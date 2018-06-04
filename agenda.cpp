#include "agenda.h"
#include "ui_agenda.h"

#include <QTimer>
#include <QDateTime>
#include <QCalendarWidget>
#include <QDateEdit>
#include <QtWidgets>
#include <QDebug>

#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>

#include <chrono>
#include <thread>

#include <QPixmap>
#include <QImage>
#include <iostream>


using namespace std;

AGENDA::AGENDA(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AGENDA)
{
    ui->setupUi(this);

//    ui->label_16->setStyleSheet("background-color: rgb(0,170,255);");

    //
    QTimer *timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();

    QDate date=QDate::currentDate();
    QString date_text=date.toString(" dddd dd MMMM yyyy");
    ui->digital_calendar->setText(date_text);

//    ui->Digital_clock->setStyleSheet("background:transparent;");
//    ui->Digital_clock->setAttribute(Qt::WA_TranslucentBackground, true);
//    ui->Digital_clock->setAttribute(Qt::WA_NoSystemBackground, false);
//    ui->Digital_clock->setWindowFlag(Qt::FramelessWindowHint,true);
    connectData();
    checkData();
    showTasks();
    showDuration();
    showImages();

}


// Connexion au BDD /////////////////////////////////////////////////////////////////////////////////////////////////////
void AGENDA::connectData()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("handidom");

}
 //Vérifie si la BDD existe /////////////////////////////////////////////////////////////////////////////////////////////////////

void AGENDA::checkData()
{
    if (db.open())
    {
        cout << "Database Access Granted" << endl;
        QString notification("Database Access Granted");
        ui->noti->setText(notification);

    }
    else
    {
        cout << "Cannot Enter Data" << endl;
    }
}

void AGENDA::showTasks()
{
//    while (true)
//    {
        QSqlQuery mysqlquery;
        mysqlquery.exec("SELECT name FROM `agenda` WHERE id = 1 ");
        this->model  = new QSqlQueryModel();
        model->setQuery(mysqlquery);
        ui->listView->setModel(model);

        mysqlquery.exec("SELECT name FROM `agenda` WHERE id = 2 ");
        this->model1  = new QSqlQueryModel();
        model1->setQuery(mysqlquery);
        ui->listView_5->setModel(model1);

        mysqlquery.exec("SELECT name FROM `agenda` WHERE id = 3 ");
        this->model2  = new QSqlQueryModel();
        model2->setQuery(mysqlquery);
        ui->listView_6->setModel(model2);

        mysqlquery.exec("SELECT name FROM `agenda` WHERE id = 4 ");
        this->model3  = new QSqlQueryModel();
        model3->setQuery(mysqlquery);
        ui->listView_7->setModel(model3);

        mysqlquery.exec("SELECT name FROM `agenda` WHERE id = 5 ");
        this->model4  = new QSqlQueryModel();
        model4->setQuery(mysqlquery);
        ui->listView_8->setModel(model4);

        mysqlquery.exec("SELECT name FROM `agenda` WHERE id = 6 ");
        this->model5  = new QSqlQueryModel();
        model5->setQuery(mysqlquery);
        ui->listView_4->setModel(model5);
}

void AGENDA::showDuration()
{
        QSqlQuery mysqlquery;
        // Time show //
        mysqlquery.exec("SELECT SUBSTRING(start,12,5) FROM agenda WHERE id = 1");
        this->model_1  = new QSqlQueryModel();
        model_1->setQuery(mysqlquery);
        ui->listView_2->setModel(model_1);

        mysqlquery.exec("SELECT SUBSTRING(start,12,5) FROM `agenda` WHERE id = 2 ");
        this->model_2  = new QSqlQueryModel();
        model_2->setQuery(mysqlquery);
        ui->listView_3->setModel(model_2);

        mysqlquery.exec("SELECT SUBSTRING(start,12,5) FROM `agenda` WHERE id = 3 ");
        this->model_3  = new QSqlQueryModel();
        model_3->setQuery(mysqlquery);
        ui->listView_9->setModel(model_3);

        mysqlquery.exec("SELECT SUBSTRING(start,12,5) FROM `agenda` WHERE id = 4 ");
        this->model_4  = new QSqlQueryModel();
        model_4->setQuery(mysqlquery);
        ui->listView_10->setModel(model_4);

        mysqlquery.exec("SELECT SUBSTRING(start,12,5) FROM `agenda` WHERE id = 5 ");
        this->model_5  = new QSqlQueryModel();
        model_5->setQuery(mysqlquery);
        ui->listView_11->setModel(model_5);

        mysqlquery.exec("SELECT SUBSTRING(start,12,5) FROM `agenda` WHERE id = 6 ");
        this->model_6  = new QSqlQueryModel();
        model_6->setQuery(mysqlquery);
        ui->listView_12->setModel(model_6);
}

