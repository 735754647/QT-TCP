#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Server)
{
    ui->setupUi(this);
    ui->cIp->setText("127.0.0.1");
    ui->cPort->setText("9999");
    ui->sPort->setText("8888");

    udp=new QUdpSocket(this);

    udp->bind(QHostAddress::AnyIPv4,ui->sPort->text().toInt());

    connect(ui->send,&QPushButton::clicked,this,[=]()
    {
        udp->writeDatagram(ui->msg->toPlainText().toUtf8(),QHostAddress("224.0.0.10"),ui->cPort->text().toUInt());
        ui->record->append("ME say: "+ui->msg->toPlainText());

    });
    connect(udp,&QUdpSocket::readyRead,this,[=]()
    {
        qint64 size =udp->pendingDatagramSize();
        QByteArray array (size,0);
        udp->readDatagram(array.data(),size);
        ui->record->append(array);
    });

}

Server::~Server()
{
    delete ui;
}

