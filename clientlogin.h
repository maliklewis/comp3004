#ifndef CLIENTLOGIN_H
#define CLIENTLOGIN_H

#include <QDialog>

namespace Ui {
class ClientLogin;
}

class ClientLogin : public QDialog
{
    Q_OBJECT

public:
    explicit ClientLogin(QWidget *parent = 0);
    ~ClientLogin();

private:
    Ui::ClientLogin *ui;
};

#endif // CLIENTLOGIN_H
