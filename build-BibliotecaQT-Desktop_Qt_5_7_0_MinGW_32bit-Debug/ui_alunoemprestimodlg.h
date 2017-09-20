/********************************************************************************
** Form generated from reading UI file 'alunoemprestimodlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALUNOEMPRESTIMODLG_H
#define UI_ALUNOEMPRESTIMODLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AlunoEmprestimoDLG
{
public:
    QLineEdit *codLivroAl;
    QLineEdit *matAluno;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *BotaoBuscarAl;
    QPushButton *buscButton_2Al;
    QPushButton *pushButton_3;
    QPushButton *CanButtonEmAl;
    QLineEdit *tituloLivroAl;
    QLineEdit *nomeAluno;

    void setupUi(QDialog *AlunoEmprestimoDLG)
    {
        if (AlunoEmprestimoDLG->objectName().isEmpty())
            AlunoEmprestimoDLG->setObjectName(QStringLiteral("AlunoEmprestimoDLG"));
        AlunoEmprestimoDLG->resize(400, 300);
        codLivroAl = new QLineEdit(AlunoEmprestimoDLG);
        codLivroAl->setObjectName(QStringLiteral("codLivroAl"));
        codLivroAl->setGeometry(QRect(20, 60, 131, 20));
        matAluno = new QLineEdit(AlunoEmprestimoDLG);
        matAluno->setObjectName(QStringLiteral("matAluno"));
        matAluno->setEnabled(false);
        matAluno->setGeometry(QRect(20, 140, 131, 20));
        label = new QLabel(AlunoEmprestimoDLG);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 81, 16));
        label_2 = new QLabel(AlunoEmprestimoDLG);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 120, 91, 16));
        label_3 = new QLabel(AlunoEmprestimoDLG);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 120, 71, 16));
        label_4 = new QLabel(AlunoEmprestimoDLG);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 40, 71, 16));
        BotaoBuscarAl = new QPushButton(AlunoEmprestimoDLG);
        BotaoBuscarAl->setObjectName(QStringLiteral("BotaoBuscarAl"));
        BotaoBuscarAl->setGeometry(QRect(20, 90, 75, 23));
        buscButton_2Al = new QPushButton(AlunoEmprestimoDLG);
        buscButton_2Al->setObjectName(QStringLiteral("buscButton_2Al"));
        buscButton_2Al->setEnabled(false);
        buscButton_2Al->setGeometry(QRect(20, 170, 75, 23));
        pushButton_3 = new QPushButton(AlunoEmprestimoDLG);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(false);
        pushButton_3->setGeometry(QRect(80, 270, 111, 23));
        CanButtonEmAl = new QPushButton(AlunoEmprestimoDLG);
        CanButtonEmAl->setObjectName(QStringLiteral("CanButtonEmAl"));
        CanButtonEmAl->setGeometry(QRect(210, 270, 75, 23));
        tituloLivroAl = new QLineEdit(AlunoEmprestimoDLG);
        tituloLivroAl->setObjectName(QStringLiteral("tituloLivroAl"));
        tituloLivroAl->setEnabled(false);
        tituloLivroAl->setGeometry(QRect(180, 60, 201, 20));
        nomeAluno = new QLineEdit(AlunoEmprestimoDLG);
        nomeAluno->setObjectName(QStringLiteral("nomeAluno"));
        nomeAluno->setEnabled(false);
        nomeAluno->setGeometry(QRect(180, 140, 201, 20));

        retranslateUi(AlunoEmprestimoDLG);

        QMetaObject::connectSlotsByName(AlunoEmprestimoDLG);
    } // setupUi

    void retranslateUi(QDialog *AlunoEmprestimoDLG)
    {
        AlunoEmprestimoDLG->setWindowTitle(QApplication::translate("AlunoEmprestimoDLG", "Emp\303\251stimo", 0));
        label->setText(QApplication::translate("AlunoEmprestimoDLG", "C\303\263digo do livro", 0));
        label_2->setText(QApplication::translate("AlunoEmprestimoDLG", "Matr\303\255cula do aluno", 0));
        label_3->setText(QApplication::translate("AlunoEmprestimoDLG", "Nome do aluno", 0));
        label_4->setText(QApplication::translate("AlunoEmprestimoDLG", "T\303\255tulo do livro", 0));
        BotaoBuscarAl->setText(QApplication::translate("AlunoEmprestimoDLG", "Buscar", 0));
        buscButton_2Al->setText(QApplication::translate("AlunoEmprestimoDLG", "Buscar", 0));
        pushButton_3->setText(QApplication::translate("AlunoEmprestimoDLG", "Efetuar empr\303\251stimo", 0));
        CanButtonEmAl->setText(QApplication::translate("AlunoEmprestimoDLG", "Cancelar", 0));
    } // retranslateUi

};

namespace Ui {
    class AlunoEmprestimoDLG: public Ui_AlunoEmprestimoDLG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALUNOEMPRESTIMODLG_H
