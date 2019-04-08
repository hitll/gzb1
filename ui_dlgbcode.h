/********************************************************************************
** Form generated from reading UI file 'dlgbcode.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGBCODE_H
#define UI_DLGBCODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dlgBcode
{
public:
    QLineEdit *lineEditBcodeTime;
    QPushButton *btnSettime;
    QLabel *label;
    QCheckBox *checkEnAutoSet;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEditCurTime;
    QLineEdit *lineEditInterval;
    QPushButton *btnOpenSerial;

    void setupUi(QDialog *dlgBcode)
    {
        if (dlgBcode->objectName().isEmpty())
            dlgBcode->setObjectName(QStringLiteral("dlgBcode"));
        dlgBcode->resize(401, 221);
        lineEditBcodeTime = new QLineEdit(dlgBcode);
        lineEditBcodeTime->setObjectName(QStringLiteral("lineEditBcodeTime"));
        lineEditBcodeTime->setGeometry(QRect(20, 110, 221, 26));
        btnSettime = new QPushButton(dlgBcode);
        btnSettime->setObjectName(QStringLiteral("btnSettime"));
        btnSettime->setGeometry(QRect(270, 110, 91, 26));
        label = new QLabel(dlgBcode);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 160, 20, 21));
        checkEnAutoSet = new QCheckBox(dlgBcode);
        checkEnAutoSet->setObjectName(QStringLiteral("checkEnAutoSet"));
        checkEnAutoSet->setGeometry(QRect(250, 160, 131, 24));
        label_2 = new QLabel(dlgBcode);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 160, 101, 21));
        label_3 = new QLabel(dlgBcode);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 80, 101, 21));
        label_4 = new QLabel(dlgBcode);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 10, 101, 21));
        lineEditCurTime = new QLineEdit(dlgBcode);
        lineEditCurTime->setObjectName(QStringLiteral("lineEditCurTime"));
        lineEditCurTime->setGeometry(QRect(20, 40, 221, 26));
        lineEditInterval = new QLineEdit(dlgBcode);
        lineEditInterval->setObjectName(QStringLiteral("lineEditInterval"));
        lineEditInterval->setGeometry(QRect(120, 160, 81, 26));
        btnOpenSerial = new QPushButton(dlgBcode);
        btnOpenSerial->setObjectName(QStringLiteral("btnOpenSerial"));
        btnOpenSerial->setGeometry(QRect(270, 80, 91, 26));

        retranslateUi(dlgBcode);

        QMetaObject::connectSlotsByName(dlgBcode);
    } // setupUi

    void retranslateUi(QDialog *dlgBcode)
    {
        dlgBcode->setWindowTitle(QApplication::translate("dlgBcode", "IRIG-B\347\240\201(DC)\345\257\271\346\227\266", Q_NULLPTR));
        btnSettime->setText(QApplication::translate("dlgBcode", "\346\211\213\345\212\250\346\240\241\346\227\266", Q_NULLPTR));
        label->setText(QApplication::translate("dlgBcode", "s", Q_NULLPTR));
        checkEnAutoSet->setText(QApplication::translate("dlgBcode", "\344\275\277\350\203\275\350\207\252\345\212\250\346\240\241\346\227\266", Q_NULLPTR));
        label_2->setText(QApplication::translate("dlgBcode", "\350\207\252\345\212\250\346\240\241\346\227\266\345\221\250\346\234\237", Q_NULLPTR));
        label_3->setText(QApplication::translate("dlgBcode", "IRIG-B\347\240\201\346\227\266\351\227\264", Q_NULLPTR));
        label_4->setText(QApplication::translate("dlgBcode", "\345\275\223\345\211\215\347\263\273\347\273\237\346\227\266\351\227\264", Q_NULLPTR));
        btnOpenSerial->setText(QApplication::translate("dlgBcode", "\345\274\200\345\247\213\346\216\245\346\224\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class dlgBcode: public Ui_dlgBcode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGBCODE_H
