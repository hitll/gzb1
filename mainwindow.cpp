#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化定时器1(每秒触发，要求精确）
    ptimer1 = new QTimer(this);
    ptimer1->setTimerType(Qt::PreciseTimer);
    connect(ptimer1, SIGNAL(timeout()), this, SLOT(Timer1Ticked()));

    //初始化定时器2(周期触发，进行B码校时）
    ptimer2 = new QTimer(this);
    ptimer2->setTimerType(Qt::VeryCoarseTimer);
    connect(ptimer2, SIGNAL(timeout()), this, SLOT(Timer2Ticked()));

    connect(ui->actAbout, SIGNAL(triggered()), this, SLOT(actAboutClicked()));
    connect(ui->actDaqCfg, SIGNAL(triggered()), this, SLOT(actDaqCfgClicked()));
    connect(ui->actEnDaq, SIGNAL(triggered(bool)), this, SLOT(actEnDaqClicked(bool)));
    connect(ui->actBcode, SIGNAL(triggered()), this, SLOT(actBcodeClicked()));
    connect(ui->actHisQuery, SIGNAL(triggered()), this, SLOT(actHisQueryClicked()));
    connect(ui->actInitDaqCfg, SIGNAL(triggered()), this, SLOT(actInitDaqCfgClicked()));
}

MainWindow::~MainWindow()
{
    db.close(); //关闭数据库连接    

    if (instantAiCtrl1 != NULL)
    {
        instantAiCtrl1->Dispose();
    }

    if (instantAiCtrl2 != NULL)
    {
        instantAiCtrl2->Dispose();
    }

    if (instantDiCtrl != NULL)
    {
        instantDiCtrl->Dispose();
    }

    if (instantDoCtrl != NULL)
    {
        instantDoCtrl->Dispose();
    }

    delete ui;
}

/*** 初始化函数 ***/
void MainWindow::Init()
{
    int i=0;

    for(i=0;i<64;i++)
    {
        rawData[i]=0;
        scaledData[i]=0;
    }

    setWindowTitle(tr("葛洲坝全息监测项目水轮机组数据采集软件v1.0 beta"));
    //setWindowState(Qt::WindowMaximized);
    printLog(tr("数据采集软件启动..."), 1);

    pLabDaqState=new QLabel;
    pLabDaqState->setMinimumWidth(150);
    pLabDaqState->setText("|未采集|");
    ui->statusBar->addWidget(pLabDaqState);

    pLabAlarmState=new QLabel;
    pLabAlarmState->setMinimumWidth(150);
    pLabAlarmState->setText("|运行正常|");
    ui->statusBar->addWidget(pLabAlarmState);

    //ui->labelPic->setPixmap(QPixmap("://new//images//machine.png"));
    QPixmap pixmap("/home/hit/gzb1/images/machine2.png");
    ui->labelPic->setPixmap(pixmap);
    ui->labelPic->show();

    QTableWidgetItem *headerItem;
    QStringList headerText1,headerText2;
    headerText1<<"序号"<<"通道"<<"测点名称"<<"实时值";
    ui->table1->setColumnCount(headerText1.count());
    for(i=0;i<headerText1.count();i++)
    {
        headerItem=new QTableWidgetItem(headerText1.at(i));
        ui->table1->setHorizontalHeaderItem(i,headerItem);
    }
    ui->table1->setColumnWidth(0,50);
    ui->table1->setColumnWidth(1,50);
    ui->table1->setColumnWidth(2,170);
    ui->table1->setColumnWidth(3,95);

    headerText2<<"日期"<<"时间"<<"测点名称"<<"报警值"<<"报警信息";
    ui->table2->setColumnCount(headerText2.count());
    for(i=0;i<headerText2.count();i++)
    {
        headerItem=new QTableWidgetItem(headerText2.at(i));
        ui->table2->setHorizontalHeaderItem(i,headerItem);
    }
    ui->table2->setColumnWidth(0,80);
    ui->table2->setColumnWidth(1,80);
    ui->table2->setColumnWidth(2,160);
    ui->table2->setColumnWidth(3,80);
    ui->table2->setColumnWidth(4,155);

    connectDB();

    i=0;
    query.exec("select * from daqcfg");
    while(query.next())
    {
        daqinfo[i].channel = query.value(0).toUInt();
        daqinfo[i].used = query.value(1).toUInt();
        daqinfo[i].name = query.value(2).toString();
        daqinfo[i].unit = query.value(3).toString();
        daqinfo[i].type = query.value(4).toUInt();
        daqinfo[i].scopemin = query.value(5).toFloat();
        daqinfo[i].scopemax = query.value(6).toFloat();
        daqinfo[i].freq = query.value(7).toUInt();
        daqinfo[i].alarm_h =query.value(8).toUInt();
        daqinfo[i].limit_h =query.value(9).toFloat();
        daqinfo[i].alarm_l =query.value(10).toUInt();
        daqinfo[i].limit_l =query.value(11).toFloat();
        daqinfo[i].remark = query.value(12).toString();
        i++;
    }

    setCurDaqCfg();

    ConfigureDevice();
}


