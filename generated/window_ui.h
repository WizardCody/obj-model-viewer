/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WINDOW_UI_H
#define WINDOW_UI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_windowClass
{
public:
    QAction *actionOpen;
    QAction *actionSmooth;
    QAction *actionBg_color;
    QAction *actionSliders;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionStatistics;
    QAction *actionWireframe;
    QAction *actionPerspective;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOptions;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *windowClass)
    {
        if (windowClass->objectName().isEmpty())
            windowClass->setObjectName(QString::fromUtf8("windowClass"));
        windowClass->resize(558, 384);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/window/resources/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        windowClass->setWindowIcon(icon);
        actionOpen = new QAction(windowClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSmooth = new QAction(windowClass);
        actionSmooth->setObjectName(QString::fromUtf8("actionSmooth"));
        actionSmooth->setCheckable(true);
        actionSmooth->setChecked(true);
        actionSmooth->setEnabled(true);
        actionBg_color = new QAction(windowClass);
        actionBg_color->setObjectName(QString::fromUtf8("actionBg_color"));
        actionSliders = new QAction(windowClass);
        actionSliders->setObjectName(QString::fromUtf8("actionSliders"));
        actionSliders->setCheckable(true);
        actionSliders->setChecked(true);
        actionSliders->setEnabled(true);
        actionExit = new QAction(windowClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout = new QAction(windowClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionStatistics = new QAction(windowClass);
        actionStatistics->setObjectName(QString::fromUtf8("actionStatistics"));
        actionStatistics->setCheckable(true);
        actionStatistics->setChecked(true);
        actionWireframe = new QAction(windowClass);
        actionWireframe->setObjectName(QString::fromUtf8("actionWireframe"));
        actionWireframe->setCheckable(true);
        actionWireframe->setChecked(false);
        actionPerspective = new QAction(windowClass);
        actionPerspective->setObjectName(QString::fromUtf8("actionPerspective"));
        actionPerspective->setCheckable(true);
        actionPerspective->setChecked(true);
        centralWidget = new QWidget(windowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        windowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(windowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 558, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        windowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(windowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        windowClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuOptions->addAction(actionWireframe);
        menuOptions->addAction(actionSmooth);
        menuOptions->addSeparator();
        menuOptions->addAction(actionSliders);
        menuOptions->addAction(actionStatistics);
        menuOptions->addSeparator();
        menuOptions->addAction(actionPerspective);
        menuOptions->addAction(actionBg_color);
        menuHelp->addAction(actionAbout);

        retranslateUi(windowClass);

        QMetaObject::connectSlotsByName(windowClass);
    } // setupUi

    void retranslateUi(QMainWindow *windowClass)
    {
        windowClass->setWindowTitle(QApplication::translate("windowClass", "Obj Model Viewer", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("windowClass", "Open", 0, QApplication::UnicodeUTF8));
        actionSmooth->setText(QApplication::translate("windowClass", "smooth", 0, QApplication::UnicodeUTF8));
        actionBg_color->setText(QApplication::translate("windowClass", "bg color", 0, QApplication::UnicodeUTF8));
        actionSliders->setText(QApplication::translate("windowClass", "sliders", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("windowClass", "Exit", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("windowClass", "About", 0, QApplication::UnicodeUTF8));
        actionStatistics->setText(QApplication::translate("windowClass", "statistics", 0, QApplication::UnicodeUTF8));
        actionWireframe->setText(QApplication::translate("windowClass", "wireframe", 0, QApplication::UnicodeUTF8));
        actionPerspective->setText(QApplication::translate("windowClass", "perspective", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("windowClass", "File", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("windowClass", "Options", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("windowClass", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class windowClass: public Ui_windowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WINDOW_UI_H
