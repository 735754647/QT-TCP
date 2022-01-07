#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
//#include "mainwindow.h"

class Subwidget : public QWidget
{
    Q_OBJECT
public:
    explicit Subwidget(QWidget *parent = nullptr);
   // void setMainObj(MainWindow * wg);

signals:
    void sigSub();
    void sigSub(int, QString);

public slots:
    void myslot();

private:

    QPushButton *b1;
   // MainWindow * wg;
};

#endif // SUBWIDGET_H
