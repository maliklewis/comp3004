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

signals:
    void browseButtonClicked();
    void addAnimalButtonClicked();
    void staffLogoutButtonSlot();
    void browseButtonClicked();
    void staffLogoutClicked();

private:
    Ui::StaffView *ui;
};

#endif // STAFFVIEW_H
