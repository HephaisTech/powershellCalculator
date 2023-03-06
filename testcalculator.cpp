#include <QApplication>
#include "calculator.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Calculator winCalcul;
    winCalcul.show();
    return app.exec();
}
