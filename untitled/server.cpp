#include "Server.h"
#include "ui_server.h"
#include  "qdebug.h"
Server::Server(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::server)
{
    ui->setupUi(this);
    ui->lineEdit_Port->setText("8765");
    ui->pushButton_Send->setEnabled(false);

    server = new QTcpServer();

    //连接信号槽
    connect(server,&QTcpServer::newConnection,this,&Server::server_New_Connect);
}


Server::~Server()
{
    server->close();
    server->deleteLater();
    delete ui;
}

void Server::on_pushButton_Send_clicked()
{
    qDebug() << "Send: " << ui->textEdit_Send->toPlainText();
    //获取文本框内容并以ASCII码形式发送
    socket->write(ui->textEdit_Send->toPlainText().toLatin1());
    socket->flush();
}

void Server::server_New_Connect()
{
    //获取客户端连接
    socket = server->nextPendingConnection();
    //连接QTcpSocket的信号槽，以读取新数据
    QObject::connect(socket, &QTcpSocket::readyRead, this, &Server::socket_Read_Data);
    QObject::connect(socket, &QTcpSocket::disconnected, this, &Server::socket_Disconnected);
    //发送按键使能
    ui->pushButton_Send->setEnabled(true);

    qDebug() << "A Client connect!";
}

void Server::socket_Read_Data()
{
    QByteArray buffer;
    //读取缓冲区数据
    buffer = socket->readAll();
    if(!buffer.isEmpty())
    {
        QString str = ui->textEdit_Recv->toPlainText();
        str+=tr(buffer);
        //刷新显示
        ui->textEdit_Recv->setText(str);
    }
}

void Server::socket_Disconnected()
{
    //发送按键失能
    ui->pushButton_Send->setEnabled(false);
    qDebug() << "Disconnected!";
}

void Server::on_pushButton_Listen_clicked()
{

    if(ui->pushButton_Listen->text() == tr("侦听"))
        {
            //从输入框获取端口号
            int port = ui->lineEdit_Port->text().toInt();

            //监听指定的端口
            if(!server->listen(QHostAddress::Any, port))
            {
                //若出错，则输出错误信息
                qDebug()<<server->errorString();
                return;
            }
            //修改按键文字
            ui->pushButton_Listen->setText("取消侦听");
            qDebug()<< "Listen succeessfully!";
        }
        else
            socket->abort();
            //取消侦听
            server->close();
            //修改按键文字
            ui->pushButton_Listen->setText("侦听");
            //发送按键失能
            ui->pushButton_Send->setEnabled(false);
        }

