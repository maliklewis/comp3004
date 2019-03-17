#ifndef ANIMALDETAILSVIEW_H
#define ANIMALDETAILSVIEW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>

namespace Ui {
class AnimalDetailsView;
}

class AnimalDetailsView : public QDialog
{
    Q_OBJECT

public:
    explicit AnimalDetailsView(QWidget *parent = 0);
    ~AnimalDetailsView();
    QLineEdit* getName();
    QLineEdit* getType();
    QLineEdit* getBreed();
    QLineEdit* getGender();
    QLineEdit* getAge();
    QLineEdit* getHousetrained();
    QLineEdit* getSpecial();
    QLineEdit* getSpan();
    QLineEdit* getSize();
    QLineEdit* getPlayful();
    QLineEdit* getCost();
    QLineEdit* getShedding();
    QLineEdit* getAggression();
    QLineEdit* getBehaviour();
    QLineEdit* getDisease();
    QLineEdit* getParasite();
    QLineEdit* getNovice();
    QLineEdit* getEase();
    QLineEdit* getEnivornment();
    QLineEdit* getWinged();
    QLineEdit* getVocal();
    QLineEdit* getclawState();
    void setClient(bool clientValue);

signals:
    void updateButtonClicked();


private slots:
    void updateButtonSlot();

private:
    Ui::AnimalDetailsView *ui;
    bool isClient = false;
};

#endif // ANIMALDETAILSVIEW_H
