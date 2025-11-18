#include "UITPad.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

UITPad::UITPad(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // Connect actions to slots
    connect(ui.actionOpen, &QAction::triggered, this, &UITPad::onOpen);
    connect(ui.actionSave, &QAction::triggered, this, &UITPad::onSave);
    connect(ui.actionExit, &QAction::triggered, this, &QWidget::close);
    connect(ui.actionAbout, &QAction::triggered, this, &UITPad::onAbout);

    // Edit actions are automatically connected to QTextEdit
    ui.actionUndo->setEnabled(false);
    ui.actionRedo->setEnabled(false);

    connect(ui.textEdit, &QTextEdit::undoAvailable, ui.actionUndo, &QAction::setEnabled);
    connect(ui.textEdit, &QTextEdit::redoAvailable, ui.actionRedo, &QAction::setEnabled);
}

void UITPad::onOpen()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            ui.textEdit->setPlainText(in.readAll());
            file.close();
        }
    }
}

void UITPad::onSave()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt);;All Files (*)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << ui.textEdit->toPlainText();
            file.close();
        }
    }
}

void UITPad::onAbout()
{
    QMessageBox::about(this, "About UITPad", "UITPad - Simple Text Editor\nCreated with Qt");
}

UITPad::~UITPad()
{
}