#ifndef CADASTROEXEMPLARDLG_H
#define CADASTROEXEMPLARDLG_H

#include <QDialog>

namespace Ui {
class CadastroExemplarDLG;
}

class CadastroExemplarDLG : public QDialog
{
    Q_OBJECT

public:
    explicit CadastroExemplarDLG(QWidget *parent = 0);
    ~CadastroExemplarDLG();

private:
    Ui::CadastroExemplarDLG *ui;

private slots:
    void cadastrar();
};

#endif // CADASTROEXEMPLARDLG_H
