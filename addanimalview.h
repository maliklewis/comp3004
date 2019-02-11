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

signals:
    void insertAnimalButtonClicked();

private slots:
    void insertAnimalButtonSlot();

    void on_typeDropdown_currentTextChanged(const QString &arg1);

private:
    Ui::AddAnimalView *ui;
};

#endif // ADDANIMALVIEW_H
