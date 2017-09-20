#include "logindlg.h"
#include "ui_logindlg.h"

#include <QPixmap>      //Colocar imagens nos objetos da interace
#include <QSqlDatabase> //Acessar o banco
#include <QSqlQuery>    //Fazer pesquisas no banco
#include <QDebug>       //Imprimir no console do qt
#include <QMessageBox>  //Exibir caixas de mensagens


#include "connectiondb.h"   //Singleton de uma conexão com o banco de dados
                            //Ele ja esta conectado, eu so pego a referencia da conexão pra fazer as consultas


//Construor da janela login
LoginDLG::LoginDLG(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDLG)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPixmap pix(":/resources/imgs/users.png");  //Pegando o caminho da imagem
    ui->iconeLB->setPixmap(pix);                //colocando num label da janela de login

    //Quando o 'cancelarBTN' for clicado a função 'close()' sera executada
    connect(ui->cancelarBTN, SIGNAL(clicked()), this, SLOT(cancelar()));
    //Quando o 'loginBTN' for clicado a função 'login()' sera executada
    connect(ui->loginBTN, SIGNAL(clicked()), this, SLOT(login()));

}

//Destrutor
LoginDLG::~LoginDLG()
{
    delete ui;
}

//Slot login, ele será executado quando o botão de login for precionado
void LoginDLG::login()
{
    //Pegando a conexão do sigleton
    //Todas requisição deverá ser feita a essa classe
    QSqlDatabase bd = ConnectionDB::get_bd();

    //Montando a consulta ao banco
    QString qry("select nome from funcionario where username = \'");
    qry.append(ui->usernameLE->text() + "\' and senha=\'");
    qry.append(ui->senhaLE->text() + "\'");

    //Criando um objeto que é reponsavel pelo recebimento dos resultados da consulta
    //Executando a consulta montada logo acima
    QSqlQuery query = bd.exec(qry);

    //Se não tem um resultado, então o username e senha não estão no banco
    if(!query.next()){
         QMessageBox::warning(this, tr("Aceso negado"), tr("Usuário e senha não conferem."));
    }
    else
    {
        //Se encontrou, então o usuário esta logado
        QString nome = query.value(0).toString();
        qDebug() << tr("Usuário: ") + nome;

        close();
    }

    query.clear();
}

void LoginDLG::cancelar()
{
    close();
    exit(0);
}
