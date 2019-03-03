#ifndef CLIENTDETAILSVIEW_H
#define CLIENTDETAILSVIEW_H

#include <QDialog>

namespace Ui {
class ClientDetailsView;
}

class ClientDetailsView : public QDialog
{
    Q_OBJECT

public:
    explicit ClientDetailsView(QWidget *parent = 0);
    ~ClientDetailsView();

private:
    Ui::ClientDetailsView *ui;
};

#endif // CLIENTDETAILSVIEW_H
