#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mybutton.h"
#include  <QDebug>
#include  <QFileDialog>
#include  <QPushButton>
#include  <QLabel>
#include  <QDialog>
#include  <QMessageBox>
#include  <QColorDialog>
#include  <QFontDialog>
#include  <QPainter>

#pragma execution_character_set("utf-8")

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    b2=new QPushButton("coon",this);
    b2->show();
    b2->move(400,500);

    b3=new QPushButton;
    b3->setParent(this);
    b3->setText("button");
    b3->move(400,300);
    b3->resize(100,60);

    b1.setParent(this);
    b1.setText("my");
    b1.move(400,370);
    b1.resize(100,60);

    MyButton * btn=new MyButton(this);
    btn->setText("my button");
    btn->move(100,0);

    this->setWindowTitle("first");
    this->resize(1200,800);
    //this->setFixedSize(400,400);
    this->setWindowIcon(QIcon("C:\Windows\WinSxS\amd64_microsoft-windows-r..ent-content-neutral_31bf3856ad364e35_10.0.19041.1_none_ae6d71b645f19154\Picture.jpg"));


    //connect(&b1,&QPushButton::clicked,this,&MainWindow::close);
    //connect(b3,&QPushButton::pressed,this,&MainWindow::close);

    connect(b3,&QPushButton::released,this,&MainWindow::slotForMianWidget);

    //subW.setMainObj(this);

    b4=new QPushButton("window",this);
    b4->move(400,240);
    b4->resize(100,50);

    connect(b4,&QPushButton::released,this,&MainWindow::slotForHideMe);

    void (Subwidget::*MySigSub)()=&Subwidget::sigSub;
    connect(&subW,MySigSub,this,&MainWindow::slotShowMe);

    void (Subwidget::*MySigPlus)(int,QString)=&Subwidget::sigSub;
    connect(&subW,MySigPlus,this,&MainWindow::slotSubMsg);

//    connect(&subW,SIGNAL(sigSub()),this,SLOT(slotShowMe()));
//    connect(&subW,SIGNAL(sigSub(int,QString)),this,SLOT(slotSubMsg(int,QString)));

     connect(&b1,&QPushButton::clicked,this,[=]()
     {

         b4->setText("lamba");
         b2->hide();
     });

     connect(ui->actionOpen,&QAction::triggered,this,[=]()
     {
//            QDialog dlg(this);
//            dlg.exec();
//            QString fileName=QFileDialog::getOpenFileName();
//            qDebug()<<fileName.toUtf8().data();
         //QMessageBox::about(this,"about","hello");
//         if (QMessageBox::Ok == QMessageBox::critical(this,"error","file error", QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Cancel))
//         {
//             QDialog dlg(this);
//             dlg.exec();
//         }

//         QColor color=QColorDialog::getColor();
//         qDebug()<<color.red()<<color.green()<<color.blue();

          bool ok;
          QFont font = QFontDialog::getFont(&ok, QFont("华文彩云"), this,"Times");
          qDebug()<<font.family().toUtf8().data()<<font.italic()<<font.pointSize()<<font.bold();


     });

     connect(ui->actionNew,&QAction::triggered,this,[=]()
     {
            QDialog *dlg=new QDialog(this);
            dlg->setAttribute(Qt::WA_DeleteOnClose);
            dlg->show ();

     });


     //ui->statusbar->addWidget(new QPushButton());
        QPushButton * button=new QPushButton("hello",this);
        ui->statusbar->addWidget(button);

        QLabel * label=new QLabel("world",this);
        ui->statusbar->addWidget(label);

        connect(ui->radioButton,&QRadioButton::released,this,[=]()
        {
              QMessageBox::information(this,"radioButton","hello");
        });

        connect(ui->checkBox,&QCheckBox::stateChanged,this,[=](int state)
        {
              QMessageBox::information(this,"checkBox",QString::number(state));
              qDebug()<<state;
        });

        ui->listWidget->addItem("list");

        QListWidgetItem *item=new QListWidgetItem(QIcon(),"add",ui->listWidget);
        //ui->listWidget->addItem(new QListWidgetItem(QIcon(),"add"));

        ui->tableWidget->setRowCount(5);

        ui->tableWidget->setColumnCount(3);
        QStringList list;
        list << "name"<<"gender"<<"age";
        ui->tableWidget->setHorizontalHeaderLabels(list);
        connect(ui->btnMusic,&QPushButton::clicked,this,[=]()
          {
                ui->stackedWidget->setCurrentIndex(1);
        });
        connect(ui->btnOther,&QPushButton::clicked,this,[=]()
          {
                ui->stackedWidget->setCurrentWidget(ui->other);
        });


                ui->comboBox->addItem(QIcon(), "first");
                ui->comboBox->addItem(QIcon(), "second");
                ui->comboBox->addItem(QIcon(), "third");

        ui->mylabel->installEventFilter(this);

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotForMianWidget()
{
    b2->setText("modify");
}

void MainWindow::slotForHideMe()
{
    hide();
    subW.show();
}

void MainWindow::slotShowMe()
{
    show();
    subW.hide();
}

void MainWindow::slotSubMsg(int num , QString str)
{
    qDebug()<<num<<str.toUtf8().data();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);

//    QPen pen;
//    pen.setColor(/*Qt::green*/QColor(0,255,0));
//    pen.setWidth(10);
//    pen.setStyle(Qt::DotLine);
    QPainter *painter = new QPainter(this);
    //画笔
    QPen *pen = new QPen(QColor(Qt::GlobalColor::red));
     pen->setStyle(Qt::DotLine);
     pen->setWidth(10);
    //替换画笔
    painter->setPen(*pen);

    QBrush *brush=new QBrush(Qt::blue);
    painter->setBrush(*brush);

    //p.drawPixmap(0,0,QPixmap(":/Image/1.jpg"));
    p.drawLine(QPoint(100,100),QPoint(300,500));
    p.drawEllipse(QPoint(200,200),100,50);
    p.drawRect(550,230,200,200);
    QFont font("华文彩云",48,75,true);
    p.setFont(font);
    p.drawText(600,500,"china");
}

bool MainWindow::eventFilter(QObject *obj, QEvent *e)
{
    if(obj==ui->mylabel)
    {
         if(e->type() == QEvent::MouseMove)
        {
             ui->mylabel->setText("+++++++++++++");
            return true;
        }
    }
        return QWidget::eventFilter(obj,e);
}




