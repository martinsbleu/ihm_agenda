#ifndef AGENDA_H
#define AGENDA_H

#include <QMainWindow>
#include <QtSql>
#include <QImage>
#include <QPixmap>

//CONSTRUCTEUR

namespace Ui { //go to agenda.ui
class AGENDA;
}

class AGENDA : public QMainWindow
{
    Q_OBJECT //macro

public:
    explicit AGENDA(QWidget *parent = 0);
    ~AGENDA();

private slots:

    void showTime();
    void on_pushButton_clicked();
    void showDuration();
    void showImages();
    void showTasks();
    void connectData();
    void checkData();

private:
    Ui::AGENDA *ui;

    QSqlQueryModel *model;
    QSqlQueryModel *model1;
    QSqlQueryModel *model2;
    QSqlQueryModel *model3;
    QSqlQueryModel *model4;
    QSqlQueryModel *model5;

    QSqlQueryModel *model_1;
    QSqlQueryModel *model_2;
    QSqlQueryModel *model_3;
    QSqlQueryModel *model_4;
    QSqlQueryModel *model_5;
    QSqlQueryModel *model_6;

    QImage *image;


    QSqlDatabase db;

};

#endif // AGENDA_H
