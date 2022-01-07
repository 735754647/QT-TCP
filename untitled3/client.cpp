#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    ui->sIp->setText("127.0.0.1");
    ui->sPort->setText("8888");
    ui->cPort->setText("9999");

    udp1=new QUdpSocket(this);

    udp1->bind(QHostAddress::AnyIPv4,ui->sPort->text().toInt());

    udp1->joinMulticastGroup(QHostAddress("224.0.0.10"));

    connect(ui->send,&QPushButton::clicked,this,[=]()
    {
        udp1->writeDatagram(ui->msg->toPlainText().toUtf8(),QHostAddress(ui->sIp->text()),ui->sPort->text().toUInt());
        ui->record->append("Client say: "+ui->msg->toPlainText());

    });
    connect(udp1,&QUdpSocket::readyRead,this,[=]()
    {
        qint64 size =udp1->pendingDatagramSize();
        QByteArray array (size,0);
        udp1->readDatagram(array.data(),size);
        ui->record->append(array);
    });
}

Client::~Client()
{
    delete ui;
}
