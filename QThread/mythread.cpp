#include "mythread.h"

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run()
{
    sleep(5);
//    for(int i=0;i<100000;++i)
//    {
//        for(int j=0;j<100000;++j)
//        {

//        }
//    }

    emit sigDone();
}
