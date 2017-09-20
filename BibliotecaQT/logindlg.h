#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>

namespace Ui {
class LoginDLG;
}

class LoginDLG : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDLG(QWidget *parent = 0);
    ~LoginDLG();

private:
    Ui::LoginDLG *ui;

private slots:
    void login();
    void cancelar();
};

#endif // LOGINDLG_H
