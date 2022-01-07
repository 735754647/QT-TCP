#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "mythread.h"
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

    void dealSignal();
    void dealClose();

signals:
    void startThread();

private slots:
    void on_start_clicked();

    void on_stop_clicked();

private:
    Ui::MyWidget *ui;

    MyThread *myT;
    QThread *thread;

};
#endif // MYWIDGET_H
