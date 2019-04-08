#ifndef DLGHISQUERY_H
#define DLGHISQUERY_H

#include <QDialog>
#include "global_def.h"

namespace Ui {
class dlgHisQuery;
}

class dlgHisQuery : public QDialog
{
    Q_OBJECT

public:
    explicit dlgHisQuery(QWidget *parent = nullptr);
    ~dlgHisQuery();


    QLineSeries *series;
    QChart *chart;

private:
    Ui::dlgHisQuery *ui;

private slots:
    void btnQueryClicked();
};

#endif // DLGHISQUERY_H