void MainWindow::ConfigureDevice()
{
    int i;

    instantAiCtrl1 = InstantAiCtrl::Create();
    instantAiCtrl2 = InstantAiCtrl::Create();
    instantDiCtrl = InstantDiCtrl::Create();
    instantDoCtrl = InstantDoCtrl::Create();

    Array<DeviceTreeNode>* supportedAiDevices = instantAiCtrl1->getSupportedDevices();

    if (supportedAiDevices->getCount() == 0)
    {
        QMessageBox::information(this, tr("警告"), tr("未找到研华PCI模拟量输入板卡！"));
        //QCoreApplication::quit();
        return;
    }
    else
    {
        for (i = 0; i < supportedAiDevices->getCount(); i++)
        {
            DeviceTreeNode const &node = supportedAiDevices->getItem(i);
            qDebug("%d, %ls\n", node.DeviceNumber, node.Description);
            daqAiCardList.append(QString::fromWCharArray(node.Description));
        }
    }

    supportedAiDevices->Dispose();

    std::wstring description = daqAiCardList.at(0).toStdWString();
    DeviceInformation selectedAi1(description.c_str());
    ErrorCode errorCode = instantAiCtrl1->setSelectedDevice(selectedAi1);
    if (errorCode >= 0xE0000000 && errorCode != Success)
    {
        QString message = tr("AI1板卡出现错误, 错误码: 0x") + QString::number(errorCode, 16).right(8).toUpper();
        QMessageBox::information(this, "警告", message);
        return;
    }

    //Get channel max number. set value range for every channel.
    Array<AiChannel> *channels = instantAiCtrl1->getChannels();
    ValueRange valueRange=V_0To5;//V_Neg10To10;
    for (i = 0; i < channels->getCount(); i++)
    {
        channels->getItem(i).setValueRange(valueRange);
    }

    description = daqAiCardList.at(1).toStdWString();
    DeviceInformation selectedAi2(description.c_str());
    errorCode = instantAiCtrl2->setSelectedDevice(selectedAi2);
    if (errorCode >= 0xE0000000 && errorCode != Success)
    {
        QString message = tr("AI2板卡出现错误, 错误码: 0x") + QString::number(errorCode, 16).right(8).toUpper();
        QMessageBox::information(this, "警告", message);
        return;
    }

    //Get channel max number. set value range for every channel.
    channels = instantAiCtrl2->getChannels();
    for (i = 0; i < channels->getCount(); i++)
    {
        channels->getItem(i).setValueRange(valueRange);
    }

    printLog(tr("初始化PCI-AI板卡成功！"), 1);

    Array<DeviceTreeNode>*supportedDiDevices = instantDiCtrl->getSupportedDevices();
    if (supportedDiDevices->getCount() == 0)
    {
        QMessageBox::information(this, tr("警告"), tr("未找到研华PCI开关量输入板卡！"));
        //QCoreApplication::quit();
        return;
    }
    else
    {
        for (i = 0; i < supportedDiDevices->getCount(); i++)
        {
            DeviceTreeNode const &node = supportedDiDevices->getItem(i);
            qDebug("%d, %ls\n", node.DeviceNumber, node.Description);
            daqDiCardList.append(QString::fromWCharArray(node.Description));
        }
    }

    description = daqDiCardList.at(0).toStdWString();
    DeviceInformation selectedDi(description.c_str());
    errorCode = instantDiCtrl->setSelectedDevice(selectedDi);
    if (errorCode >= 0xE0000000 && errorCode != Success)
    {
        QString message = tr("DI板卡出现错误, 错误码: 0x") + QString::number(errorCode, 16).right(8).toUpper();
        QMessageBox::information(this, "警告", message);
        return;
    }

    Array<DeviceTreeNode> *supportedDoDevices = instantDoCtrl->getSupportedDevices();
    if (supportedDoDevices->getCount() == 0)
    {
        QMessageBox::information(this, tr("警告"), tr("未找到研华PCI开关量输出板卡！"));
        //QCoreApplication::quit();
        return;
    }
    else
    {
        for (i = 0; i < supportedDiDevices->getCount(); i++)
        {
            DeviceTreeNode const &node = supportedDoDevices->getItem(i);
            qDebug("%d, %ls\n", node.DeviceNumber, node.Description);
            daqDoCardList.append(QString::fromWCharArray(node.Description));
        }
    }

    description = daqDoCardList.at(0).toStdWString();
    DeviceInformation selectedDo(description.c_str());
    errorCode = instantDoCtrl->setSelectedDevice(selectedDo);
    if (errorCode >= 0xE0000000 && errorCode != Success)
    {
        QString message = tr("DO板卡出现错误, 错误码: 0x") + QString::number(errorCode, 16).right(8).toUpper();
        QMessageBox::information(this, "警告", message);
        return;
    }

    printLog(tr("初始化PCI-DI/DO板卡成功！"), 1);
}


