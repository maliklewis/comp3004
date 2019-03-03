#ifndef CLIENTDETAILSVIEW_H
#define CLIENTDETAILSVIEW_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class ClientDetailsView;
}

class ClientDetailsView : public QDialog
{
    Q_OBJECT

public:
    explicit ClientDetailsView(QWidget *parent = 0);
    ~ClientDetailsView();
    QLabel* getName();
    QLabel* getNumber();
    QLabel* getEmail();
    QLabel* getAge();
    QLabel* getNumChild();
    QLabel* getAgeChild();
    QLabel* getOtherAnimal();
    QLabel* getEmploymentType();
    QLabel* getMStatus();
    QLabel* getEStatus();
    QLabel* getIncome();
    QLabel* getStyle();




private:
    Ui::ClientDetailsView *ui;
};

#endif // CLIENTDETAILSVIEW_H
