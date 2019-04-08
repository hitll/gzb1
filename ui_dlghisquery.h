/********************************************************************************
** Form generated from reading UI file 'dlghisquery.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGHISQUERY_H
#define UI_DLGHISQUERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_dlgHisQuery
{
public:
    QChartView *graphicsView;
    QPushButton *btnQuery;
    QDateTimeEdit *dtp1;
    QDateTimeEdit *dtp2;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_3;

    void setupUi(QDialog *dlgHisQuery)
    {
        if (dlgHisQuery->objectName().isEmpty())
            dlgHisQuery->setObjectName(QStringLiteral("dlgHisQuery"));
        dlgHisQuery->resize(943, 520);
        graphicsView = new QChartView(dlgHisQuery);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(20, 80, 901, 421));
        btnQuery = new QPushButton(dlgHisQuery);
        btnQuery->setObjectName(QStringLiteral("btnQuery"));
        btnQuery->setGeometry(QRect(840, 40, 80, 26));
        dtp1 = new QDateTimeEdit(dlgHisQuery);
        dtp1->setObjectName(QStringLiteral("dtp1"));
        dtp1->setGeometry(QRect(300, 40, 201, 27));
        dtp1->setDateTime(QDateTime(QDate(2019, 1, 1), QTime(0, 0, 0)));
        dtp2 = new QDateTimeEdit(dlgHisQuery);
        dtp2->setObjectName(QStringLiteral("dtp2"));
        dtp2->setGeometry(QRect(560, 40, 191, 27));
        dtp2->setDateTime(QDateTime(QDate(2019, 1, 1), QTime(0, 0, 0)));
        label = new QLabel(dlgHisQuery);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 20, 71, 18));
        label_2 = new QLabel(dlgHisQuery);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(560, 20, 81, 18));
        comboBox = new QComboBox(dlgHisQuery);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 40, 191, 26));
        label_3 = new QLabel(dlgHisQuery);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 20, 81, 18));

        retranslateUi(dlgHisQuery);

        QMetaObject::connectSlotsByName(dlgHisQuery);
    } // setupUi

    void retranslateUi(QDialog *dlgHisQuery)
    {
        dlgHisQuery->setWindowTitle(QApplication::translate("dlgHisQuery", "\345\216\206\345\217\262\346\225\260\346\215\256\346\237\245\350\257\242", Q_NULLPTR));
        btnQuery->setText(QApplication::translate("dlgHisQuery", "\346\237\245\350\257\242(&Q)", Q_NULLPTR));
        dtp1->setDisplayFormat(QApplication::translate("dlgHisQuery", "yyyy/MM/dd      hh:mm:ss", Q_NULLPTR));
        dtp2->setDisplayFormat(QApplication::translate("dlgHisQuery", "yyyy/MM/dd      hh:mm:ss", Q_NULLPTR));
        label->setText(QApplication::translate("dlgHisQuery", "\350\265\267\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        label_2->setText(QApplication::translate("dlgHisQuery", "\347\273\223\346\235\237\346\227\266\351\227\264", Q_NULLPTR));
        label_3->setText(QApplication::translate("dlgHisQuery", "\346\265\213\347\202\271\345\220\215\347\247\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class dlgHisQuery: public Ui_dlgHisQuery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGHISQUERY_H
