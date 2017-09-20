#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSqlQueryModel* tableModelUsuario;
    QSqlQueryModel* tableModelPublicacao;
    QSqlQueryModel* tableModelEmprestimo;

    //Função que executa uma pesquisa no banco
    void executarBuscaPorUsuario(QString consulta);
    void executarBuscaPorPublicacao(QString consulta);
    void executarBuscaPorEmprestimo(QString consulta);

private slots:
    //Exibição de outras janelas
    void janelaCadastrarUsuario();
    void janelaEmprestimoAluno();
    void janelaEmprestimoProf();
    void janelaAjuda();
    void janelaDevolucao();
    void janelaExemplar();
    void janelaCadastrarPublicacao();

    //Mudar as paginas dentro do main
    void paginaUsuarios();
    void paginaPublicacoes();
    void paginaEmprestimos();

    //Montar buca para ser executada
    void buscarUsuarios();
    void buscarPublicacoes();
    void buscarEmprestimos();

    //Eventos de tipo de busca
    void tipoDeBuscaUsuario();
    void tipoDeBuscaPublicacao();
    void tipoDeBuscaEmprestimo();
};

#endif // MAINWINDOW_H
