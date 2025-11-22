#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "textarea.h" // On inclut notre nouveau widget

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setupUi();     // Création de l'interface (Menus, Layouts)
    void setupStyle();  // Application des couleurs (CSS)

    TextArea *textArea; // Notre éditeur de code personnalisé
};
#endif // MAINWINDOW_H
