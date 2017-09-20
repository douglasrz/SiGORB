#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "cadastrousuariodlg.h"
#include "alunoemprestimodlg.h"
#include "professoremprestimodlg.h"
#include "ajudadlg.h"
#include "devolucaodlg.h"
#include "cadastroexemplardlg.h"
#include "cadastropublicacaodlg.h"

#include <QDebug>
#include <QPixmap>
#include <QIcon>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Instanciando os modelos de tabela sql
    this->tableModelUsuario = new QSqlQueryModel(ui->usuarioTable);
    this->tableModelPublicacao = new QSqlQueryModel(ui->publicacoesTable);
    this->tableModelEmprestimo = new QSqlQueryModel(ui->emprestimoTable);

    /*
    QPixmap search_user(":/resources/imgs/search_user.png");
    QIcon ico(search_user);
    ui->usuariosCadastradosBTN->setIcon(ico);
    ui->usuariosCadastradosBTN->setIconSize(search_user.rect().size());

    QPixmap find_document(":/resources/imgs/find_document.png");
    QIcon ico2(find_document);
    ui->publicacoesBTN->setIcon(ico2);
    ui->publicacoesBTN->setIconSize(find_document.rect().size());

    QPixmap loan_document(":/resources/imgs/loan_document.png");
    QIcon ico3(loan_document);
    ui->emprestimosBTN->setIcon(ico3);
    ui->emprestimosBTN->setIconSize(loan_document.rect().size());
    */


    connect(ui->actionUsuario, SIGNAL(triggered(bool)), this, SLOT(janelaCadastrarUsuario()));//COMANDO PARA ABRIR OUTRA JANELA - TIPO REFERENCIAR OUTRA JANELA
    connect(ui->actionAlunoEmp,SIGNAL(triggered()),this,SLOT(janelaEmprestimoAluno()));
    connect(ui->actionProfessorEmp,SIGNAL(triggered()),this,SLOT(janelaEmprestimoProf()));
    connect(ui->menuDevolucao, SIGNAL(aboutToShow()), this, SLOT(janelaDevolucao()));
    connect(ui->actionExemplar, SIGNAL(triggered(bool)), this, SLOT(janelaExemplar()));
    connect(ui->actionPublicacao, SIGNAL(triggered(bool)),this,SLOT(janelaCadastrarPublicacao()));
    connect(ui->usuariosCadastradosBTN, SIGNAL(clicked()), this, SLOT(paginaUsuarios()));//usuariosCadastradosBTN É UM BOTAO QUANDO APERTADO VAI ABRIR A PAGINA paginaUsuarios
    connect(ui->emprestimosBTN, SIGNAL(clicked()), this, SLOT(paginaEmprestimos()));//SIGNAL É APOREÇÃO FEITA COM O SLOT QUE É APGINA
    connect(ui->publicacoesBTN, SIGNAL(clicked()), this, SLOT(paginaPublicacoes()));

    connect(ui->buscarUsuarioBTN, SIGNAL(clicked()), this, SLOT(buscarUsuarios()));
    connect(ui->buscarPublicacoesBTN, SIGNAL(clicked(bool)), this, SLOT(buscarPublicacoes()));
    connect(ui->buscarEmprestimosBTN, SIGNAL(clicked(bool)), this, SLOT(buscarEmprestimos()));

    connect(ui->tipoDeBuscaUsuarioCB, SIGNAL(currentTextChanged(QString)), this, SLOT(tipoDeBuscaUsuario()));
    connect(ui->tipoDeBuscaPublicacaoCB, SIGNAL(currentTextChanged(QString)), this, SLOT(tipoDeBuscaPublicacao()));
    connect(ui->tipoDeBuscaEmprestimoCB, SIGNAL(currentTextChanged(QString)), this, SLOT(tipoDeBuscaEmprestimo()));

    tipoDeBuscaPublicacao();
    tipoDeBuscaUsuario();
    tipoDeBuscaEmprestimo();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tableModelUsuario;
}

