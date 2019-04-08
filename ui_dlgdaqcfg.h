/********************************************************************************
** Form generated from reading UI file 'dlgdaqcfg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGDAQCFG_H
#define UI_DLGDAQCFG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_dlgDaqCfg
{
public:
    QTableWidget *table1;
    QPushButton *btnOK;
    QPushButton *btnCancel;

    void setupUi(QDialog *dlgDaqCfg)
    {
        if (dlgDaqCfg->objectName().isEmpty())
            dlgDaqCfg->setObjectName(QStringLiteral("dlgDaqCfg"));
        dlgDaqCfg->resize(1024, 581);
        table1 = new QTableWidget(dlgDaqCfg);
        if (table1->rowCount() < 64)
            table1->setRowCount(64);
        table1->setObjectName(QStringLiteral("table1"));
        table1->setGeometry(QRect(20, 10, 991, 491));
        table1->setRowCount(64);
        table1->horizontalHeader()->setVisible(true);
        table1->verticalHeader()->setVisible(false);
        btnOK = new QPushButton(dlgDaqCfg);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        btnOK->setGeometry(QRect(340, 530, 80, 26));
        btnCancel = new QPushButton(dlgDaqCfg);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(590, 530, 80, 26));

        retranslateUi(dlgDaqCfg);
        QObject::connect(btnOK, SIGNAL(clicked()), dlgDaqCfg, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), dlgDaqCfg, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgDaqCfg);
    } // setupUi

    void retranslateUi(QDialog *dlgDaqCfg)
    {
        dlgDaqCfg->setWindowTitle(QApplication::translate("dlgDaqCfg", "\346\265\213\347\202\271\344\277\241\346\201\257\351\205\215\347\275\256", Q_NULLPTR));
        btnOK->setText(QApplication::translate("dlgDaqCfg", "\347\241\256\345\256\232(&O)", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("dlgDaqCfg", "\345\217\226\346\266\210(&C)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class dlgDaqCfg: public Ui_dlgDaqCfg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGDAQCFG_H
