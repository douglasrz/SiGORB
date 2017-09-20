#ifndef CADASTROPUBLICACAODLG_H
#define CADASTROPUBLICACAODLG_H

#include <QDialog>

namespace Ui {
class CadastroPublicacaoDLG;
}

class CadastroPublicacaoDLG : public QDialog
{
    Q_OBJECT

public:
    explicit CadastroPublicacaoDLG(QWidget *parent = 0);
    ~CadastroPublicacaoDLG();

private:
    Ui::CadastroPublicacaoDLG *ui;
private slots:
    void cadastrarp();
};


#endif // CADASTROPUBLICACAODLG_H
