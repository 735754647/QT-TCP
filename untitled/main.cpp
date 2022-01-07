#include "Server.h"
#include "client.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Server w;
    w.setWindowTitle("server");
    w.show();

    client c;
    c.setWindowTitle("client");
    c.show();
    return a.exec();
}
