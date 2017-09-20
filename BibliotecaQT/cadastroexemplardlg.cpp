#include "cadastroexemplardlg.h"
#include "ui_cadastroexemplardlg.h"

#include "connectiondb.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>


CadastroExemplarDLG::CadastroExemplarDLG(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastroExemplarDLG)
{
    ui->setupUi(this);
    connect(ui->cadastrarBTN, SIGNAL(clicked(bool)), this, SLOT(cadastrar()));
    connect(ui->cancelarBTN, SIGNAL(clicked(bool)), this, SLOT(close()));
}

CadastroExemplarDLG::~CadastroExemplarDLG()
{
    delete ui;
}

void CadastroExemplarDLG::cadastrar()
{
    /*
     *  +---------------+-------------+------+-----+---------+----------------+
        | Field         | Type        | Null | Key | Default | Extra          |
        +---------------+-------------+------+-----+---------+----------------+
        | id            | int(11)     | NO   | PRI | NULL    | auto_increment |
        | id_publicacao | int(11)     | YES  | MUL | NULL    |                |
        | isbn          | int(11)     | NO   |     | NULL    |                |
        | condicao      | varchar(45) | YES  |     | NULL    |                |
        | data_entrada  | date        | NO   |     | NULL    |                |
        | ano_de_edicao | int(11)     | YES  |     | NULL    |                |
        | cativo        | tinyint(1)  | YES  |     | NULL    |                |
        | qtd_faciculos | int(11)     | YES  |     | NULL    |                |
        +---------------+-------------+------+-----+---------+----------------+
     */
    QSqlDatabase bd = ConnectionDB::get_bd();
    QSqlQuery *qry = new QSqlQuery(bd);
    QString consulta;

    consulta.append("SELECT * FROM publicacao WHERE id = " + ui->idPublicacaoSB->text() + "");

    if(!qry->exec(consulta))
    {
        qDebug() << qry->lastQuery();
        qDebug() << qry->lastError();
    }
    else
    {
        if(!qry->next())
        {
            QMessageBox::information(this, tr("Erro"), tr("Publicação não encontrada."), QMessageBox::Ok);
            qDebug() << "Publicação não encontrada";
        }
        else
        {
            consulta.clear();
            qry->clear();

            //--------------------------------------------------------------------------------------------
            consulta.append("SELECT * FROM exemplar WHERE isbn = " + ui->isbnSB->text() + "");
            if(!qry->exec(consulta))
            {
                qDebug() << qry->lastQuery();
                qDebug() << qry->lastError();
            }
            else
            {
                if(qry->next())
                {
                    QMessageBox::information(this, tr("Erro"), tr("ISBN já cadastrado."), QMessageBox::Ok);
                    return;
                }
            }
            //--------------------------------------------------------------------------------------------

            consulta.clear();
            qry->clear();

            consulta.append("INSERT INTO exemplar (id_publicacao, isbn, data_entrada, ano_de_edicao, cativo, qtd_faciculos) ");
            consulta.append("VALUES (" + ui->idPublicacaoSB->text() + ", ");
            consulta.append(ui->isbnSB->text() + ", ");
            consulta.append("'" + QDate::currentDate().toString("yyyy-MM-dd") + "', ");
            consulta.append(ui->anoEdicaoSB->text()  + ", ");

            if(ui->cativoCB->isChecked())
            {
                consulta.append(" 1, ");
            }
            else
            {
                consulta.append(" 0, ");
            }

            consulta.append(ui->quantidadeFacSB->text() + ")");

            qDebug() << ui->cativoCB->isChecked() ;

            if(!qry->exec(consulta))
            {
                qDebug() << qry->lastQuery();
                qDebug() << qry->lastError();
            }
            else
            {
                QMessageBox::information(this, tr("Cadastro efetuado"), tr("Exemplar cadastrado"), QMessageBox::Ok);
                ui->anoEdicaoSB->setValue(0);
                ui->cativoCB->setChecked(false);
                ui->idPublicacaoSB->setValue(0);
                ui->isbnSB->setValue(0);
                ui->quantidadeFacSB->setValue(0);
            }

        }
    }
}
