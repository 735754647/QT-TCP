#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTimer>
#include "mythread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private slots:
    void on_begin_clicked();

private:
    Ui::MyWidget *ui;
    QTimer  * mytimer;
    MyThread *myt;
};
#endif // MYWIDGET_H
