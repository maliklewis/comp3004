#ifndef EDITCLIENTDETAILSVIEW_H
#define EDITCLIENTDETAILSVIEW_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class EditClientDetailsView;
}

class EditClientDetailsView : public QDialog
{
    Q_OBJECT

public:
    explicit EditClientDetailsView(QWidget *parent = 0);
    ~EditClientDetailsView();
    QLineEdit* getName();
    QLineEdit* getNumber();
    QLineEdit* getEmail();
    QLineEdit* getAge();
    QLineEdit* getNumChild();
    QLineEdit* getAgeChild();
    QLineEdit* getOtherAnimal();
    QLineEdit* getEmploymentType();
    QLineEdit* getMStatus();
    QLineEdit* getEStatus();
    QLineEdit* getIncome();
    QLineEdit* getStyle();

private slots:
    void editClientBackButtonSlot();
    void editClientAddButtonSlot();
    void editClientPrefButtonSlot();

signals:
    void editClientAddButtonClicked();
    void editClientBackButtonClicked();
    void editClientPrefButtonClicked();

private:
    Ui::EditClientDetailsView *ui;
};

#endif // EDITCLIENTDETAILSVIEW_H
