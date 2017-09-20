#include "professoremprestimodlg.h"
#include "ui_professoremprestimodlg.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include<QDate>

QString siape;//variaveis para pegar os dados e efetuar o emprestimo
QString codLivroAl;

ProfessorEmprestimoDLG::ProfessorEmprestimoDLG(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfessorEmprestimoDLG)
{
    ui->setupUi(this);
    connect(ui->ButtonCancelarEmpP, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->empButtonProf1,SIGNAL(clicked()),this, SLOT(buscarLivroProf()));
    connect(ui->empButtonProf2,SIGNAL(clicked()),this, SLOT(buscarProf()));
    connect(ui->efetuarEmprestimoButton_3,SIGNAL(clicked()),this,SLOT(efetuarEmprestimo()));
    this->con=ConnectionDB::get_con();
    QSqlDatabase bd=con->get_bd();
}

ProfessorEmprestimoDLG::~ProfessorEmprestimoDLG()
{
    delete ui;
}
void ProfessorEmprestimoDLG::buscarLivroProf(){
    QSqlDatabase bd = ConnectionDB::get_bd();
    codLivroAl=ui->lineEdit->text();

    //VERIFICANDO SE TEM ALGUM LIVRO COM ESSE ID JÁ EMPRESTADO
    QString cons("select *from emprestimo where id_exemplar="+codLivroAl);
    QSqlQuery veriIdEmprestado=bd.exec(cons);
    veriIdEmprestado.next();
    if(!veriIdEmprestado.value(0).isNull()){
        QMessageBox::warning(this,tr("LIVRO JÁ FOI EMPRESTADO"),tr("ESTE ID PERTENCE A UM LIVRO AINDA EM EMPRÉSTIMO"));
        return;
    }

    //PEGANDO O TITULO PELO ID
    QString qry("SELECT titulo FROM publicacao WHERE id = "+codLivroAl);
    QSqlQuery resul=bd.exec(qry);
    if(resul.next()){
        QString consulta=resul.value(0).toString();
        ui->tituloLivroPr->setText(consulta);
        ui->empButtonProf2->setEnabled(true);
        ui->lineEdit_2->setEnabled(true);
    }else{
        QMessageBox::warning(this,tr("ERRO"),tr("NÃO EXISTE LIVRO COM ESTE CÓDIGO, CADASTRADO."));
        ui->lineEdit->clear();
    }
}

void ProfessorEmprestimoDLG::buscarProf(){
    QSqlDatabase bd = ConnectionDB::get_bd();
    siape=ui->lineEdit_2->text();

    //pegando o id do usuario pela matricula dele
    QString consulId("SELECT id_usuario FROM professor WHERE siape="+siape);
    QSqlQuery IdUsuario=bd.exec(consulId);
    IdUsuario.next();
    QString id=IdUsuario.value(0).toString();

    //VERIFICO SE O CARA JÁ TEM 15 EMPRESTIMO, MAXIMO PERMITIDO
    QString qtdEmprestimo("select count(*) from emprestimo where id_usuario="+id+" AND data_devolvido is null");
    QSqlQuery quantidade=bd.exec(qtdEmprestimo);
    quantidade.next();
    int quant= quantidade.value(0).toInt();
    if(quant>14){//SE TIVER 15 EMPRESTIMO, CANCELA
        QMessageBox::warning(this,tr("ERRO"),tr("USUÁRIO TEM 15 OU MAIS EMPRÉSTIMOS EM ABERTO"));
        return;
    }

    //PEGANDO O NOME PELO SIAPE DIGITADO
    QString qry("SELECT U.nome FROM professor as P, usuario as U WHERE P.id_usuario=U.id AND P.siape= "+siape);//PRECISA ALTERAR
    QSqlQuery resul=bd.exec(qry);
    if(resul.next()){
        QString consulta=resul.value(0).toString();
        ui->nomeProf->setText(consulta);
        ui->efetuarEmprestimoButton_3->setEnabled(true);
    }else{
        QMessageBox::warning(this,tr("ERRO"),tr("NÃO EXISTE PROFESSOR COM ESTE SIAPE, CADASTRADO."));
        ui->lineEdit_2->clear();
    }
}

void ProfessorEmprestimoDLG::efetuarEmprestimo(){
    QSqlDatabase bd = ConnectionDB::get_bd();

    //PEGANDO O ID DO USUARIO PELO SIAPE DIGITADO
    QString qry("SELECT id_usuario FROM professor WHERE siape="+siape);
    QSqlQuery busca=bd.exec(qry);
    busca.next();
    QString id_usuario =busca.value(0).toString();//PEGANDO O ID DO USUARIO PELO SIAPE DIGITADO PELO USUARIO

    //TESTANDO ESSA PARA PARA VERIFICAR SE O USUARIO TEM ALGUM LIVRO ATRASADO
    QString pendencia("SELECT data_devedevolver FROM emprestimo WHERE id_usuario="+id_usuario);
    QSqlQuery b=bd.exec(pendencia);

    while(b.next()){//ESTE LAÇO É USADO PARA VERIFICAR SE TEM PENDECIA NA BIBLIOTECA
        QDate prazo=b.value(0).toDate();
        if(prazo.operator <=(QDate::currentDate())&&(prazo.isValid())){
                QMessageBox::warning(this,tr("ERRO"),tr("NÃO FOI POSSIVEL EFETUAR O EMPRESTIMO \nPROFESSOR COM PENDENCIAS NA BIBLIOTECAS"));
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
                ui->tituloLivroPr->clear();
                ui->nomeProf->clear();
                ui->efetuarEmprestimoButton_3->setEnabled(false);
                ui->empButtonProf2->setEnabled(false);
                ui->lineEdit_2->setEnabled(false);
                return;
            }
    }

    QString data=QDate::currentDate().toString("yyyy-MM-dd");//PEGANDO A DATA NO MOMENTO DO EMPRESTIMO
    QDate IssueDate=QDate::currentDate();//tres prixmo linhas é só pra add 15 dias a mais na data atual, para ser a data de devolucao
    QDate ReturnDate;
    ReturnDate=IssueDate.addDays(15);
    QString dataDevolver=ReturnDate.toString("yyyy-MM-dd");

    QSqlQuery tent;
    tent.prepare("INSERT INTO emprestimo(id_exemplar,id_usuario,data_emprestimo,data_devedevolver,qtd_renovacao)"
                 "VALUES(:id_exemplar,:id_usuario,:data_emprestimo,:data_devedevolver, :qtd_renovacao)");
    tent.bindValue(":id_exemplar",codLivroAl);
    tent.bindValue(":id_usuario",id_usuario);
    tent.bindValue(":data_emprestimo",data);
    tent.bindValue(":data_devedevolver",dataDevolver);
    tent.bindValue(":qtd_renovacao",15);

    if(tent.exec()){
        QMessageBox mens;
        mens.setWindowTitle("EMPRÉSTIMO REALIZADO");
        mens.setText("USUÁRIO TEM ATÉ "+ReturnDate.toString("dd/M/yyyy")+"\nPARA REALIZAR A DEVOLUÇÃO");
        mens.exec();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->tituloLivroPr->clear();
        ui->nomeProf->clear();
        ui->efetuarEmprestimoButton_3->setEnabled(false);
        ui->empButtonProf2->setEnabled(false);
        ui->lineEdit_2->setEnabled(false);
    }
    else{
        QMessageBox::warning(this,tr("ERRO"),tr("NÃO FOI POSSIVEL EFETUAR O EMPRÉSTIMO"));
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->tituloLivroPr->clear();
        ui->nomeProf->clear();
    }
}

