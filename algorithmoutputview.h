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

private:
    Ui::AlgorithmOutputView *ui;
};

#endif // ALGORITHMOUTPUTVIEW_H
