#ifndef ALGORITHMOUTPUTVIEW_H
#define ALGORITHMOUTPUTVIEW_H

#include <QDialog>
#include <QTableView>

namespace Ui {
class AlgorithmOutputView;
}

class AlgorithmOutputView : public QDialog
{
    Q_OBJECT

public:
    explicit AlgorithmOutputView(QWidget *parent = 0);
    ~AlgorithmOutputView();
    QTableView* getForm();
    int acmTableRow;
    QString acmTableRowString;

private slots:
    void browseBackButtonSlot();
    void on_tableView_doubleClicked(const QModelIndex &index);

signals:
    void browseClientsBackButtonClicked();
    void tableItemClicked();

private:
    Ui::AlgorithmOutputView *ui;
};

#endif // ALGORITHMOUTPUTVIEW_H
