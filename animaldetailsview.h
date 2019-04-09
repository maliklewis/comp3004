#ifndef ANIMALDETAILSVIEW_H
#define ANIMALDETAILSVIEW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
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
    QComboBox* getGender();
    QLineEdit* getAge();
    QComboBox* getHousetrained();
    QComboBox* getSpecial();
    QComboBox* getSpan();
    QComboBox* getSize();
    QComboBox* getPlayful();
    QComboBox* getCost();
    QComboBox* getShedding();
    QComboBox* getAggression();
    QComboBox* getBehaviour();
    QComboBox* getDisease();
    QComboBox* getParasite();
    QComboBox* getNovice();
    QComboBox* getEase();
    QComboBox* getEnivornment();
    QComboBox* getWinged();
    QComboBox* getVocal();
    QComboBox* getclawState();
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
