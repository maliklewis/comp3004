#ifndef ADDCLIENTVIEW_H
#define ADDCLIENTVIEW_H

#include <QDialog>

namespace Ui {
class addclientview;
}

class addclientview : public QDialog
{
    Q_OBJECT

public:
    explicit addclientview(QWidget *parent = 0);
    ~addclientview();

private:
    Ui::addclientview *ui;
};

#endif // ADDCLIENTVIEW_H
