#include "Server.h"

Server::Server(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	ui.sIP->setText("127.0.0.1");
	ui.sPort->setText("9999");

	server = new QTcpServer(this);
	server->listen(QHostAddress(ui.sIP->text()), ui.sPort->text().toInt());

	connect(server, &QTcpServer::newConnection, this, [=]()
	{
		coon = server->nextPendingConnection();
		ui.record->append("have new connect");

		connect(coon, &QTcpSocket::readyRead, this, [=]()
		{
			QByteArray arry = coon->readAll();
			ui.record->append(arry);


		});

	});

	connect(ui.send, &QPushButton::clicked, this, [=]()
	{
		coon->write(ui.msg->toPlainText().toUtf8());

		ui.record->append("my say:" + ui.msg->toPlainText());

		ui.msg->clear();
	});
}
