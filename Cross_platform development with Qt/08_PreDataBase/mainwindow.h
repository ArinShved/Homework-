#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>


#include <QMessageBox>
#include <QtConcurrent>
#include "database.h"
#include "dbdata.h"

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
    void ScreenDataFromDB(QAbstractTableModel *model, int typeRequest);
    void ReceiveStatusConnectionToDB(bool status);
    void ReceiveStatusRequestToDb(QSqlError);


private slots:
    void on_act_addData_triggered();
    void on_act_connect_triggered();
    void on_pb_request_clicked();



    void on_pb_clear_clicked();

signals:
    void sig_RequestToDb(QString request);

private:

    QVector<QString> dataForConnect; //Данные для подключения к БД.

    Ui::MainWindow *ui;
    DbData *dataDb;
    DataBase* dataBase;
    QMessageBox* msg;
    QTableView* tableView;

    QString request = "SELECT title, description FROM film f "
                      "JOIN film_category fc on f.film_id = fc.film_id "
                      "JOIN category c on c.category_id  = fc.category_id";

    QString comedy_request = "SELECT title, description FROM film f "
                             "JOIN film_category fc on f.film_id = fc.film_id "
                             "JOIN category c on c.category_id = fc.category_id "
                             "WHERE c.name = 'Comedy'";

    QString horror_request = "SELECT title, description FROM film f "
                             "JOIN film_category fc on f.film_id = fc.film_id "
                             "JOIN category c on c.category_id = fc.category_id "
                             "WHERE c.name = 'Horror'";


};
#endif // MAINWINDOW_H
