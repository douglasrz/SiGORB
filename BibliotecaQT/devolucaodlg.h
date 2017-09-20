#ifndef DEVOLUCAODLG_H
#define DEVOLUCAODLG_H

#include <QDialog>

namespace Ui {
class devolucaoDlg;
}

class devolucaoDlg : public QDialog
{
    Q_OBJECT

public:
    explicit devolucaoDlg(QWidget *parent = 0);
    ~devolucaoDlg();

private slots:
    void buscarLivro();
    void calcularMulta();
    void devolver();


private:
    Ui::devolucaoDlg *ui;
    int valor;
};

#endif // DEVOLUCAODLG_H
