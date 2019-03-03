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
    QString name;
    QString number;
    QString email;

signals:
    void insertClientButtonClicked();
    void insertClientBackButtonClicked();

private slots:
    void insertClientButtonSlot();
    void insertClientBackButtonSlot();

private:
    Ui::addclientview *ui;
};

#endif // ADDCLIENTVIEW_H
