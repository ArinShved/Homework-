#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{

    dataBase = new QSqlDatabase();
    simpleQuery = new QSqlQuery();
    tableWidget = new QTableWidget();

    tableModel = new QSqlTableModel();
    queryModel = new QSqlQueryModel();


}

DataBase::~DataBase()
{
    delete dataBase;
    delete simpleQuery;
    delete tableWidget;
    delete tableModel;
    delete queryModel;

}

/*!
 * \brief Метод добавляет БД к экземпляру класса QSqlDataBase
 * \param driver драйвер БД
 * \param nameDB имя БД (Если отсутствует Qt задает имя по умолчанию)
 */
void DataBase::AddDataBase(QString driver, QString nameDB)
{

    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);

}

/*!
 * \brief Метод подключается к БД
 * \param для удобства передаем контейнер с данными необходимыми для подключения
 * \return возвращает тип ошибки
 */
void DataBase::ConnectToDataBase(QVector<QString> data)
{

    dataBase->setHostName(data[hostName]);
    dataBase->setDatabaseName(data[dbName]);
    dataBase->setUserName(data[login]);
    dataBase->setPassword(data[pass]);
    dataBase->setPort(data[port].toInt());

    bool status;
    status = dataBase->open( );
    emit sig_SendStatusConnection(status);

}
/*!
 * \brief Метод производит отключение от БД
 * \param Имя БД
 */
void DataBase::DisconnectFromDataBase(QString nameDb)
{

    *dataBase = QSqlDatabase::database(nameDb);
    dataBase->close();

}
/*!
 * \brief Метод формирует запрос к БД.
 * \param request - SQL запрос
 * \return
 */
void DataBase::RequestToDB(QString request)
{
    this->request = request;
    *simpleQuery = QSqlQuery(*dataBase);
    simpleQuery->exec(request);

    emit sig_SendStatusRequest(simpleQuery->lastError( ));

}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}

void DataBase::ReadAnswerFromBD(int type){

    if (type == 0){

           tableModel->setTable("Фильм");
           tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
           tableModel->select();
           emit sig_SendDataFromDB(tableModel, type);
       }
    else {
           queryModel->setQuery(request, *dataBase);
           emit sig_SendDataFromDB(queryModel, type);
    }
}
