#include "devolucaodlg.h"
#include "ui_devolucaodlg.h"

devolucaoDlg::devolucaoDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::devolucaoDlg)
{
    ui->setupUi(this);

    connect(ui->buscarBtn, SIGNAL(clicked()), this, SLOT(buscarLivro()));
    connect(ui->cancelarBtn, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->devolverBtn, SIGNAL(clicked()), this, SLOT(devolver()));
}

devolucaoDlg::~devolucaoDlg()
{
    delete ui;
}
void devolucaoDlg::buscarLivro()
{

}
void devolucaoDlg::devolver(){}
void devolucaoDlg::calcularMulta(){}
