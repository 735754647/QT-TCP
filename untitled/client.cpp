#include "client.h"
#include "ui_client.h"

client::client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);

    socket = new QTcpSocket();
     //连接信号槽
     QObject::connect(socket, &QTcpSocket::readyRead, this, &client::socket_Read_Data);
     QObject::connect(socket, &QTcpSocket::disconnected, this, &client::socket_Disconnected);

     ui->pushButton_Send->setEnabled(false);
     ui->lineEdit_IP->setText("127.0.0.1");
     ui->lineEdit_Port->setText("8765");

 }

 client::~client()
 {
     delete this->socket;
     delete ui;
 }

 void client::on_pushButton_Connect_clicked()
 {
     if(ui->pushButton_Connect->text() == tr("连接"))
     {
         QString IP;
         int port;

         //获取IP地址
         IP = ui->lineEdit_IP->text();
         //获取端口号
         port = ui->lineEdit_Port->text().toInt();

         //取消已有的连接
         socket->abort();
         //连接服务器
         socket->connectToHost(IP, port);

         //等待连接成功
         if(!socket->waitForConnected(30000))
         {
             qDebug() << "Connection failed!";
             return;
         }
         qDebug() << "Connect successfully!";

         //发送按键使能
         ui->pushButton_Send->setEnabled(true);
         //修改按键文字
         ui->pushButton_Connect->setText("断开连接");
     }
     else
     {
         //断开连接
         socket->disconnectFromHost();
         //修改按键文字
         ui->pushButton_Connect->setText("连接");
         ui->pushButton_Send->setEnabled(false);
     }
 }

 void client::on_pushButton_Send_clicked()
 {
     qDebug() << "Send: " << ui->textEdit_Send->toPlainText();
      //获取文本框内容并以ASCII码形式发送
     socket->write(ui->textEdit_Send->toPlainText().toLatin1());
     socket->flush();
 }

 void client::socket_Read_Data()
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

 void client::socket_Disconnected()
 {
     //发送按键失能
     ui->pushButton_Send->setEnabled(false);
     //修改按键文字
     ui->pushButton_Connect->setText("连接");
     qDebug() << "Disconnected!";
 }
