#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);


    void  myTimeOut();
    void  setFlag(bool flag =true);

signals:
    void mysignal();

private:
    bool isStop;

};

#endif // MYTHREAD_H
