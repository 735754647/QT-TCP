/********************************************************************************
** Form generated from reading UI file 'Server.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerClass
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *sIP;
    QLabel *label_2;
    QLineEdit *sPort;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QTextEdit *record;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QTextEdit *msg;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *send;

    void setupUi(QWidget *ServerClass)
    {
        if (ServerClass->objectName().isEmpty())
            ServerClass->setObjectName(QString::fromUtf8("ServerClass"));
        ServerClass->resize(546, 556);
        verticalLayout_3 = new QVBoxLayout(ServerClass);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget = new QWidget(ServerClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        formLayout = new QFormLayout(widget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        sIP = new QLineEdit(widget);
        sIP->setObjectName(QString::fromUtf8("sIP"));

        formLayout->setWidget(0, QFormLayout::FieldRole, sIP);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        sPort = new QLineEdit(widget);
        sPort->setObjectName(QString::fromUtf8("sPort"));

        formLayout->setWidget(1, QFormLayout::FieldRole, sPort);


        verticalLayout_3->addWidget(widget);

        widget_2 = new QWidget(ServerClass);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        record = new QTextEdit(widget_2);
        record->setObjectName(QString::fromUtf8("record"));

        verticalLayout->addWidget(record);


        verticalLayout_3->addWidget(widget_2);

        widget_3 = new QWidget(ServerClass);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        msg = new QTextEdit(widget_3);
        msg->setObjectName(QString::fromUtf8("msg"));

        verticalLayout_2->addWidget(msg);


        verticalLayout_3->addWidget(widget_3);

        widget_4 = new QWidget(ServerClass);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(90, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        send = new QPushButton(widget_4);
        send->setObjectName(QString::fromUtf8("send"));

        horizontalLayout->addWidget(send);


        verticalLayout_3->addWidget(widget_4);


        retranslateUi(ServerClass);

        QMetaObject::connectSlotsByName(ServerClass);
    } // setupUi

    void retranslateUi(QWidget *ServerClass)
    {
        ServerClass->setWindowTitle(QCoreApplication::translate("ServerClass", "Server", nullptr));
        label->setText(QCoreApplication::translate("ServerClass", "IP", nullptr));
        label_2->setText(QCoreApplication::translate("ServerClass", "Port", nullptr));
        label_3->setText(QCoreApplication::translate("ServerClass", "\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
        label_4->setText(QCoreApplication::translate("ServerClass", "\350\276\223\345\205\245", nullptr));
        send->setText(QCoreApplication::translate("ServerClass", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerClass: public Ui_ServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
