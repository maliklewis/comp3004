#ifndef STAFFVIEW_H
#define STAFFVIEW_H

#include <QDialog>

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
    void on_pushButton_clicked();

private:
    Ui::StaffView *ui;
};

#endif // STAFFVIEW_H
