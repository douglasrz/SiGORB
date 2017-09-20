#ifndef RENOVARLIVRO_H
#define RENOVARLIVRO_H

#include <QDialog>
#include "connectiondb.h"

namespace Ui {
class RenovarLivro;
}

class RenovarLivro : public QDialog
{
    Q_OBJECT

public:
    explicit RenovarLivro(QWidget *parent = 0);
    ~RenovarLivro();

private slots:
    void buscarLivro();
    void efetuarEmprestimo();
    void radiobutonDevolver();
    void radiobutonRenovar();

private:
    Ui::RenovarLivro *ui;    
    ConnectionDB* con;
};

#endif // RENOVARLIVRO_H
