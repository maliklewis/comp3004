#ifndef BROWSECLIENTVIEW_H
#define BROWSECLIENTVIEW_H

#include <QDialog>
#include <QTableView>

namespace Ui {
class BrowseClientView;
}

class BrowseClientView : public QDialog
{
    Q_OBJECT

public:
    explicit BrowseClientView(QWidget *parent = 0);
    ~BrowseClientView();
    QTableView* getForm();
    int clientTableRow;
    QString clientTableRowString;

signals:
    void clientTableItemClicked();
    void browseClientsBackButtonClicked();

private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);
    void browseClientsBackButtonSlot();

private:
    Ui::BrowseClientView *ui;
};

#endif // BROWSECLIENTVIEW_H
