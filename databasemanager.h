#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QObject>
#include <QSqlDatabase>
#include <QFile>




class databasemanager : public QObject
{
    Q_OBJECT
public:
    explicit databasemanager(QObject *parent = 0);
    bool dbOpen();
    bool dbBuild();
    bool dbClose();
    void dbPopulate();

    bool makeAnimalTable();

    bool insertAnimal(QString name,QString type, QString breed);

    QSqlQuery exec(const QString & query = QString()) const;

    QSqlQuery getAnimalTable();


private:
    QSqlDatabase db;

signals:

public slots:
};

#endif // DATABASEMANAGER_H
