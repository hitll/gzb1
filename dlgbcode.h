#ifndef DLGBCODE_H
#define DLGBCODE_H

#include <QDialog>
#include "global_def.h"

namespace Ui {
class dlgBcode;
}

class dlgBcode : public QDialog
{
    Q_OBJECT

public:
    explicit dlgBcode(QWidget *parent = nullptr);
    ~dlgBcode();


    QTimer *ptimer1;

private:
    Ui::dlgBcode *ui;
    QSerialPort *serial;
    QDateTime curTime;

    bool flagRec;

private slots:
    void openSerial();
    void readData();
    void TimerTicked();
    void Settime();
};

#endif // DLGBCODE_H
