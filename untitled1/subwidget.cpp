#include "subwidget.h"

Subwidget::Subwidget(QWidget *parent) : QWidget(parent)
{
    b1=new QPushButton("window",this);

    b1->resize(100,100);
      this->setWindowTitle("second");
      this->resize(400,600);
    connect(b1,&QPushButton::clicked,this,&Subwidget::myslot);
}

void Subwidget::myslot()
{
    emit sigSub();
    emit sigSub(250,"you is SB");
}

//void Subwidget::setMainObj(MainWindow * mainW)
//{
//    wg=mainW;
//}
