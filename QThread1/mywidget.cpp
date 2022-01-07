#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>



MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);


    myT=new MyThread;

    thread =new QThread(this);

    myT->moveToThread(thread);

    connect(myT,&MyThread::mysignal,this,&MyWidget::dealSignal);

    qDebug()<<QStringLiteral("主线程号:")<<QThread::currentThread();

    connect(this,&MyWidget::startThread,myT,&MyThread::myTimeOut);

    connect(this,&MyWidget::destroyed,this,&MyWidget::dealClose);

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::dealClose()
{
    on_stop_clicked();

    delete myT;
}

void MyWidget::dealSignal()
{
    static int i=0;
    i++;
    ui->lcdNumber->display(i);
}

void MyWidget::on_start_clicked()
{
    if(thread->isRunning()==true)
    {
        return;
    }

    thread->start();
    myT->setFlag(false);
    emit startThread();
}


void MyWidget::on_stop_clicked()
{
    if(thread->isRunning()==false)
    {
        return;
    }

    myT->setFlag(true);
    thread->quit();
    thread->wait();
}
