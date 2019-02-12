#ifndef ANIMALDETAILSVIEW_H
#define ANIMALDETAILSVIEW_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class AnimalDetailsView;
}

class AnimalDetailsView : public QDialog
{
    Q_OBJECT

public:
    explicit AnimalDetailsView(QWidget *parent = 0);
    ~AnimalDetailsView();
    QLabel* getName();
    QLabel* getType();
    QLabel* getBreed();
    QLabel* getGender();
    QLabel* getAge();

private:
    Ui::AnimalDetailsView *ui;
};

#endif // ANIMALDETAILSVIEW_H
