/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "circuitviewer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAND;
    QAction *actionINPUT;
    QAction *actionOUTPUT;
    QAction *actionOR;
    QAction *actionNOR;
    QAction *actionNOT;
    QAction *actionXOR;
    QAction *actionNAND;
    QAction *actionLoadImage;
    QAction *actionShowImage;
    QAction *actionPOINT;
    QAction *actionLINE;
    QAction *actionSAVE;
    QAction *actionPLAY;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    CircuitViewer *cv;
    QMenuBar *menuBar;
    QToolBar *gatesToolbar;
    QStatusBar *statusBar;
    QToolBar *pointerToolbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");

        MainWindow->resize(938, 598);

        actionAND = new QAction(MainWindow);
        actionAND->setObjectName("actionAND");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/AND"), QSize(), QIcon::Normal, QIcon::Off);
        actionAND->setIcon(icon);

        actionINPUT = new QAction(MainWindow);
        actionINPUT->setObjectName("actionINPUT");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/INPUT"), QSize(), QIcon::Normal, QIcon::Off);
        actionINPUT->setIcon(icon1);

        actionOUTPUT = new QAction(MainWindow);
        actionOUTPUT->setObjectName("actionOUTPUT");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/OUTPUT"), QSize(), QIcon::Normal, QIcon::Off);
        actionOUTPUT->setIcon(icon2);

        actionOR = new QAction(MainWindow);
        actionOR->setObjectName("actionOR");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/OR"), QSize(), QIcon::Normal, QIcon::Off);
        actionOR->setIcon(icon3);

        actionNOR = new QAction(MainWindow);
        actionNOR->setObjectName("actionNOR");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/NOR"), QSize(), QIcon::Normal, QIcon::Off);
        actionNOR->setIcon(icon4);

        actionNOT = new QAction(MainWindow);
        actionNOT->setObjectName("actionNOT");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/NOT"), QSize(), QIcon::Normal, QIcon::Off);
        actionNOT->setIcon(icon5);

        actionXOR = new QAction(MainWindow);
        actionXOR->setObjectName("actionXOR");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/XOR"), QSize(), QIcon::Normal, QIcon::Off);
        actionXOR->setIcon(icon6);

        actionNAND = new QAction(MainWindow);
        actionNAND->setObjectName("actionNAND");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/NAND"), QSize(), QIcon::Normal, QIcon::Off);
        actionNAND->setIcon(icon7);

        actionLoadImage = new QAction(MainWindow);
        actionLoadImage->setObjectName("actionLOADIMAGE");
        QIcon iconLoadImage;
        iconLoadImage.addFile(QString::fromUtf8(":/LOADIMAGE"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoadImage->setIcon(iconLoadImage);

        actionShowImage = new QAction(MainWindow);
        actionShowImage->setObjectName("actionSHOWIMAGE");
        QIcon iconShowImage;
        iconShowImage.addFile(QString::fromUtf8(":/SHOWIMAGE"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowImage->setIcon(iconShowImage);

        actionPOINT = new QAction(MainWindow);
        actionPOINT->setObjectName("actionPOINT");
        actionPOINT->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/POINT"), QSize(), QIcon::Normal, QIcon::Off);
        actionPOINT->setIcon(icon8);

        actionLINE = new QAction(MainWindow);
        actionLINE->setObjectName("actionLINE");
        actionLINE->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/LINE"), QSize(), QIcon::Normal, QIcon::Off);
        actionLINE->setIcon(icon9);

        actionSAVE = new QAction(MainWindow);
        actionSAVE->setObjectName("actionSAVE");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/SAVE"), QSize(), QIcon::Normal, QIcon::Off);
        actionSAVE->setIcon(icon10);

        actionPLAY = new QAction(MainWindow);
        actionPLAY->setObjectName("actionPLAY");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/PLAY"), QSize(), QIcon::Normal, QIcon::Off);
        actionPLAY->setIcon(icon11);

        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");

        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        cv = new CircuitViewer(centralWidget);
        cv->setObjectName("cv");
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cv->sizePolicy().hasHeightForWidth());
        cv->setSizePolicy(sizePolicy);
        cv->setMinimumSize(QSize(200, 200));

        horizontalLayout->addWidget(cv);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 938, 25));
        MainWindow->setMenuBar(menuBar);
        gatesToolbar = new QToolBar(MainWindow);
        gatesToolbar->setObjectName("gatesToolbar");
        gatesToolbar->setAcceptDrops(false);
        gatesToolbar->setMovable(true);
        gatesToolbar->setIconSize(QSize(35, 30));
        gatesToolbar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        gatesToolbar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, gatesToolbar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);
        pointerToolbar = new QToolBar(MainWindow);
        pointerToolbar->setObjectName("pointerToolbar");
        MainWindow->addToolBar(Qt::TopToolBarArea, pointerToolbar);
        /*
        gatesToolbar->addAction(actionINPUT);
        gatesToolbar->addAction(actionOUTPUT);
        gatesToolbar->addAction(actionAND);
        gatesToolbar->addAction(actionOR);
        gatesToolbar->addAction(actionNOT);
        gatesToolbar->addAction(actionNAND);
        gatesToolbar->addAction(actionNOR);
        gatesToolbar->addAction(actionXOR);
        */
        gatesToolbar->addAction(actionLoadImage);
        gatesToolbar->addAction(actionShowImage);
        pointerToolbar->addAction(actionPOINT);
        pointerToolbar->addAction(actionLINE);
        pointerToolbar->addAction(actionSAVE);
        pointerToolbar->addAction(actionPLAY);

        retranslateUi(MainWindow);
        QObject::connect(gatesToolbar, SIGNAL(actionTriggered(QAction*)), cv, SLOT(addItem(QAction*)));
        QObject::connect(pointerToolbar, SIGNAL(actionTriggered(QAction*)), cv, SLOT(setMode(QAction*)));
        QObject::connect(actionSAVE, &QAction::triggered, cv, qOverload<>(&CircuitViewer::record));
        QObject::connect(actionPLAY, &QAction::triggered, cv, qOverload<>(&CircuitViewer::play));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAND->setText(QCoreApplication::translate("MainWindow", "AND", nullptr));
