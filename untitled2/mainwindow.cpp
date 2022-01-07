#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextCodec>
#include <QTextStream>
#include <QDataStream>
#include <QDebug>
#include <QFileInfo>
#include <QDateTime>

#pragma execution_character_set("utf-8")
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->selectFile,&QPushButton::clicked,this,[=]()
    {
        QString fileName=QFileDialog::getOpenFileName(this,"open file","d:\\");
        if (fileName.isEmpty()==true)
        {
            QMessageBox::warning(this,"waring","select file faild");
        }
        ui->filePath->setText(fileName);


        QFile file(fileName);

        //QTextCodec * codec=QTextCodec::codecForName("gbk");

        bool isOk=file.open(QFile::ReadOnly);
        if(isOk == false)
        {
            QMessageBox::critical(this,"Error","file open faild");
            return ;
        }

//        QByteArray array;
//        while(false ==file.atEnd())
//        {
//            array +=file.readLine();
//        }

        // QByteArray array=file.readAll();
//         ui->textEdit->setText(array);

        //ui->textEdit->setText(codec->toUnicode(array));

        //ui->textEdit->append();

//        char buf[128]={0};
//        file.write(QString("hello world").toUtf8());
//        file.write(buf,strlen(buf));
//        file.write(buf);

        QTextStream stream(&file);

        stream.setCodec("utf8");

        QByteArray array;
              while(false ==stream.atEnd())
              {
                  array +=stream.readLine();
              }
              ui->textEdit->setText(array);

        file.close();
    });
#if 0
    QFile f("1.txt");
    f.open(QFile::WriteOnly);
    QTextStream txt (&f);
    txt <<QString("hello world !") <<123456;
    f.close();

    QString buf1;
    f.open(QFile::ReadOnly);
    txt.setDevice(&f);
    txt >>buf1;
    qDebug()<<buf1.toUtf8().data();
#endif
    QFile f("1.txt");
    f.open(QFile::WriteOnly);
    QDataStream ds (&f);
    ds <<QString("hello world !") <<123456;
    f.close();

    QString buf1;
    int number;
    f.open(QFile::ReadOnly);
    ds.setDevice(&f);
    ds >>buf1>>number;
    qDebug()<<buf1.toUtf8().data()<<number;

//    QImage image("C://Users//admin//Documents//untitled1//Image//1.png");
//    QByteArray a;
//    QDataStream s(&a,QIODevice::ReadWrite);
//    s << image;

    QFileInfo info("C://Users//admin//Documents//untitled1//Image//1.png");
    qDebug()<<"file size"<<info.size();
    qDebug()<<"file path"<<info.filePath();
    qDebug()<<"modify date"<<info.lastModified().toString("yyyy-MM-dd hh:mm:ss");
}

MainWindow::~MainWindow()
{
    delete ui;
}

