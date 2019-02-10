#ifndef ADDANIMALVIEW_H
#define ADDANIMALVIEW_H

#include <QDialog>

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

private:
    Ui::AddAnimalView *ui;
};

#endif // ADDANIMALVIEW_H
