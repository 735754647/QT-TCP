#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class client;
}

class client : public QMainWindow
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();

private slots:

    void on_pushButton_Connect_clicked();

    void on_pushButton_Send_clicked();

    void socket_Read_Data();

    void socket_Disconnected();

private:
    Ui::client *ui;
    QTcpSocket *socket;
};

#endif // CLIENT_H
