#ifndef CLIENTPREFERENCESVIEW_H
#define CLIENTPREFERENCESVIEW_H

#include <QDialog>

namespace Ui {
class ClientPreferencesView;
}

class ClientPreferencesView : public QDialog
{
    Q_OBJECT

public:
    explicit ClientPreferencesView(QWidget *parent = 0);
    ~ClientPreferencesView();

    QString getPAnimalType();
    QString getPAnimalBreed();
    QString getAgeRange();
    QString getPrefEnvType();
    QString getVetFees();
    QString getKidFriendly();
    QString getEaseTrain();
    QString getHealthCon();
    QString getPrefSize();

signals:
    void saveButtonClicked();

private slots:
    void saveButtonSlot();
    void on_typeDropdown_currentTextChanged(const QString &arg1);

private:
    Ui::ClientPreferencesView *ui;
};

#endif // CLIENTPREFERENCESVIEW_H
