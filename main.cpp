#include "UITPad.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    UITPad window;
    window.show();
    return app.exec();
}
