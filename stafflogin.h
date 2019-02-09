#ifndef STAFFLOGIN_H
#define STAFFLOGIN_H

#include <QDialog>

namespace Ui {
class StaffLogin;
}

class StaffLogin : public QDialog
{
    Q_OBJECT

public:
    explicit StaffLogin(QWidget *parent = 0);
    ~StaffLogin();

private:
    Ui::StaffLogin *ui;
};

#endif // STAFFLOGIN_H
