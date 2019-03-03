#ifndef STAFFVIEW_H
#define STAFFVIEW_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class StaffView;
}

class StaffView : public QDialog
{
    Q_OBJECT

public:
    explicit StaffView(QWidget *parent = 0);
    ~StaffView();

private slots:
    void browseButtonSlot();
    void addAnimalButtonSlot();
    void staffLogoutButtonSlot();
    void addClientButtonSlot();
    void browseClientsButtonSlot();

signals:
    void browseButtonClicked();
    void addAnimalButtonClicked();
    void staffLogoutClicked();
    void addClientButtonClicked();
    void browseClientsButtonClicked();

private:
    Ui::StaffView *ui;
};

#endif // STAFFVIEW_H