void AGENDA::showImages()
{
    // ////id Pictogrammes /////////////////////////////////////////////////////////////////////////////////////////////////////
        QString picto,picto1, picto2, picto3, picto4, picto5;
    //    QString test ="F:/CONFIDENTIAL/CroixROUGE/pictos/";
        QString test ="C:/Users/MARTIN/Pictures/IHM AGENDA/PICTOGRAME/";

        QSqlQuery mysqlquery;
        mysqlquery.exec("SELECT picto FROM `agenda` WHERE id = 1 ");
        while (mysqlquery.next())
        {
            picto=mysqlquery.value("picto").toString().toUtf8().constData();
            test.append(picto);
            QPixmap pix(test);
            ui->label_3->setPixmap(pix);
        }

        QString test7 ="C:/Users/MARTIN/Pictures/IHM AGENDA/PICTOGRAME/";
        mysqlquery.exec("SELECT picto FROM `agenda` WHERE id = 2 ");
        while (mysqlquery.next())
        {
            picto1=mysqlquery.value("picto").toString().toUtf8().constData();
            test7.append(picto1);
            QPixmap pix(test7);
            ui->label_4->setPixmap(pix);
        }


     //   QString test1 ="F:/CONFIDENTIAL/CroixROUGE/pictos/";
        QString test1 ="C:/Users/MARTIN/Pictures/IHM AGENDA/PICTOGRAME/";
        QSqlQuery mysqlquery1;

        mysqlquery1.exec("SELECT picto FROM `agenda` WHERE id = 3 ");
        while (mysqlquery1.next())
        {
            picto2=mysqlquery1.value("picto").toString().toUtf8().constData();
            test1.append(picto2);
            QPixmap pix1(test1);
            ui->label_9->setPixmap(pix1);
        }

    //    QString test3 ="F:/CONFIDENTIAL/CroixROUGE/pictos/";
        QString test3 ="C:/Users/MARTIN/Pictures/IHM AGENDA/PICTOGRAME/";
        QSqlQuery mysqlquery3;
        mysqlquery3.exec("SELECT picto FROM `agenda` WHERE id = 4 ");
        while (mysqlquery3.next())
        {
            picto3=mysqlquery3.value("picto").toString().toUtf8().constData();
            test3.append(picto3);
            QPixmap pix3(test3);
            ui->label_10->setPixmap(pix3);
        }


     //   QString test2 ="F:/CONFIDENTIAL/CroixROUGE/pictos/";
        QString test2 ="C:/Users/MARTIN/Pictures/IHM AGENDA/PICTOGRAME/";
        QSqlQuery mysqlquery2;
        mysqlquery2.exec("SELECT picto FROM `agenda` WHERE id = 5 ");
        while (mysqlquery2.next())
        {
            picto4=mysqlquery2.value("picto").toString().toUtf8().constData();
            test2.append(picto4);
            QPixmap pix2(test2);
            ui->label_11->setPixmap(pix2);
        }

      //  QString test4 ="F:/CONFIDENTIAL/CroixROUGE/pictos/";
        QString test4 ="C:/Users/MARTIN/Pictures/IHM AGENDA/PICTOGRAME/";
        QSqlQuery mysqlquery4;
        mysqlquery4.exec("SELECT picto FROM agenda WHERE id = 6 ");
        while (mysqlquery4.next())
        {
            picto5=mysqlquery4.value("picto").toString().toUtf8().constData();
            test4.append(picto5);
            QPixmap pix4(test4);
            ui->label_8->setPixmap(pix4);
        }
//        std::this_thread::sleep_for(std::chrono::seconds(5));
//    }
}

//Création du méthode d'horloge digitale dans la déclaration AGENDA
void AGENDA::showTime()
{
    //currentTime: type de temps pour afficher
    QTime time=QTime::currentTime();
    //déclarer l'affichage de l'horloge
    QString time_text=time.toString("hh:mm:ss");
    //Pointer à label Digital_clock avec la méthode time_textđcm
    ui->Digital_clock->setText(time_text);
}

void AGENDA::on_pushButton_clicked()
{
    close();
}


AGENDA::~AGENDA()
{
    delete ui;
}


/* SQL EXEMPLES*/

//    mysqlquery.exec("SELECT * FROM agenda");
//    string userid, username, descript, dstart, dend, picto;
//    if (mysqlquery.size()>0)
//    {
//        while (mysqlquery.next())
//        {
//            userid=mysqlquery.value("id").toString().toUtf8().constData();
//            username=mysqlquery.value("name").toString().toUtf8().constData();
//            descript=mysqlquery.value("description").toString().toUtf8().constData();
//            dstart=mysqlquery.value("start").toString().toUtf8().constData();
//            dend=mysqlquery.value("end").toString().toUtf8().constData();
//            picto=mysqlquery.value("picto").toString().toUtf8().constData();

//            cout << userid << " - " << username << " - " << descript << " - " << dstart << " - " << dend << " - " << picto << endl;
//        }
//    }
//    else
//    {
//        cout << "404" << endl;
//    }

