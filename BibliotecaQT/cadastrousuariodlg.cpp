#include "cadastrousuariodlg.h"
#include "ui_cadastrousuariodlg.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QDebug>
#include <QMessageBox>
#include <QDate>

#include "connectiondb.h"

CadastroUsuarioDLG::CadastroUsuarioDLG(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastroUsuarioDLG)
{
    ui->setupUi(this);

    connect(ui->alunoRarioB, SIGNAL(clicked(bool)), this, SLOT(tipoDeUsuarioAluno()));
    connect(ui->professorRadioB, SIGNAL(clicked(bool)), this, SLOT(tipoDeUsuarioProfessor()));
    connect(ui->cancelarBTN, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(ui->cadastrarBTN, SIGNAL(clicked(bool)), this, SLOT(cadastrar()));

    carregarCursos();
}

CadastroUsuarioDLG::~CadastroUsuarioDLG()
{
    delete ui;
}

void CadastroUsuarioDLG::carregarCursos()
{
    QSqlDatabase db = ConnectionDB::get_bd();
    QString consulta = "SELECT nome FROM curso";

    QSqlQuery qry = db.exec(consulta);

    while(qry.next())
    {
        ui->cursoCBX->addItem(qry.value(0).toString());
    }

    qry.clear();

}

void CadastroUsuarioDLG::tipoDeUsuarioAluno()
{
    ui->informacaoLB->setText("Matrícula*");
    ui->informacaoLE->setText("");
    ui->cursoLB->setVisible(true);
    ui->cursoCBX->setVisible(true);
}

void CadastroUsuarioDLG::tipoDeUsuarioProfessor()
{
    ui->informacaoLB->setText("Siape*");
    ui->informacaoLE->setText("");
    ui->cursoLB->setVisible(false);
    ui->cursoCBX->setVisible(false);
}

void CadastroUsuarioDLG::cadastrar()
{

  /*
    Usuário
    +--------------------+-------------+------+-----+---------+----------------+
    | Field              | Type        | Null | Key | Default | Extra          |
    +--------------------+-------------+------+-----+---------+----------------+
    | id                 | int(11)     | NO   | PRI | NULL    | auto_increment |
    | nome               | varchar(60) | NO   |     | NULL    |                |
    | email              | varchar(50) | NO   |     | NULL    |                |
    | telefone           | varchar(45) | YES  |     | NULL    |                |
    | data_de_nascimento | date        | NO   |     | NULL    |                |
    | cidade             | varchar(50) | NO   |     | NULL    |                |
    | uf                 | varchar(2)  | YES  |     | NULL    |                |
    | rua                | varchar(90) | YES  |     | NULL    |                |
    | bairro             | varchar(50) | YES  |     | NULL    |                |
    | num_casa           | varchar(15) | YES  |     | NULL    |                |
    +--------------------+-------------+------+-----+---------+----------------+

    Aluno
    +------------+---------+------+-----+---------+-------+
    | Field      | Type    | Null | Key | Default | Extra |
    +------------+---------+------+-----+---------+-------+
    | id_usuario | int(11) | YES  | MUL | NULL    |       |
    | matricula  | int(11) | NO   | PRI | NULL    |       |
    | id_curso   | int(11) | YES  | MUL | NULL    |       |
    +------------+---------+------+-----+---------+-------+

    Professor
    +------------+---------+------+-----+---------+-------+
    | Field      | Type    | Null | Key | Default | Extra |
    +------------+---------+------+-----+---------+-------+
    | id_usuario | int(11) | YES  | MUL | NULL    |       |
    | siape      | int(11) | NO   |     | NULL    |       |
    +------------+---------+------+-----+---------+-------+
   */


    QSqlDatabase bd = ConnectionDB::get_bd();
    QSqlQuery* qry = new QSqlQuery(bd);

    QString consulta;


    if(ui->nomeLE->text() == "" || ui->emailLE->text() == "" || ui->dataNascimentoDATE->text() == "" || ui->cidadeLE->text() == "" || ui->informacaoLE->text() == "")
    {
        QMessageBox::warning(this, tr("Erro de inserção"),tr("Falta informações"),QMessageBox::Ok);
    }
    else
    {
        //Verificar se o email já esta cadastrado
        consulta.append("SELECT nome FROM usuario WHERE email = \'" + ui->emailLE->text() + "\'");
        if(!qry->exec(consulta))
        {
            qDebug() << qry->lastQuery();
            qDebug() << qry->lastError();
        }
        else
        {
            if(qry->next())
            {
                QMessageBox::information(this, tr("Erro no cadastro"), tr("Email já cadastrado"), QMessageBox::Ok);
            }
            else
            {
                /* INSERINDO PRIMEIRO NA TABELA DE USUARIO
                 * PARA DEPOIS ASSOCIAR ESSE USUARIO
                 * A UM PROFESSOR OU ALUNO
                 */
                consulta.clear();
                qry->clear();

                QString nome = '\'' + ui->nomeLE->text() + '\'';
                QString email = '\'' + ui->emailLE->text() + '\'';
                QString telefone = '\'' + ui->telefoneLE->text() + '\'';

                QDate data = ui->dataNascimentoDATE->date();
                QString dataString = "\'" + data.toString("yyyy-MM-dd") + "\'";

                QString cidade = '\'' + ui->cidadeLE->text() + '\'';
                QString uf = '\'' + ui->ufLE->text() + '\'';
                QString rua = '\'' + ui->ruaLE->text() + '\'';
                QString bairro = '\'' + ui->bairroLE->text() + '\'';
                QString num_casa = '\'' + ui->numeroDaCasaLE->text() + '\'';

                consulta.append("INSERT INTO usuario (nome, email, telefone, data_de_nascimento, cidade, uf, rua, bairro, num_casa) VALUES (");
                consulta.append(nome + ',' + email + ',' + telefone + ',' + dataString + ',' + cidade + ',' + uf + ',' + rua + ',' + bairro + ',' + num_casa + ")");



                if(qry->exec(consulta))
                {
                    consulta.clear();
                    qry->clear();

                    //Agora é preciso do id do usuario que acabou de ser inserido no banco
                    consulta.append("SELECT id FROM usuario WHERE email = \'" + ui->emailLE->text() + "\'");

                    if(!qry->exec(consulta))
                    {
                        qDebug() << qry->lastQuery();
                        qDebug() << qry->lastError();
                    }
                    else
                    {
                        //Pegando o id
                        qry->next();
                        QString id_usuario = qry->value(0).toString();

                        consulta.clear();
                        qry->clear();

                        if(ui->alunoRarioB->isChecked())
                        {
                            //Se for um aluno que esta sendo cadastrado execute a inserção na tabela de alunos

                            //Pegando o id do curso que esse aluno pertence
                            consulta.append("SELECT id FROM curso WHERE nome = \'" + ui->cursoCBX->currentText() + "\'");

                            if(!qry->exec(consulta))
                            {
                                qDebug() << qry->lastQuery();
                                qDebug() << qry->lastError();
                            }
                            else
                            {
                                //Pegando o id do curso
                                qry->next();
                                QString id_curso = qry->value(0).toString();

                                consulta.clear();
                                qry->clear();

                                consulta.append("INSERT INTO aluno (id_usuario, matricula, id_curso) VALUES (");
                                consulta.append(id_usuario + ",");
                                consulta.append(ui->informacaoLE->text() + ", ");
                                consulta.append(id_curso + ")");


                                if(!qry->exec(consulta))
                                {
                                    qDebug() << qry->lastQuery();
                                    qDebug() << qry->lastError();
                                }
                                else
                                {
                                    const QString mensagem = "Aluno " + ui->nomeLE->text() + " cadastrado.";
                                    QMessageBox::information(this, tr("Cadastro efetuado"), mensagem, QMessageBox::Ok);
                                }

                            }
                        }
                        else if(ui->professorRadioB->isChecked())
                        {
                            consulta.append("INSERT INTO professor (id_usuario, siape) VALUES (");
                            consulta.append("\'" + id_usuario + "\', " +
                                            "\'" + ui->informacaoLE->text() + "\')");

                            if(!qry->exec(consulta))
                            {
                                qDebug() << qry->lastQuery();
                                qDebug() << qry->lastError();
                            }
                            else
                            {
                                const QString mensagem = "Professor " + ui->nomeLE->text() + " cadastrado.";
                                QMessageBox::information(this, tr("Cadastro efetuado"), mensagem, QMessageBox::Ok);
                            }
                        }

                    }

                }
                else{
                    qDebug() << qry->lastQuery();
                    qDebug() << qry->lastError();
                }
            }
        }


        consulta.clear();
        qry->clear();

    }
}
