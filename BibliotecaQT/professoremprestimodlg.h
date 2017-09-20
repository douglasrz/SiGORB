#ifndef PROFESSOREMPRESTIMODLG_H
#define PROFESSOREMPRESTIMODLG_H

#include <QDialog>
#include "connectiondb.h"

namespace Ui {
class ProfessorEmprestimoDLG;
}

class ProfessorEmprestimoDLG : public QDialog
{
    Q_OBJECT

public:
    explicit ProfessorEmprestimoDLG(QWidget *parent = 0);
    ~ProfessorEmprestimoDLG();
private slots:
    void buscarLivroProf();
    void buscarProf();
    void efetuarEmprestimo();

private:
    Ui::ProfessorEmprestimoDLG *ui;
    ConnectionDB* con;

};

#endif // PROFESSOREMPRESTIMODLG_H