void MainWindow::printLog(QString text, bool timeflag)
{
    if(timeflag)
    {
        QDateTime curTime = QDateTime::currentDateTime();
        QString strDate = curTime.time().toString();
        ui->txtLog->append(strDate + "\t " + text);
    }
    else
    {
        ui->txtLog->append(text);
    }
}

/*** 定时器1触发 ***/
void MainWindow::Timer1Ticked()
{
    int i,ch;
    QTableWidgetItem *item;
    QString str;

    QDateTime curTime = QDateTime::currentDateTime();
    quint32 tt = curTime.toTime_t();
    //QDateTime dt = QDateTime::fromTime_t (1);
    QString strDate = curTime.toString(Qt::SystemLocaleLongDate);//日期格式自定义

    ErrorCode errorCode = Success;
    errorCode = instantDiCtrl->Read(0, 2, portDiState);
    errorCode = instantDoCtrl->Read(0, 2, portDoState);
    errorCode = instantDoCtrl->Write(0, 2, portDoState);

    errorCode = instantAiCtrl1->Read(configure.channelStart, configure.channelCount, rawData,scaledData);
    errorCode = instantAiCtrl2->Read(configure.channelStart, configure.channelCount, rawData+32,scaledData+32);

    if (errorCode != Success)
    {
        return;
    }

    for(i=0;i<listChUsed.size();i++)
    {
        ch=listChUsed.at(i);
        daqinfo[ch].value=rawData[ch];
        daqinfo[ch].fvalue=daqinfo[ch].scopemin+((daqinfo[ch].scopemax - daqinfo[ch].scopemin)*(scaledData[ch]/(float)5));

        str.sprintf("%.2f %s",daqinfo[ch].fvalue,daqinfo[ch].unit.toStdString().c_str());
        item=new QTableWidgetItem(str,3);
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->table1->setItem(i,3,item);

        str.sprintf("insert into hisdata values(%d,%d,%f)",tt,ch,daqinfo[ch].fvalue);
        query.exec(str);
    }

    //update image tip
    str.sprintf("%.2f %s",daqinfo[0].fvalue,daqinfo[0].unit.toStdString().c_str());
    ui->labelValue1->setText(str);

    flagAlarmState=false;
    for(i=0;i<64;i++)
    {
        if(false==daqinfo[i].used)
        {
            continue;
        }

        if(daqinfo[i].alarm_h)
        {
            if(daqinfo[i].fvalue>=daqinfo[i].limit_h)
            {
                flagAlarmState=true;
            }
        }

        if(daqinfo[i].alarm_l)
        {
            if(daqinfo[i].fvalue<=daqinfo[i].limit_l)
            {
                flagAlarmState=true;
            }
        }
    }

    if(flagAlarmState)
    {
        pLabAlarmState->setText("|有报警!!!|");
    }
    else
    {
        pLabAlarmState->setText("|运行正常|");
    }
}

/*****定时器2触发*****/
void MainWindow::Timer2Ticked()
{
    ;
}

/*** 连接数据库 ***/
void MainWindow::connectDB()
{
    //连接MariaDB数据库
    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("hit");
    db.setPassword("hit");
    db.setDatabaseName("gzb");
    db.setPort(3306);

    if(false==db.open())
    {
        QMessageBox::warning(NULL, "Warning", "Can not open Mariadb Database!");
        return;
    }
    else
    {
        flagConnetDB=true;
        query=QSqlQuery(db);
        printLog("连接数据库成功！", 1);
    }
}

