#include "mylabel.h"
#include <QMouseEvent>
#include <QTimerEvent>
#include <QTimer>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
     this->setMouseTracking(true);

    // id =startTimer(100);

     QTimer * timer =new QTimer(this);
     timer->start(100);

     connect(timer,&QTimer::timeout,this,[=]()
     {
         static int number=0;
         this->setText("this is timer:  "+QString::number( number++));

     });
}
void MyLabel::enterEvent(QEvent *)
{
    setText("come");
}
void MyLabel::leaveEvent(QEvent *)
{
    setText("left");
}
//鼠标按下
void MyLabel::mousePressEvent(QMouseEvent *ev)
{

//      QString str = "123";
//      int number =123;
//      QString::number(number);

//     QString str;
//     str.sprintf("%d","%s",123,"hello");

    //QString str = QString::fromUtf8("MousePress[]:(%1,%2)").arg(ev->x()).arg(ev->y());//"%1,%2,%3"为占位符，对应后面的第几个arg
    QString btn;
    if(ev->button() == Qt::RightButton){
        btn = "RightButton";
    }
    else if(ev->button() == Qt::LeftButton)
    {
        btn = "LeftButton";
    }
    else if(ev->button() == Qt::MidButton)
    {
        btn = "MidButton";
    }
    QString str = QString::fromUtf8("MousePress[%3]:(%1,%2)").arg(ev->x()).arg(ev->y()).arg(btn);
    setText(str);

}


void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QString btn;
    if(ev->button() == Qt::RightButton){
        btn = "RightButton";
    }
    else if(ev->button() == Qt::LeftButton)
    {
        btn = "LeftButton";
    }
    else if(ev->button() == Qt::MidButton)
    {
        btn = "MidButton";
    }
    QString str = QString::fromUtf8("MouseRelease[%3]:(%1,%2)").arg(ev->x()).arg(ev->y()).arg(btn);
    setText(str);
}


//鼠标移动，持续状态使用buttons()函数，
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QString btn;
    if(ev->buttons() & Qt::RightButton){
        btn = "RightButton";
    }
    else if(ev->buttons() & Qt::LeftButton)
    {
        btn = "LeftButton";
    }
    else if(ev->buttons() & Qt::MidButton)
    {
        btn = "MidButton";
    }
    QString str = QString::fromUtf8("MouseMove[%3]:(%1,%2)").arg(ev->x()).arg(ev->y()).arg(btn);
    setText(str);
}

void MyLabel::timerEvent(QTimerEvent *e)
{
//    static int num=0;
//    QString str = QString::fromUtf8("%1,%2").arg("time out ").arg(num++);
//    if(num == 100)
//    {
//        killTimer(id);
//    }
//    setText(str);

//    QString str ;
//    if(e->timerId()==id)
//    {
//            static int num=0;
//            QString str = QString("%1,%2").arg("time out ").arg(num++);
//            if(num >= 100)
//            {
//                killTimer(id);
//            }
//            setText(str);
    //    }
}

bool MyLabel::event(QEvent *e)
{
//    switch (e->type())
//    {
//    case QEvent::MouseMove:
//    mouseMoveEvent(e);
//    break;
//    }

    if(e->type() == QEvent::Timer)
    {
        return true;
    }
    else if(e->type() == QEvent::MouseMove)
    {
        return true;
    }

    return QLabel::event(e);
}
