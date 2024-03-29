#ifndef CLIENTVIEW_H
#define CLIENTVIEW_H

#include <QDialog>

namespace Ui {
class ClientView;
}

class ClientView : public QDialog
{
    Q_OBJECT

public:
    explicit ClientView(QWidget *parent = 0);
    ~ClientView();

private slots:
    void browseButtonSlot();
    void clientLogoutButtonSlot();
    void editProfileButtonSlot();

signals:
    void browseButtonClicked();
    void clientLogoutClicked();
    void editProfileClicked();

private:
    Ui::ClientView *ui;
};

#endif // CLIENTVIEW_H
