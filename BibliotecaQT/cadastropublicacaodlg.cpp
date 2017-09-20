#include "cadastropublicacaodlg.h"
#include "ui_cadastropublicacaodlg.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "connectiondb.h"
#include<QMessageBox>

CadastroPublicacaoDLG::CadastroPublicacaoDLG(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastroPublicacaoDLG)
{
    ui->setupUi(this);
    connect(ui->cad,SIGNAL(clicked(bool)),this,SLOT(cadastrarp()));
    connect(ui->can,SIGNAL(clicked(bool)),this,SLOT(close()));
}

CadastroPublicacaoDLG::~CadastroPublicacaoDLG()
{
    delete ui;
}

void CadastroPublicacaoDLG::cadastrarp()
{
    /*
     *  +--------------+-------------+------+-----+---------+----------------+
        | Field        | Type        | Null | Key | Default | Extra          |
        +--------------+-------------+------+-----+---------+----------------+
        | id           | int(11)     | NO   | PRI | NULL    | auto_increment |
        | titulo       | varchar(50) | NO   |     | NULL    |                |
        | sub_titulo   | varchar(70) | NO   |     | NULL    |                |
        | editora      | varchar(45) | YES  |     | NULL    |                |
        | midia        | varchar(45) | YES  |     | NULL    |                |
        | tipo_de_obra | varchar(45) | YES  |     | NULL    |                |
        | volume       | int(11)     | YES  |     | NULL    |                |
        +--------------+-------------+------+-----+---------+----------------+
     */

    QSqlDatabase bd=ConnectionDB::get_bd();
    QSqlQuery insert;
    insert.prepare("INSERT INTO publicacao(titulo,sub_titulo,editora,midia,tipo_de_obra,volume) VALUES (:id_tit,:id_sub,:id_ed,:id_mid,:id_tip,:id_vol)");
    insert.bindValue(":id_tit",ui->TituloLE->text());
    insert.bindValue(":id_sub",ui->subLE->text());
    insert.bindValue(":id_ed",ui->edLE->text());
    insert.bindValue(":id_mid",ui->MidLE->text());
    insert.bindValue(":id_tip",ui->TipLE->text());
    insert.bindValue(":id_vol",ui->volLE->text());


if(insert.exec()){
    QMessageBox mens;
    mens.setWindowTitle("CADASTRO REALIZADO");
    mens.setText("Cadastro realizado com sucesso");
    mens.exec();
    ui->TituloLE->clear();
    ui->subLE->clear();
    ui->edLE->clear();
    ui->MidLE->clear();
    ui->TipLE->clear();
    ui->volLE->clear();
}
else{
QMessageBox mens;
mens.setWindowTitle("CADASTRO NÃO REALIZADO");
mens.setText("Cadastro não realizado, dados inseridos incorretamente");
mens.exec();
qDebug()<<insert.lastError();
qDebug()<<insert.lastQuery();
ui->TituloLE->clear();
ui->subLE->clear();
ui->edLE->clear();
ui->MidLE->clear();
ui->TipLE->clear();
ui->volLE->clear();
}
}
