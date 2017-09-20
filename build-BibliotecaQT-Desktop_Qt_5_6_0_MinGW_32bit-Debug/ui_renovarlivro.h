/********************************************************************************
** Form generated from reading UI file 'renovarlivro.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENOVARLIVRO_H
#define UI_RENOVARLIVRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_RenovarLivro
{
public:
    QLineEdit *idLivro;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *tituloLivro;
    QLineEdit *devolver;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *qtdReno;
    QLineEdit *nvdevolucao;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *usuarioNome;
    QPushButton *efetuarEmprestimo;
    QPushButton *cancelar;
    QPushButton *buscarLivro;
    QRadioButton *devolverB;
    QRadioButton *renovar;

    void setupUi(QDialog *RenovarLivro)
    {
        if (RenovarLivro->objectName().isEmpty())
            RenovarLivro->setObjectName(QStringLiteral("RenovarLivro"));
        RenovarLivro->resize(400, 300);
        idLivro = new QLineEdit(RenovarLivro);
        idLivro->setObjectName(QStringLiteral("idLivro"));
        idLivro->setGeometry(QRect(20, 60, 121, 20));
        label = new QLabel(RenovarLivro);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 51, 16));
        label_2 = new QLabel(RenovarLivro);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 40, 71, 16));
        tituloLivro = new QLineEdit(RenovarLivro);
        tituloLivro->setObjectName(QStringLiteral("tituloLivro"));
        tituloLivro->setEnabled(false);
        tituloLivro->setGeometry(QRect(170, 60, 211, 20));
        devolver = new QLineEdit(RenovarLivro);
        devolver->setObjectName(QStringLiteral("devolver"));
        devolver->setEnabled(false);
        devolver->setGeometry(QRect(20, 200, 121, 20));
        label_3 = new QLabel(RenovarLivro);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 180, 91, 16));
        label_4 = new QLabel(RenovarLivro);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 130, 131, 16));
        qtdReno = new QLineEdit(RenovarLivro);
        qtdReno->setObjectName(QStringLiteral("qtdReno"));
        qtdReno->setEnabled(false);
        qtdReno->setGeometry(QRect(20, 150, 121, 20));
        nvdevolucao = new QLineEdit(RenovarLivro);
        nvdevolucao->setObjectName(QStringLiteral("nvdevolucao"));
        nvdevolucao->setEnabled(false);
        nvdevolucao->setGeometry(QRect(20, 250, 121, 20));
        label_5 = new QLabel(RenovarLivro);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 230, 121, 20));
        label_6 = new QLabel(RenovarLivro);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(170, 130, 47, 13));
        usuarioNome = new QLineEdit(RenovarLivro);
        usuarioNome->setObjectName(QStringLiteral("usuarioNome"));
        usuarioNome->setEnabled(false);
        usuarioNome->setGeometry(QRect(170, 150, 211, 20));
        efetuarEmprestimo = new QPushButton(RenovarLivro);
        efetuarEmprestimo->setObjectName(QStringLiteral("efetuarEmprestimo"));
        efetuarEmprestimo->setGeometry(QRect(180, 250, 101, 23));
        cancelar = new QPushButton(RenovarLivro);
        cancelar->setObjectName(QStringLiteral("cancelar"));
        cancelar->setGeometry(QRect(310, 250, 75, 23));
        buscarLivro = new QPushButton(RenovarLivro);
        buscarLivro->setObjectName(QStringLiteral("buscarLivro"));
        buscarLivro->setGeometry(QRect(20, 90, 75, 23));
        devolverB = new QRadioButton(RenovarLivro);
        devolverB->setObjectName(QStringLiteral("devolverB"));
        devolverB->setEnabled(true);
        devolverB->setGeometry(QRect(170, 200, 82, 17));
        devolverB->setMouseTracking(true);
        renovar = new QRadioButton(RenovarLivro);
        renovar->setObjectName(QStringLiteral("renovar"));
        renovar->setGeometry(QRect(250, 200, 82, 17));

        retranslateUi(RenovarLivro);

        QMetaObject::connectSlotsByName(RenovarLivro);
    } // setupUi

    void retranslateUi(QDialog *RenovarLivro)
    {
        RenovarLivro->setWindowTitle(QApplication::translate("RenovarLivro", "Renovar emr\303\251stimo", 0));
        label->setText(QApplication::translate("RenovarLivro", "ID do livro", 0));
        label_2->setText(QApplication::translate("RenovarLivro", "T\303\255tulo do livro", 0));
        label_3->setText(QApplication::translate("RenovarLivro", "Data de devolver", 0));
        label_4->setText(QApplication::translate("RenovarLivro", "Quantidade de renova\303\247\303\243o", 0));
        label_5->setText(QApplication::translate("RenovarLivro", "Multa", 0));
        label_6->setText(QApplication::translate("RenovarLivro", "Usu\303\241rio", 0));
        efetuarEmprestimo->setText(QApplication::translate("RenovarLivro", "Efetuar renova\303\247\303\243o", 0));
        cancelar->setText(QApplication::translate("RenovarLivro", "Cancelar", 0));
        buscarLivro->setText(QApplication::translate("RenovarLivro", "Buscar", 0));
        devolverB->setText(QApplication::translate("RenovarLivro", "Devolver", 0));
        renovar->setText(QApplication::translate("RenovarLivro", "Renovar", 0));
    } // retranslateUi

};

namespace Ui {
    class RenovarLivro: public Ui_RenovarLivro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENOVARLIVRO_H
