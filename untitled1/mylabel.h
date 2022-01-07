#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);


signals:


protected:
//鼠标进入
void enterEvent(QEvent *);
//鼠标离开
void leaveEvent(QEvent *);
//鼠标按下
void mousePressEvent(QMouseEvent *ev);
//鼠标移动
void mouseMoveEvent(QMouseEvent *ev);
//鼠标释放
void mouseReleaseEvent(QMouseEvent *ev);
//定时器
void timerEvent(QTimerEvent *);

bool event(QEvent *e) ;

bool eventFilter(QObject obj ,QEvent *e) ;

protected:
    int id;

};

#endif // MYLABEL_H
