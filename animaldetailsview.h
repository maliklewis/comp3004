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
    QLabel* getHousetrained();
    QLabel* getSpecial();
    QLabel* getSpan();
    QLabel* getSize();
    QLabel* getPlayful();
    QLabel* getCost();
    QLabel* getShedding();
    QLabel* getAggression();
    QLabel* getBehaviour();
    QLabel* getDisease();
    QLabel* getParasite();
    QLabel* getNovice();
    QLabel* getEase();
    QLabel* getEnivornment();
    QLabel* getWinged();
    QLabel* getVocal();
    QLabel* getclawState();

private:
    Ui::AnimalDetailsView *ui;
};

#endif // ANIMALDETAILSVIEW_H