//Definir qual pagina dentro do main sera exibida
void MainWindow::paginaUsuarios()
{
    ui->paginas->setCurrentIndex(1);
}

void MainWindow::paginaPublicacoes()
{
    ui->paginas->setCurrentIndex(2);
}

void MainWindow::paginaEmprestimos()
{
    ui->paginas->setCurrentIndex(3);
}

//Exibição de outras janelas
void MainWindow::janelaCadastrarUsuario()
{
    CadastroUsuarioDLG *janela = new CadastroUsuarioDLG();
    janela->exec();
}
void MainWindow::janelaCadastrarPublicacao()
{
    CadastroPublicacaoDLG *janela=new CadastroPublicacaoDLG();
    janela->exec();
}
void MainWindow::janelaEmprestimoAluno()
{
    AlunoEmprestimoDLG* janela=new AlunoEmprestimoDLG();
    janela->exec();
}
void MainWindow::janelaEmprestimoProf()
{
    ProfessorEmprestimoDLG* janela=new ProfessorEmprestimoDLG();
    janela->exec();
}
void MainWindow::janelaAjuda()
{
    ajudaDlg* janela = new ajudaDlg();
    janela->exec();
}
void MainWindow::janelaDevolucao()
{
    devolucaoDlg* janela = new devolucaoDlg();
    janela->exec();
}

void MainWindow::janelaExemplar()
{
    CadastroExemplarDLG *janela = new CadastroExemplarDLG();
    janela->exec();
}


//Execução de instruções sql
void MainWindow::executarBuscaPorUsuario(QString consulta)
{

    // Configura os cabeçalhos da tabela
    QStringList headers;
    headers.append(tr("Id"));
    headers.append(tr("Nome"));
    headers.append(tr("E-mail"));
    headers.append(tr("Telefone"));
    headers.append(tr("Data de Nascimento"));
    headers.append(tr("Cidade"));
    headers.append(tr("UF"));
    headers.append(tr("Rua"));
    headers.append(tr("Bairro"));
    headers.append(tr("Numero da casa"));

    QSqlDatabase bd = ConnectionDB::get_bd();
    QSqlQuery* qry = new QSqlQuery(bd);

    qry->prepare(consulta);

    if(!qry->exec())
    {
        qDebug() << qry->lastQuery();
        qDebug() << qry->lastError();
    }
    else
    {
        //Relacionar a tabela para receber dados de uma pesquisa SQL
        this->tableModelUsuario->setQuery(*qry);

        //Renomenando os titulos das columas
        for (int i = 0; i < headers.size(); ++i)
            this->tableModelUsuario->setHeaderData(i, Qt::Horizontal, headers.at(i));

        //Passando o modelo com os dados para tabela dos usarios
        ui->usuarioTable->setModel(this->tableModelUsuario);
        ui->usuarioTable->resizeColumnsToContents();
    }

    delete qry;
}
void MainWindow::executarBuscaPorPublicacao(QString consulta)
{

    // Configura os cabeçalhos da tabela
    QStringList headers;
    headers.append(tr("Id"));
    headers.append(tr("Título"));
    headers.append(tr("Sub-Título"));
    headers.append(tr("Editora"));
    headers.append(tr("Midia"));
    headers.append(tr("Tipo"));
    headers.append(tr("Volume"));

    QSqlDatabase bd = ConnectionDB::get_bd();
    QSqlQuery* qry = new QSqlQuery(bd);

    qry->prepare(consulta);

    if(!qry->exec())
    {
        qDebug() << qry->lastQuery();
        qDebug() << qry->lastError();
    }
    else
    {
        //Relacionar a table para receber dados de uma pesquisa SQL
        this->tableModelPublicacao->setQuery(*qry);

        for (int i = 0; i < headers.size(); ++i)
            this->tableModelPublicacao->setHeaderData(i, Qt::Horizontal, headers.at(i));

        ui->publicacoesTable->setModel(this->tableModelPublicacao);
        ui->publicacoesTable->resizeColumnsToContents();
    }

    delete qry;
}
void MainWindow::executarBuscaPorEmprestimo(QString consulta)
{
    /*
     *  +-------------------+-------------+------+-----+---------+----------------+
        | Field             | Type        | Null | Key | Default | Extra          |
        +-------------------+-------------+------+-----+---------+----------------+
        | id                | int(11)     | NO   | PRI | NULL    | auto_increment |
        | id_exemplar       | int(11)     | YES  | MUL | NULL    |                |
        | id_usuario        | int(11)     | YES  | MUL | NULL    |                |
        | data_emprestimo   | date        | NO   |     | NULL    |                |
        | data_devedevolver | date        | NO   |     | NULL    |                |
        | data_devolvido    | date        | NO   |     | NULL    |                |
        | qtd_renovacao     | int(11)     | NO   |     | NULL    |                |
        | situacao          | varchar(45) | YES  |     | NULL    |                |
        +-------------------+-------------+------+-----+---------+----------------+
     */
    // Configura os cabeçalhos da tabela
    QStringList headers;
    headers.append(tr("Id"));
    headers.append(tr("Id exemplar"));
    headers.append(tr("Id Usuário"));
    headers.append(tr("Data do Emprestimo"));
    headers.append(tr("Data de Devolucao"));
    headers.append(tr("Data Devolvido"));
    headers.append(tr("Quantidade de Renovação"));
    headers.append(tr("Status"));

    QSqlDatabase bd = ConnectionDB::get_bd();
    QSqlQuery* qry = new QSqlQuery(bd);

    qry->prepare(consulta);

    if(!qry->exec())
    {
        qDebug() << qry->lastQuery();
        qDebug() << qry->lastError();
    }
    else
    {
        //Relacionar a table para receber dados de uma pesquisa SQL
        this->tableModelEmprestimo->setQuery(*qry);

        for (int i = 0; i < headers.size(); ++i)
            this->tableModelEmprestimo->setHeaderData(i, Qt::Horizontal, headers.at(i));

        ui->emprestimoTable->setModel(this->tableModelEmprestimo);
        ui->emprestimoTable->resizeColumnsToContents();
        ui->emprestimoTable->resizeRowsToContents();
    }

    delete qry;
}


