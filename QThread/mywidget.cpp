#include "mywidget.h"
#include "ui_mywidget.h"
#include <QThread>
#include <QDebug>


MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    mytimer =new QTimer(this);

    myt=new MyThread(this);

    connect(mytimer,&QTimer::timeout,this,[=]()
    {
        static int num=0;
        ui->lcdNumber->display(++num);
    });

    connect(myt,&MyThread::sigDone,this,[=]()
    {
        qDebug()<<"timer is stoping";
        mytimer->stop();
    });

    connect(this,&MyWidget::destroyed,this,[=]()
    {
        myt->quit();
        myt->wait();

    });

}

MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget::on_begin_clicked()
{
    if(mytimer->isActive() == true)
    {
        return;
    }
    mytimer->start(100);

//    QThread::sleep(5);

//    mytimer->stop();

//    qDebug()<<"timer is stoping";
     myt->start();
}
