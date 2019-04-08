/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actDaqCfg;
    QAction *actEnDaq;
    QAction *actHisQuery;
    QAction *actAbout;
    QAction *actBcode;
    QAction *actComCfg;
    QAction *actGlobalCfg;
    QAction *actHisManage;
    QAction *actInitDaqCfg;
    QWidget *centralWidget;
    QTextEdit *txtLog;
    QLabel *labelPic;
    QTableWidget *table1;
    QLabel *labelName1;
    QLabel *labelValue1;
    QTableWidget *table2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1714, 918);
        actDaqCfg = new QAction(MainWindow);
        actDaqCfg->setObjectName(QStringLiteral("actDaqCfg"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/images/images/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        actDaqCfg->setIcon(icon);
        actEnDaq = new QAction(MainWindow);
        actEnDaq->setObjectName(QStringLiteral("actEnDaq"));
        actEnDaq->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/images/images/recording.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actEnDaq->setIcon(icon1);
        actHisQuery = new QAction(MainWindow);
        actHisQuery->setObjectName(QStringLiteral("actHisQuery"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/images/images/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        actHisQuery->setIcon(icon2);
        actAbout = new QAction(MainWindow);
        actAbout->setObjectName(QStringLiteral("actAbout"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/images/images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actAbout->setIcon(icon3);
        actBcode = new QAction(MainWindow);
        actBcode->setObjectName(QStringLiteral("actBcode"));
        actComCfg = new QAction(MainWindow);
        actComCfg->setObjectName(QStringLiteral("actComCfg"));
        actGlobalCfg = new QAction(MainWindow);
        actGlobalCfg->setObjectName(QStringLiteral("actGlobalCfg"));
        actHisManage = new QAction(MainWindow);
        actHisManage->setObjectName(QStringLiteral("actHisManage"));
        actInitDaqCfg = new QAction(MainWindow);
        actInitDaqCfg->setObjectName(QStringLiteral("actInitDaqCfg"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        txtLog = new QTextEdit(centralWidget);
        txtLog->setObjectName(QStringLiteral("txtLog"));
        txtLog->setGeometry(QRect(1140, 510, 561, 301));
        labelPic = new QLabel(centralWidget);
        labelPic->setObjectName(QStringLiteral("labelPic"));
        labelPic->setGeometry(QRect(410, 10, 711, 801));
        table1 = new QTableWidget(centralWidget);
        table1->setObjectName(QStringLiteral("table1"));
        table1->setGeometry(QRect(10, 10, 371, 801));
        table1->setRowCount(0);
        table1->verticalHeader()->setVisible(false);
        labelName1 = new QLabel(centralWidget);
        labelName1->setObjectName(QStringLiteral("labelName1"));
        labelName1->setGeometry(QRect(460, 630, 141, 20));
        labelName1->setAlignment(Qt::AlignCenter);
        labelValue1 = new QLabel(centralWidget);
        labelValue1->setObjectName(QStringLiteral("labelValue1"));
        labelValue1->setGeometry(QRect(510, 650, 54, 18));
        table2 = new QTableWidget(centralWidget);
        table2->setObjectName(QStringLiteral("table2"));
        table2->setGeometry(QRect(1140, 10, 561, 481));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1714, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuFile->addAction(actDaqCfg);
        menuFile->addSeparator();
        menuFile->addAction(actBcode);
        menuFile->addSeparator();
        menuFile->addAction(actComCfg);
        menuFile->addSeparator();
        menuFile->addAction(actGlobalCfg);
        menuFile->addSeparator();
        menuFile->addAction(actInitDaqCfg);
        menu->addAction(actEnDaq);
        menu_2->addAction(actHisQuery);
        menu_2->addSeparator();
        menu_2->addAction(actHisManage);
        menu_4->addAction(actAbout);
        mainToolBar->addAction(actDaqCfg);
        mainToolBar->addAction(actEnDaq);
        mainToolBar->addAction(actHisQuery);
        mainToolBar->addAction(actAbout);

        retranslateUi(MainWindow);
        QObject::connect(actAbout, SIGNAL(triggered()), MainWindow, SLOT(repaint()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actDaqCfg->setText(QApplication::translate("MainWindow", "\346\265\213\347\202\271\351\205\215\347\275\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actDaqCfg->setToolTip(QApplication::translate("MainWindow", "\351\205\215\347\275\256\346\265\213\347\202\271\344\277\241\346\201\257...", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actEnDaq->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250\351\207\207\351\233\206", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actEnDaq->setToolTip(QApplication::translate("MainWindow", "\345\274\200\345\247\213\351\207\207\351\233\206\346\225\260\346\215\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actHisQuery->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\237\245\350\257\242", Q_NULLPTR));
        actAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
        actBcode->setText(QApplication::translate("MainWindow", "B\347\240\201\345\257\271\346\227\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actBcode->setToolTip(QApplication::translate("MainWindow", "B\347\240\201\345\257\271\346\227\266\351\205\215\347\275\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actComCfg->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\351\205\215\347\275\256", Q_NULLPTR));
        actGlobalCfg->setText(QApplication::translate("MainWindow", "\351\200\232\347\224\250\351\205\215\347\275\256", Q_NULLPTR));
        actHisManage->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\347\256\241\347\220\206", Q_NULLPTR));
        actInitDaqCfg->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\346\265\213\347\202\271\344\277\241\346\201\257", Q_NULLPTR));
        labelPic->setText(QApplication::translate("MainWindow", "log", Q_NULLPTR));
        labelName1->setText(QApplication::translate("MainWindow", "\345\206\267\345\215\264\346\260\264\346\270\251\345\272\246", Q_NULLPTR));
        labelValue1->setText(QApplication::translate("MainWindow", "23.5\342\204\203", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "\347\263\273\347\273\237\351\205\215\347\275\256(&S)", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256\351\207\207\351\233\206(&A)", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\216\206\345\217\262\350\256\260\345\275\225(&R)", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\210\206\346\236\220(&D)", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
