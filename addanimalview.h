#ifndef ADDANIMALVIEW_H
#define ADDANIMALVIEW_H

#include <QDialog>
#include <QComboBox>

namespace Ui {
class AddAnimalView;
}

class AddAnimalView : public QDialog
{
    Q_OBJECT

public:
    explicit AddAnimalView(QWidget *parent = 0);
    ~AddAnimalView();
    QString name;
    QString age;
    QString type;
    QString breed;
    QString gender;
    QString housetrained;
    QString specialneeds;
    QString lifespan;
    QString size;
    QString carecost;
    QString shedAmount;
    QString aggression;
    QString playfulness;
    QString solitudialBehavior;
    QString parasiticResistance;
    QString goodForNowners;
    QString trainingEase;
    QString environmentType;
    QString deseaseResistance;


signals:
    void insertAnimalButtonClicked();
    void insertAnimalBackButtonClicked();

private slots:
    void insertAnimalButtonSlot();
    void insertAnimalBackButtonSlot();
    void on_typeDropdown_currentTextChanged(const QString &arg1);

private:
    Ui::AddAnimalView *ui;
};

#endif // ADDANIMALVIEW_H