//Montando instruções sql
void MainWindow::buscarUsuarios()
{
    switch (ui->tipoDeBuscaUsuarioCB->currentIndex()) {
    case 0: //Todos
    {
        QString consulta = "SELECT * FROM usuario";

        executarBuscaPorUsuario(consulta);

        break;
    }
    case 1: //Nome
    {
        QString consulta = "SELECT * FROM usuario WHERE nome like '";
        consulta.append(ui->pesquisaUsuarioLE->text() + "%'");

        executarBuscaPorUsuario(consulta);

        break;

    }
    case 2: //E-mail
    {
        QString consulta = "SELECT * FROM usuario WHERE email like '";
        consulta.append(ui->pesquisaUsuarioLE->text() + "%'");

        executarBuscaPorUsuario(consulta);

        break;
    }
    default:
        break;
    }
}
void MainWindow::buscarPublicacoes()
{
    switch (ui->tipoDeBuscaPublicacaoCB->currentIndex()) {
    case 0: //Todos
    {
        QString consulta = "SELECT * FROM publicacao";

        executarBuscaPorPublicacao(consulta);

        break;
    }
    case 1: //Título
    {
        QString consulta = "SELECT * FROM publicacao WHERE titulo like '";
        consulta.append(ui->pesquisaPublicacaoLE->text() + "%'");

        executarBuscaPorPublicacao(consulta);

        break;

    }
    case 2: //Editora
    {
        QString consulta = "SELECT * FROM publicacao WHERE editora like '";
        consulta.append(ui->pesquisaPublicacaoLE->text() + "%'");

        executarBuscaPorPublicacao(consulta);

        break;
    }
    case 3: //Gênero
    {
        QString consulta = "SELECT P.*  FROM publicacao as P, genero as G WHERE G.nome like '";
        consulta.append(ui->pesquisaPublicacaoLE->text() + "%'");
        consulta.append(" AND G.id_publicacao = P.id");

        executarBuscaPorPublicacao(consulta);

        break;
    }
    default:
        break;
    }
}
void MainWindow::buscarEmprestimos()
{
    /*
     *  +-------------------+-------------+------+-----+---------+----------------+
        | Field             | Type        | Null | Key | Default | Extra          |
        +-------------------+-------------+------+-----+---------+----------------+
        | id                | int(11)     | NO   | PRI | NULL    | auto_increment |
        | id_exemplar       | int(11)     | YES  | MUL | NULL    |                |
        | id_usuario        | int(11)     | YES  | MUL | NULL    |                |
        | data_emprestimo   | date        | NO   |     | NULL    |                |
        | data_devedevolver | date        | NO   |     | NULL    |                |
        | data_devolvido    | date        | YES  |     | NULL    |                |
        | qtd_renovacao     | int(11)     | NO   |     | NULL    |                |
        | situacao          | varchar(45) | YES  |     | NULL    |                |
        +-------------------+-------------+------+-----+---------+----------------+
     */

    switch (ui->tipoDeBuscaEmprestimoCB->currentIndex()) {
    case 0: //Tudo
    {
        QString consulta = "SELECT * FROM emprestimo";
        executarBuscaPorEmprestimo(consulta);
        break;
    }
    case 1: //Nome do usuário
    {
        QString consulta = "SELECT * FROM emprestimo ";
        consulta.append("WHERE id_usuario = (SELECT U.id FROM usuario as U WHERE U.nome LIKE '");
        consulta.append(ui->pesquisaEmprestimoLE->text() + "%')");
        executarBuscaPorEmprestimo(consulta);

        break;
    }
    case 2: //Id do exemplar
    {
        QString consulta = "SELECT * FROM emprestimo WHERE id_exemplar = '" + ui->pesquisaEmprestimoLE->text() + "'";
        executarBuscaPorEmprestimo(consulta);
        break;
    }
    case 3: //Titulo do livro
    {
        QString consulta = "SELECT E.* FROM emprestimo as E, exemplar as EX, publicacao as P WHERE E.id_exemplar = EX.id AND EX.id_publicacao = P.id AND P.titulo like '" + ui->pesquisaEmprestimoLE->text() +"%'";
        executarBuscaPorEmprestimo(consulta);
        break;
    }
    default:
        break;
    }
}

