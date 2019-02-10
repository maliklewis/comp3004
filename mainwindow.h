#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stafflogin.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void staffButtonSlot();

signals:
    void staffButtonClicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
