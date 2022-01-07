#pragma once

#include <QWidget>
#include "ui_Client.h"
#include <QTcpSocket>
#include <QHostAddress>
class Client : public QWidget
{
	Q_OBJECT

public:
	Client(QWidget *parent = Q_NULLPTR);
	~Client();

private:
	Ui::Client ui;
	QTcpSocket *client;
};
