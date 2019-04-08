/********************************************************************************
** Form generated from reading UI file 'dlgabout.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGABOUT_H
#define UI_DLGABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dlgAbout
{
public:
    QPushButton *btnOK;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *dlgAbout)
    {
        if (dlgAbout->objectName().isEmpty())
            dlgAbout->setObjectName(QStringLiteral("dlgAbout"));
        dlgAbout->resize(400, 123);
        btnOK = new QPushButton(dlgAbout);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        btnOK->setGeometry(QRect(280, 80, 80, 26));
        label = new QLabel(dlgAbout);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 10, 241, 31));
        label_2 = new QLabel(dlgAbout);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 50, 241, 21));

        retranslateUi(dlgAbout);
        QObject::connect(btnOK, SIGNAL(clicked()), dlgAbout, SLOT(accept()));

        QMetaObject::connectSlotsByName(dlgAbout);
    } // setupUi

    void retranslateUi(QDialog *dlgAbout)
    {
        dlgAbout->setWindowTitle(QApplication::translate("dlgAbout", "\345\205\263\344\272\216", Q_NULLPTR));
        btnOK->setText(QApplication::translate("dlgAbout", "\347\241\256\345\256\232(&O)", Q_NULLPTR));
        label->setText(QApplication::translate("dlgAbout", "\345\205\250\346\201\257\347\233\221\346\265\213\346\225\260\346\215\256\351\207\207\351\233\206\350\275\257\344\273\266 v1.0 beta", Q_NULLPTR));
        label_2->setText(QApplication::translate("dlgAbout", "\347\211\210\346\235\203\346\211\200\346\234\211\357\274\232\345\223\210\345\260\224\346\273\250\347\224\265\346\234\272\345\216\202   2019", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class dlgAbout: public Ui_dlgAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGABOUT_H
