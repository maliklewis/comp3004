#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QObject>
#include <QSqlDatabase>

class databasemanager : public QObject
{
    Q_OBJECT
public:
    static databasemanager* getInstance();
    //explicit databasemanager(QObject *parent = 0);
    bool dbOpen();
    bool dbBuild();
    bool dbClose();
    void dbPopulate();

    bool makeAnimalTable();
    bool makeStaffTable();
    bool makeClientTable();
    QVector<QString> editClientGetinfo(QString);
    QVector<QString> editClientaddInfo(QString);


private:
    QSqlDatabase db;
    static databasemanager* instance;

    databasemanager();

signals:

public slots:
};

#endif // DATABASEMANAGER_H
