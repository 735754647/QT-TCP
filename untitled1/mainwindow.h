#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "subwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void slotForMianWidget();
    void slotForHideMe();
    void slotShowMe();
    void slotSubMsg(int num , QString str);


protected:
    void paintEvent(QPaintEvent *);
    bool eventFilter(QObject *obj,QEvent *e);


private:
    Ui::MainWindow *ui;
    QPushButton b1;
    QPushButton *b2;
    QPushButton *b3;
    QPushButton *b4;
    Subwidget subW;
};

#endif // MAINWINDOW_H
