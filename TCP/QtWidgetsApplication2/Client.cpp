#include "Client.h"

Client::Client(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.sIP->setText("127.0.0.1");
	ui.sPort->setText("9999");

	client = new QTcpSocket(this);
	client->connectToHost(QHostAddress(ui.sIP->text()), ui.sPort->text().toInt());


	connect(client, &QTcpSocket::readyRead, this, [=]()
	{
			QByteArray arry = client->readAll();
			ui.record->append(arry);

	});


	connect(ui.send, &QPushButton::clicked, this, [=]()
	{
		client->write(ui.msg->toPlainText().toUtf8().data());

		ui.record->append("my say:" + ui.msg->toPlainText());

		ui.msg->clear();
	});
}

Client::~Client()
{
}
