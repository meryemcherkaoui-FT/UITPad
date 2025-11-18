/********************************************************************************
** Form generated from reading UI file 'UITPad.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UITPAD_H
#define UI_UITPAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UITPad
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionAbout;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;

    void setupUi(QMainWindow *UITPad)
    {
        if (UITPad->objectName().isEmpty())
            UITPad->setObjectName("UITPad");
        UITPad->resize(800, 600);
        actionOpen = new QAction(UITPad);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(UITPad);
        actionSave->setObjectName("actionSave");
        actionExit = new QAction(UITPad);
        actionExit->setObjectName("actionExit");
        actionUndo = new QAction(UITPad);
        actionUndo->setObjectName("actionUndo");
        actionRedo = new QAction(UITPad);
        actionRedo->setObjectName("actionRedo");
        actionCut = new QAction(UITPad);
        actionCut->setObjectName("actionCut");
        actionCopy = new QAction(UITPad);
        actionCopy->setObjectName("actionCopy");
        actionPaste = new QAction(UITPad);
        actionPaste->setObjectName("actionPaste");
        actionAbout = new QAction(UITPad);
        actionAbout->setObjectName("actionAbout");
        centralWidget = new QWidget(UITPad);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName("verticalLayout");
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        UITPad->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UITPad);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName("menuEdit");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        UITPad->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuHelp->addAction(actionAbout);

        retranslateUi(UITPad);

        QMetaObject::connectSlotsByName(UITPad);
    } // setupUi

    void retranslateUi(QMainWindow *UITPad)
    {
        UITPad->setWindowTitle(QCoreApplication::translate("UITPad", "UITPad - Simple Text Editor", nullptr));
        actionOpen->setText(QCoreApplication::translate("UITPad", "&Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("UITPad", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("UITPad", "&Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("UITPad", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("UITPad", "E&xit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("UITPad", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUndo->setText(QCoreApplication::translate("UITPad", "&Undo", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("UITPad", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRedo->setText(QCoreApplication::translate("UITPad", "&Redo", nullptr));
#if QT_CONFIG(shortcut)
        actionRedo->setShortcut(QCoreApplication::translate("UITPad", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut->setText(QCoreApplication::translate("UITPad", "Cu&t", nullptr));
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("UITPad", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("UITPad", "&Copy", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("UITPad", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("UITPad", "&Paste", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("UITPad", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("UITPad", "&About", nullptr));
        textEdit->setPlaceholderText(QCoreApplication::translate("UITPad", "Start typing your text here...", nullptr));
        menuFile->setTitle(QCoreApplication::translate("UITPad", "&File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("UITPad", "&Edit", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("UITPad", "&Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UITPad: public Ui_UITPad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UITPAD_H
