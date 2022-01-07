#ifndef QPUSHBUTTON_H
#define QPUSHBUTTON_H

#include <QObject>
#include <QWidget>

class QPushButton : public QWidget
{
    Q_OBJECT
public:
    explicit QPushButton(QWidget *parent = nullptr);

signals:

};

#endif // QPUSHBUTTON_H
