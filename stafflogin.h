#ifndef STAFFLOGIN_H
#define STAFFLOGIN_H

#include <QDialog>
#include <QDebug>
#include <QLineEdit>

namespace Ui {
class StaffLogin;
}

class StaffLogin : public QDialog
{
    Q_OBJECT

public:
    explicit StaffLogin(QWidget *parent = 0);
    ~StaffLogin();
    QString username;
    QLineEdit* getForm();

private slots:
    void loginButtonSlot();

signals:
    void loginButtonClicked();

private:
    Ui::StaffLogin *ui;
};

#endif // STAFFLOGIN_H
