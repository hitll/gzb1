#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>


#include "dlgabout.h"
#include "dlgdaqcfg.h"
#include "dlgbcode.h"
#include "dlghisquery.h"
#include "global_def.h"


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QSqlDatabase db;
    QSqlQuery query;
    bool flagConnetDB;

    bool flagDaqState;
    bool flagAlarmState;
    QLabel *pLabDaqState;
    QLabel *pLabAlarmState;

    stDaqInfo daqinfo[64];
    QList<quint32> listChUsed;

    int32 rawData[64];
    double scaledData[64];

    QStringList daqAiCardList,daqDiCardList,daqDoCardList;
    InstantAiCtrl *instantAiCtrl1; //第一块PCI-1715板卡
    InstantAiCtrl *instantAiCtrl2; //第二块PCI-1715板卡
    InstantDiCtrl *instantDiCtrl;
    InstantDoCtrl *instantDoCtrl;
    quint8 portDiState[2],portDoState[2];

    ConfigureParameter configure;


    void Init();
    void connectDB();
    void setCurDaqCfg();

    void ConfigureDevice();
    void printLog(QString text, bool timeflag);

private:
    Ui::MainWindow *ui;
    QTimer *ptimer1,*ptimer2;
    QString lastBcodeSetTime;

    void setDaqCfg2DB();

private slots:
    void Timer1Ticked();
    void Timer2Ticked();
    void actAboutClicked();
    void actDaqCfgClicked();
    void actEnDaqClicked(bool checked);
    void actBcodeClicked();
    void actHisQueryClicked();
    void actInitDaqCfgClicked();
};

#endif // MAINWINDOW_H
