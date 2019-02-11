#ifndef BROWSEANIMALSVIEW_H
#define BROWSEANIMALSVIEW_H

#include <QDialog>
#include <QTableView>

namespace Ui {
class BrowseAnimalsView;
}

class BrowseAnimalsView : public QDialog
{
    Q_OBJECT

public:
    explicit BrowseAnimalsView(QWidget *parent = 0);
    ~BrowseAnimalsView();
    QTableView* getForm();

private slots:
    void browseBackButtonSlot();

signals:
    void browseBackButtonClicked();

private:
    Ui::BrowseAnimalsView *ui;
};

#endif // BROWSEANIMALSVIEW_H
