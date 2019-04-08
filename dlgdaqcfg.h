#ifndef DLGDAQCFG_H
#define DLGDAQCFG_H

#include <QDialog>
#include "global_def.h"

namespace Ui {
class dlgDaqCfg;
}

class dlgDaqCfg : public QDialog
{
    Q_OBJECT

public:
    explicit dlgDaqCfg(QWidget *parent = nullptr);
    ~dlgDaqCfg();
    void getTableValue();

private:
    Ui::dlgDaqCfg *ui;

    void createRow(int rowNo, stDaqInfo *pdaqinfo);
};

#endif // DLGDAQCFG_H
