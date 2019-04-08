#include "dlghisquery.h"
#include "ui_dlghisquery.h"
#include "mainwindow.h"

dlgHisQuery::dlgHisQuery(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgHisQuery)
{
    ui->setupUi(this);

    connect(ui->btnQuery, SIGNAL(clicked()), this, SLOT(btnQueryClicked()));
}

dlgHisQuery::~dlgHisQuery()
{
    delete ui;
}

void dlgHisQuery::btnQueryClicked()
{
    quint32 t,i;
    float tt;
    float v;

    MainWindow *pwnd = (MainWindow *)parentWidget();

    series = new QLineSeries();
    series->setName("channel 1");
    pwnd->query.exec("select * from hisdata where channel=0");
    i=0;
    while(pwnd->query.next())
    {
        tt = pwnd->query.value(0).toFloat();
        v = pwnd->query.value(2).toFloat();
        series->append(i,v);
        i++;
    }

    chart = new QChart();

    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();

    chart->axisY()->setRange(0,100);

    //QValueAxis *axisX = new Q


    ui->graphicsView->setChart(chart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    ui->graphicsView->show();

}
