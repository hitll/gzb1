#include "dlgbcode.h"
#include "ui_dlgbcode.h"

dlgBcode::dlgBcode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgBcode)
{
    ui->setupUi(this);

    flagRec=false;

    connect(ui->btnOpenSerial, SIGNAL(clicked()), this, SLOT(openSerial()));
    connect(ui->btnSettime, SIGNAL(clicked()), this, SLOT(Settime()));

    //初始化定时器1(每秒触发，要求精确）
    ptimer1 = new QTimer(this);
    ptimer1->setTimerType(Qt::PreciseTimer);
    connect(ptimer1, SIGNAL(timeout()), this, SLOT(TimerTicked()));

    ptimer1->start(1000);
}

dlgBcode::~dlgBcode()
{
    //关闭串口
    if(flagRec)
    {
        serial->clear();
        serial->close();
    }

    delete ui;
}

void dlgBcode::readData()
{
    QByteArray buf;
    QString str;
    char ch,btime[6];
    int i,cnt;

    qDebug() << "readData: " << endl;

    buf = serial->readAll();
    cnt=buf.size();
    if (!buf.isEmpty())
    {
        ch=buf.at(0);
        if(ch==0x42)
        {
            for(i=1;i<=6;i++)
            {
                ch=buf.at(i);
                btime[i-1]=ch-(ch>>4)*6;
            }
        }
        str.sprintf("%04d-%02d-%02d %02d:%02d:%02d",2000+btime[3],btime[4],btime[5],btime[0],btime[1],btime[2]);
        ui->lineEditBcodeTime->setText(str);
    }
}

void dlgBcode::TimerTicked()
{
    QDateTime curTime = QDateTime::currentDateTime();
    QString strDatetime = curTime.toString("yyyy-MM-dd HH:mm:ss");
    ui->lineEditCurTime->setText(strDatetime);
}

void dlgBcode::openSerial()
{    
    if(flagRec) //如果正在接收则停止
    {
        serial->clear();
        serial->close();
        ui->btnOpenSerial->setText("开始接收");
        flagRec=false;
    }
    else        //否则打开串口开始接收
    {
        serial = new QSerialPort;
        QString description;
        QString manufacturer;
        QString serialNumber;

        //获取可以用的串口
        QList<QSerialPortInfo> serialPortInfos = QSerialPortInfo::availablePorts();

        //输出当前系统可以使用的串口个数
        qDebug() << "Total numbers of ports: " << serialPortInfos.count();

        //将所有可以使用的串口设备添加到ComboBox中
        for (const QSerialPortInfo &serialPortInfo : serialPortInfos)
        {
            QStringList list;
            description = serialPortInfo.description();
            manufacturer = serialPortInfo.manufacturer();
            serialNumber = serialPortInfo.serialNumber();
        }

        serial->setPortName("/dev/ttyS0");          //设置串口名字
        serial->setBaudRate(QSerialPort::Baud9600); //设置波特率
        serial->setDataBits(QSerialPort::Data8);    //设置数据位
        serial->setParity(QSerialPort::NoParity);   //设置奇偶校验位
        serial->setStopBits(QSerialPort::OneStop);  //设置停止位
        serial->setFlowControl(QSerialPort::NoFlowControl); //设置流控

        //打开串口
        if (serial->open(QIODevice::ReadWrite))
        {
            ui->btnOpenSerial->setText("停止接收");
            flagRec=true;
            connect(serial, &QSerialPort::readyRead, this, &dlgBcode::readData); //信号与槽函数关联
        }
    }
}

void dlgBcode::Settime()
{
    QString cmd = "date -s '" + ui->lineEditBcodeTime->text()+"'";
    system(cmd.toStdString().data());

    //将系统时钟同步到硬件时钟
    cmd="hwclock -w";
    system(cmd.toStdString().data());
}
