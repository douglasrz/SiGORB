#ifndef ALUNOEMPRESTIMODLG_H
#define ALUNOEMPRESTIMODLG_H

#include <QDialog>
#include "connectiondb.h"

namespace Ui {
class AlunoEmprestimoDLG;
}

class AlunoEmprestimoDLG : public QDialog
{
    Q_OBJECT

public:
    explicit AlunoEmprestimoDLG(QWidget *parent = 0);
    ~AlunoEmprestimoDLG();

private slots:
    void buscarLivro();
    void buscarMatAl();
    void efetuarEmprestimoAl();
private:
    Ui::AlunoEmprestimoDLG *ui;
    ConnectionDB* con;
};

#endif // ALUNOEMPRESTIMODLG_H
