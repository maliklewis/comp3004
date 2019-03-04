#ifndef CLIENTLOGIN_H
#define CLIENTLOGIN_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class ClientLogin;
}

class ClientLogin : public QDialog
{
    Q_OBJECT

public:
    explicit ClientLogin(QWidget *parent = 0);
    ~ClientLogin();
    QString username;

private slots:
    void loginButtonSlot();

signals:
    void clientLoginButtonClicked();

private:
    Ui::ClientLogin *ui;
};

#endif // CLIENTLOGIN_H
