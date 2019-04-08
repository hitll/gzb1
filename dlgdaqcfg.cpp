#include "dlgdaqcfg.h"
#include "ui_dlgdaqcfg.h"
#include "mainwindow.h"

dlgDaqCfg::dlgDaqCfg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgDaqCfg)
{
    ui->setupUi(this);

    QTableWidgetItem *headerItem;
    QStringList headerText;
    headerText<<"通道"<<"是否使用"<<"测点名称"<<"单位"<<"类型"<<"量程下限"<<"量程上限"<<"采集频率"<<"启用高报警"<<"高报警值"<<"启用低报警"<<"低报警值"<<"备注";
    ui->table1->setColumnCount(headerText.count());
    for(int i=0;i<headerText.count();i++)
    {
        headerItem=new QTableWidgetItem(headerText.at(i));
        ui->table1->setHorizontalHeaderItem(i,headerItem);
    }
    ui->table1->setAlternatingRowColors(true);

    ui->table1->clearContents();

    MainWindow *pWnd = (MainWindow *)parentWidget();
    for(int i=0;i<64;i++)
    {
        createRow(i,pWnd->daqinfo+i);
    }
    ui->table1->resizeColumnsToContents();
}

dlgDaqCfg::~dlgDaqCfg()
{
    delete ui;
}


void dlgDaqCfg::createRow(int rowNo, stDaqInfo *pdaqinfo)
{
    QTableWidgetItem *item;
    QString str;

    //column 0
    str.sprintf("%d",pdaqinfo->channel);
    item=new QTableWidgetItem(str,0);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    item->setData(Qt::UserRole,pdaqinfo->channel);
    ui->table1->setItem(rowNo, 0,item);

    //column 1
    item=new QTableWidgetItem("使用",1);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    if(pdaqinfo->used)
        item->setCheckState(Qt::Checked);
    else
        item->setCheckState(Qt::Unchecked);
    ui->table1->setItem(rowNo,1,item);

    //column 2
    item=new QTableWidgetItem(pdaqinfo->name,2);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->table1->setItem(rowNo,2,item);

    //column 3
    item=new QTableWidgetItem(pdaqinfo->unit,3);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->table1->setItem(rowNo,3,item);

    //column 4
    str.sprintf("%d",pdaqinfo->type);
    item=new QTableWidgetItem(str,4);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->table1->setItem(rowNo, 4,item);

    //column 5
    str.sprintf("%.1f",pdaqinfo->scopemin);
    item=new QTableWidgetItem(str,5);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->table1->setItem(rowNo, 5,item);

    //column 6
    str.sprintf("%.1f",pdaqinfo->scopemax);
    item=new QTableWidgetItem(str,6);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->table1->setItem(rowNo, 6,item);

    //column 7
    str.sprintf("%d",pdaqinfo->freq);
    item=new QTableWidgetItem(str,7);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->table1->setItem(rowNo, 7,item);

    //column 8
    item=new QTableWidgetItem("启用高报警",8);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    if(pdaqinfo->alarm_h)
        item->setCheckState(Qt::Checked);
    else
        item->setCheckState(Qt::Unchecked);
    ui->table1->setItem(rowNo, 8,item);

    //column 9
    str.sprintf("%.1f",pdaqinfo->limit_h);
    item=new QTableWidgetItem(str,9);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->table1->setItem(rowNo, 9,item);

    //column 10
    item=new QTableWidgetItem("启用低报警",10);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    if(pdaqinfo->alarm_l)
        item->setCheckState(Qt::Checked);
    else
        item->setCheckState(Qt::Unchecked);
    ui->table1->setItem(rowNo, 10,item);

    //column 11
    str.sprintf("%.1f",pdaqinfo->limit_l);
    item=new QTableWidgetItem(str,11);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->table1->setItem(rowNo, 11,item);

    //column 12
    item=new QTableWidgetItem(pdaqinfo->remark,12);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->table1->setItem(rowNo,12,item);

}

void dlgDaqCfg::getTableValue()
{
    QString str;
    QTableWidgetItem *item;
    MainWindow *pWnd = (MainWindow *)parentWidget();

    for(int i=0;i<64;i++)
    {
        item=ui->table1->item(i,0);
        pWnd->daqinfo[i].channel=item->text().toUInt();
        item=ui->table1->item(i,1);
        pWnd->daqinfo[i].used=item->checkState();
        item=ui->table1->item(i,2);
        pWnd->daqinfo[i].name=item->text();
        item=ui->table1->item(i,3);
        pWnd->daqinfo[i].unit=item->text();
        item=ui->table1->item(i,4);
        pWnd->daqinfo[i].type=item->text().toUInt();
        item=ui->table1->item(i,5);
        pWnd->daqinfo[i].scopemin=item->text().toFloat();
        item=ui->table1->item(i,6);
        pWnd->daqinfo[i].scopemax=item->text().toFloat();
        item=ui->table1->item(i,7);
        pWnd->daqinfo[i].freq=item->text().toUInt();
        item=ui->table1->item(i,8);
        pWnd->daqinfo[i].alarm_h=item->checkState();
        item=ui->table1->item(i,9);
        pWnd->daqinfo[i].limit_h=item->text().toFloat();
        item=ui->table1->item(i,10);
        pWnd->daqinfo[i].alarm_l=item->checkState();
        item=ui->table1->item(i,11);
        pWnd->daqinfo[i].limit_l=item->text().toFloat();
        item=ui->table1->item(i,12);
        pWnd->daqinfo[i].remark=item->text();
    }
}
