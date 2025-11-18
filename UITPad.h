#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_UITPad.h"

class UITPad : public QMainWindow
{
    Q_OBJECT

public:
    UITPad(QWidget *parent = nullptr);
    ~UITPad();

private:
    Ui::UITPad ui;
    void onOpen();
    void onSave();
    void onAbout();
};

