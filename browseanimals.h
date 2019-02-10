#ifndef BROWSEANIMALS_H
#define BROWSEANIMALS_H

#include <QDialog>

namespace Ui {
class BrowseAnimals;
}

class BrowseAnimals : public QDialog
{
    Q_OBJECT

public:
    explicit BrowseAnimals(QWidget *parent = 0);
    ~BrowseAnimals();

private:
    Ui::BrowseAnimals *ui;
};

#endif // BROWSEANIMALS_H
