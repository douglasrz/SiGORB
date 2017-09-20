#include "ajudadlg.h"
#include "ui_ajudadlg.h"

ajudaDlg::ajudaDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajudaDlg)
{
    ui->setupUi(this);
}

ajudaDlg::~ajudaDlg()
{
    delete ui;
}
