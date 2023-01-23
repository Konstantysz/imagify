#include "ImagifyMainWindow.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    ImagifyMainWindow window;
    window.show();

    return app.exec();
}