void MainWindow::actAboutClicked()
{

    dlgAbout *pdlgAbout = new dlgAbout(this);
    Qt::WindowFlags flags=pdlgAbout->windowFlags();
    pdlgAbout->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);
    int ret=pdlgAbout->exec();
    if(ret==QDialog::Accepted)
    {
        delete pdlgAbout;
    }    
}

void MainWindow::actDaqCfgClicked()
{
    dlgDaqCfg *pdlgDaqCfg = new dlgDaqCfg(this);
    Qt::WindowFlags flags=pdlgDaqCfg->windowFlags();
    pdlgDaqCfg->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);
    int ret=pdlgDaqCfg->exec();
    if(ret==QDialog::Accepted)
    {
        pdlgDaqCfg->getTableValue();
        setDaqCfg2DB();
        setCurDaqCfg();
    }

    delete pdlgDaqCfg;
}


/*** Refresh left table on main interface ***/
void MainWindow::setCurDaqCfg()
{
    QTableWidgetItem *item;
    QString str;
    int i,j;

    ui->labelName1->setText(daqinfo[0].name);

    ui->table1->clearContents();
    for(i=ui->table1->rowCount()-1;i>=0;i--)
    {
        ui->table1->removeRow(i);
    }
    listChUsed.clear();

    j=0;
    for(i=0;i<64;i++)
    {
        if(daqinfo[i].used)
        {
            listChUsed.append(i);
            ui->table1->insertRow(j);

            //column 0
            str.sprintf("%d",j+1);
            item=new QTableWidgetItem(str,0);
            item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            item->setData(Qt::UserRole,j);
            ui->table1->setItem(j, 0,item);

            //column 1
            str.sprintf("%d",daqinfo[i].channel);
            item=new QTableWidgetItem(str,1);
            item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->table1->setItem(j,1,item);

            //column 2
            item=new QTableWidgetItem(daqinfo[i].name,2);
            item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->table1->setItem(j,2,item);

            j++;
        }
    }
}

/*** Write config info to database ***/
void MainWindow::setDaqCfg2DB()
{
    QString str;
    for(int i=0;i<64;i++)
    {
        str.sprintf("update daqcfg set used=%d,name='%s',unit='%s',type=%d,scopemin=%f,scopemax=%f, \
                    freq=%d,alarm_h=%d,limit_h=%f,alarm_l=%d,limit_l=%f,remark='%s' where channel=%d", \
                    daqinfo[i].used,daqinfo[i].name.toStdString().c_str(),daqinfo[i].unit.toStdString().c_str(),daqinfo[i].type,daqinfo[i].scopemin, \
                    daqinfo[i].scopemax,daqinfo[i].freq,daqinfo[i].alarm_h,daqinfo[i].limit_h,daqinfo[i].alarm_l, \
                    daqinfo[i].limit_l,daqinfo[i].remark.toStdString().c_str(), i+1);
        query.exec(str);
    }
}

void MainWindow::actEnDaqClicked(bool checked)
{
    flagDaqState=checked;
    if(checked)
    {
        ptimer1->start(1000);
        pLabDaqState->setText("|采集中...|");
    }
    else
    {
        ptimer1->stop();
        pLabDaqState->setText("|未采集|");
    }
}

void MainWindow::actBcodeClicked()
{
    dlgBcode *pdlgBcode = new dlgBcode(this);
    Qt::WindowFlags flags=pdlgBcode->windowFlags();
    pdlgBcode->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);
    int ret=pdlgBcode->exec();
    if(ret==QDialog::Accepted)
    {
        delete pdlgBcode;
    }
}
void MainWindow::actHisQueryClicked()
{
    dlgHisQuery *pdlgHisQuery = new dlgHisQuery(this);
    Qt::WindowFlags flags=pdlgHisQuery->windowFlags();
    pdlgHisQuery->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);
    int ret=pdlgHisQuery->exec();
    if(ret==QDialog::Accepted)
    {
        delete pdlgHisQuery;
    }
}

void MainWindow::actInitDaqCfgClicked()
{
    QString str;

    query.exec("create table hisdata(ts int unsigned,channel int unsigned,value float)");
    query.exec("create table daqcfg(channel int unsigned, used int unsigned, name varchar(60), unit varchar(20), type int unsigned, scopemin float, scopemax float, freq int unsigned, alarm_h int unsigned, limit_h float, alarm_l int unsigned, limit_l float, remark varchar(100),primary key(channel))");
    //query.exec("delete from daqcfg");
    for(int i=1;i<65;i++)
    {
        str.sprintf("insert into daqcfg(channel,used,scopemax) values(%d,0,100)",i);
        query.exec(str);
    }
}
