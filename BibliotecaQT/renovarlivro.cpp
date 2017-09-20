#include "renovarlivro.h"
#include "ui_renovarlivro.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QDate>


QString codigo_do_livro;
bool devolver=false;
bool renovar=true;

QSqlDatabase bd = ConnectionDB::get_bd();

RenovarLivro::RenovarLivro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RenovarLivro)
{
    ui->setupUi(this);
    connect(ui->buscarLivro,SIGNAL(clicked()),this,SLOT(buscarLivro()));

    this->con=ConnectionDB::get_con();
    QSqlDatabase bd=con->get_bd();
}

RenovarLivro::~RenovarLivro()
{
    delete ui;
}

void RenovarLivro::buscarLivro(){
    codigo_do_livro=ui->idLivro->text();//PEGO O COD DO LIVRO DIGITADO PELO USUARIO

    //VERIFICANDO SE EXISTE ESSE EMPRESTIMO
    QString verificar("SELECT *FROM emprestimo WHERE id_exemplar="+codigo_do_livro);
    QSqlQuery existe=bd.exec(verificar);
    existe.exec();
    if(existe.value(0).isNull()){
        QMessageBox::warning(this,tr("ERRO"),tr("LIVRO NÃO ESTÁ EM EMPRÉSTIMO"));
        return;
    }
    //PEGANDO AQUANTIDADE QUE AINDA PODE RENOVAR
    QString verQtd("SELECT qtd_renovacao FROM emprestimo WHERE id_exemplar="+codigo_do_livro);
    QSqlQuery qtd=bd.exec(verQtd);
    qtd.next();
    if(qtd.value(0).toInt()<=0){
        QMessageBox::warning(this,tr("ERRO"),tr(" NÃO É PERMITIDO EFETUAR A RENOVAÇÃO\n POIS O LIVRO JÁ FOI RENOVADO 10 VEZES "));
        return;
    }
    //PEGANDO O TITULO DO LIVRO PARA MOSTRAR
    QString cons("SELECT titulo FROM publicacao WHERE id="+codigo_do_livro);
    QSqlQuery busc=bd.exec(cons);
    busc.next();
    ui->tituloLivro->setText(busc.value(0).toString());
    ui->qtdReno->setText(qtd.value(0).toString());//MOSTRANDO A QUANTIDADE QUE AINDA PODE RENOVAR

    //PEGANDO O NOME DO VIADO QUE TA DANDO TRABALHO
    QString consul("SELECT U.nome FROM usuario as U, emprestimo as E WHERE U.id=E.id_usuario AND E.id_exemplar="+codigo_do_livro);
    QSqlQuery usuario=bd.exec(consul);
    usuario.next();
    ui->usuarioNome->setText(usuario.value(0).toString());

    //MOSTRANDO A DATA QUE DEVERIA DEVOLVER
    QString c("SELECT data_devedevolver FROM publicacao WHERE id="+codigo_do_livro);
    QSqlQuery b=bd.exec(c);
    b.next();
    QDate data=b.value(0).toDate();
    ui->devolver->setText(data.toString());
    QDate atual=QDate::currentDate();
    auto dat=data.daysTo(atual);//o compilador deduz o tipo da variavel auto
    QString multa=QString::number(dat*0,50);
    if(dat>=0){
        ui->nvdevolucao->setText(multa);
    }else{
        ui->nvdevolucao->setText("0,00");
    }
}

void RenovarLivro::radiobutonDevolver(){
    devolver=true;
    renovar=false;
}
void RenovarLivro::radiobutonRenovar(){
    renovar=true;
    devolver=false;
}
void RenovarLivro::efetuarEmprestimo(){
    //PEGANDO O NOVO PRAZO
    QDate IssueDate=QDate::currentDate();//tres prixmo linhas é só pra add 15 dias a mais na data atual, para ser a data de devolucao
    QDate ReturnDate;
    ReturnDate=IssueDate.addDays(15);
    QString dataDevolver=ReturnDate.toString("dd-MM-yyyy");
    ui->nvdevolucao->setText(dataDevolver);
    if((devolver==true)&&(renovar==false)){
        QString qry("UPDATE emprestimo SET data_devolvido="+QDate::currentDate().toString("yyyyMMdd")+" WHERE id_exemplar="+codigo_do_livro);
        QSqlQuery update=bd.exec(qry);
        if(update.next()){
            QMessageBox mens;
            mens.setWindowTitle("DEVOLUÇÃO");
            mens.setText("DEVOLUÇÃO EFETUADA COM SUCESSO");
            mens.exec();
        }
    }
    if((renovar==true)&&(devolver==false)){
        QString qry("UPDATE emprestimo SET qtd_renovacao=qtd_renovacao-1,dataDevolver="+dataDevolver+" WHERE id_exemplar="+codigo_do_livro);
        QSqlQuery update=bd.exec(qry);
        if(update.next()){
            QMessageBox mens;
            mens.setWindowTitle("EMPRÉSTIMO RENOVADO");
            mens.setText("NOVA DATA: "+ReturnDate.toString("dd/M/yyyy")+"\nPARA REALIZAR A DEVOLUÇÃO");
            mens.exec();
        }
    }




}




