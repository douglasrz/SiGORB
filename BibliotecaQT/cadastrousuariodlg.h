#ifndef CADASTROUSUARIODLG_H
#define CADASTROUSUARIODLG_H

#include <QDialog>
#include <QModelIndex>

namespace Ui {
class CadastroUsuarioDLG;
}

class CadastroUsuarioDLG : public QDialog
{
    Q_OBJECT

public:
    explicit CadastroUsuarioDLG(QWidget *parent = 0);
    ~CadastroUsuarioDLG();

private:
    Ui::CadastroUsuarioDLG *ui;
    void carregarCursos();

private slots:
    void cadastrar();
    void tipoDeUsuarioAluno();
    void tipoDeUsuarioProfessor();
};

#endif // CADASTROUSUARIODLG_H
