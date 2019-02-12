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
    int tableRow;
    QString tableRowString;

private slots:
    void browseBackButtonSlot();
    void on_tableView_doubleClicked(const QModelIndex &index);

signals:
    void browseBackButtonClicked();
    void tableItemClicked();

private:
    Ui::BrowseAnimalsView *ui;
};

#endif // BROWSEANIMALSVIEW_H