#if QT_CONFIG(tooltip)
        actionAND->setToolTip(QCoreApplication::translate("MainWindow", "AND", nullptr));
#endif // QT_CONFIG(tooltip)
        actionINPUT->setText(QCoreApplication::translate("MainWindow", "INPUT", nullptr));
        actionOUTPUT->setText(QCoreApplication::translate("MainWindow", "OUTPUT", nullptr));
#if QT_CONFIG(tooltip)
        actionOUTPUT->setToolTip(QCoreApplication::translate("MainWindow", "OUTPUT", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOR->setText(QCoreApplication::translate("MainWindow", "OR", nullptr));
#if QT_CONFIG(tooltip)
        actionOR->setToolTip(QCoreApplication::translate("MainWindow", "OR", nullptr));
#endif // QT_CONFIG(tooltip)
        actionNOR->setText(QCoreApplication::translate("MainWindow", "NOR", nullptr));
#if QT_CONFIG(tooltip)
        actionNOR->setToolTip(QCoreApplication::translate("MainWindow", "NOR", nullptr));
#endif // QT_CONFIG(tooltip)
        actionNOT->setText(QCoreApplication::translate("MainWindow", "NOT", nullptr));
#if QT_CONFIG(tooltip)
        actionNOT->setToolTip(QCoreApplication::translate("MainWindow", "NOT", nullptr));
#endif // QT_CONFIG(tooltip)
        actionXOR->setText(QCoreApplication::translate("MainWindow", "XOR", nullptr));
#if QT_CONFIG(tooltip)
        actionXOR->setToolTip(QCoreApplication::translate("MainWindow", "XOR", nullptr));
#endif // QT_CONFIG(tooltip)
        actionNAND->setText(QCoreApplication::translate("MainWindow", "NAND", nullptr));
        actionLoadImage->setText(QCoreApplication::translate("MainWindow", "LOADIMAGE", nullptr));
        actionShowImage->setText(QCoreApplication::translate("MainWindow", "SHOWIMAGE", nullptr));
#if QT_CONFIG(tooltip)
        actionNAND->setToolTip(QCoreApplication::translate("MainWindow", "NAND", nullptr));
        actionLoadImage->setToolTip(QCoreApplication::translate("MainWindow", "LoadImage", nullptr));
        actionShowImage->setToolTip(QCoreApplication::translate("MainWindow", "ShowImage", nullptr));
#endif // QT_CONFIG(tooltip)
        actionPOINT->setText(QCoreApplication::translate("MainWindow", "POINT", nullptr));
#if QT_CONFIG(tooltip)
        actionPOINT->setToolTip(QCoreApplication::translate("MainWindow", "Select", nullptr));
#endif // QT_CONFIG(tooltip)
        actionLINE->setText(QCoreApplication::translate("MainWindow", "LINE", nullptr));
        actionSAVE->setText(QCoreApplication::translate("MainWindow", "SAVE", nullptr));
#if QT_CONFIG(tooltip)
        actionSAVE->setToolTip(QCoreApplication::translate("MainWindow", "Save", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPLAY->setToolTip(QCoreApplication::translate("MainWindow", "Play", nullptr));
#endif // QT_CONFIG(tooltip)
        pointerToolbar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