//Verificando qual o tipo de busca foi excolhido
void MainWindow::tipoDeBuscaUsuario()
{
    if(ui->tipoDeBuscaUsuarioCB->currentText() != "Todos"){
        ui->pesquisaUsuarioLE->setEnabled(true);
    }
    else{
        ui->pesquisaUsuarioLE->setEnabled(false);
    }

    ui->restricaoDeBuscaUsuarioLB->setText(ui->tipoDeBuscaUsuarioCB->currentText());
    ui->pesquisaUsuarioLE->setText("");
}
void MainWindow::tipoDeBuscaPublicacao()
{
    if(ui->tipoDeBuscaPublicacaoCB->currentText() != "Todas"){
        ui->pesquisaPublicacaoLE->setEnabled(true);
    }
    else{
        ui->pesquisaPublicacaoLE->setEnabled(false);
    }

    ui->pesquisaPublicacaoLE->setText("");
}
void MainWindow::tipoDeBuscaEmprestimo()
{
    if(ui->tipoDeBuscaEmprestimoCB->currentText() != "Tudo"){
        ui->pesquisaEmprestimoLE->setEnabled(true);

    }
    else{
        ui->pesquisaEmprestimoLE->setEnabled(false);
    }

    ui->restricaoPesquisaEmprestimoLB->setText(ui->tipoDeBuscaEmprestimoCB->currentText());
    ui->pesquisaEmprestimoLE->setText("");
}
