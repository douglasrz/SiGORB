/********************************************************************************
** Form generated from reading UI file 'professoremprestimodlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFESSOREMPRESTIMODLG_H
#define UI_PROFESSOREMPRESTIMODLG_H

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

class Ui_ProfessorEmprestimoDLG
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *empButtonProf1;
    QPushButton *empButtonProf2;
    QPushButton *efetuarEmprestimoButton_3;
    QPushButton *ButtonCancelarEmpP;
    QLineEdit *tituloLivroPr;
    QLineEdit *nomeProf;

    void setupUi(QDialog *ProfessorEmprestimoDLG)
    {
        if (ProfessorEmprestimoDLG->objectName().isEmpty())
            ProfessorEmprestimoDLG->setObjectName(QStringLiteral("ProfessorEmprestimoDLG"));
        ProfessorEmprestimoDLG->resize(450, 300);
        lineEdit = new QLineEdit(ProfessorEmprestimoDLG);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 70, 151, 20));
        label = new QLabel(ProfessorEmprestimoDLG);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 81, 16));
        label_2 = new QLabel(ProfessorEmprestimoDLG);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 130, 141, 16));
        lineEdit_2 = new QLineEdit(ProfessorEmprestimoDLG);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(10, 150, 151, 20));
        label_3 = new QLabel(ProfessorEmprestimoDLG);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 50, 71, 16));
        label_4 = new QLabel(ProfessorEmprestimoDLG);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 130, 91, 16));
        empButtonProf1 = new QPushButton(ProfessorEmprestimoDLG);
        empButtonProf1->setObjectName(QStringLiteral("empButtonProf1"));
        empButtonProf1->setGeometry(QRect(10, 100, 75, 23));
        empButtonProf2 = new QPushButton(ProfessorEmprestimoDLG);
        empButtonProf2->setObjectName(QStringLiteral("empButtonProf2"));
        empButtonProf2->setEnabled(false);
        empButtonProf2->setGeometry(QRect(10, 180, 75, 23));
        efetuarEmprestimoButton_3 = new QPushButton(ProfessorEmprestimoDLG);
        efetuarEmprestimoButton_3->setObjectName(QStringLiteral("efetuarEmprestimoButton_3"));
        efetuarEmprestimoButton_3->setEnabled(false);
        efetuarEmprestimoButton_3->setGeometry(QRect(120, 270, 111, 23));
        ButtonCancelarEmpP = new QPushButton(ProfessorEmprestimoDLG);
        ButtonCancelarEmpP->setObjectName(QStringLiteral("ButtonCancelarEmpP"));
        ButtonCancelarEmpP->setGeometry(QRect(260, 270, 75, 23));
        tituloLivroPr = new QLineEdit(ProfessorEmprestimoDLG);
        tituloLivroPr->setObjectName(QStringLiteral("tituloLivroPr"));
        tituloLivroPr->setEnabled(false);
        tituloLivroPr->setGeometry(QRect(190, 70, 241, 20));
        tituloLivroPr->setMinimumSize(QSize(241, 0));
        nomeProf = new QLineEdit(ProfessorEmprestimoDLG);
        nomeProf->setObjectName(QStringLiteral("nomeProf"));
        nomeProf->setEnabled(false);
        nomeProf->setGeometry(QRect(190, 150, 241, 20));
        lineEdit->raise();
        label->raise();
        label_2->raise();
        lineEdit_2->raise();
        label_3->raise();
        label_4->raise();
        empButtonProf1->raise();
        empButtonProf2->raise();
        efetuarEmprestimoButton_3->raise();
        ButtonCancelarEmpP->raise();
        nomeProf->raise();
        tituloLivroPr->raise();

        retranslateUi(ProfessorEmprestimoDLG);

        QMetaObject::connectSlotsByName(ProfessorEmprestimoDLG);
    } // setupUi

    void retranslateUi(QDialog *ProfessorEmprestimoDLG)
    {
        ProfessorEmprestimoDLG->setWindowTitle(QApplication::translate("ProfessorEmprestimoDLG", "Empr\303\251stimo", 0));
        label->setText(QApplication::translate("ProfessorEmprestimoDLG", "C\303\263digo do Livro", 0));
        label_2->setText(QApplication::translate("ProfessorEmprestimoDLG", "Matr\303\255cula Siape do professor", 0));
        label_3->setText(QApplication::translate("ProfessorEmprestimoDLG", "T\303\255tulo do Livro", 0));
        label_4->setText(QApplication::translate("ProfessorEmprestimoDLG", "Nome do professor", 0));
        empButtonProf1->setText(QApplication::translate("ProfessorEmprestimoDLG", "Buscar", 0));
        empButtonProf2->setText(QApplication::translate("ProfessorEmprestimoDLG", "Buscar", 0));
        efetuarEmprestimoButton_3->setText(QApplication::translate("ProfessorEmprestimoDLG", "Efetuar empr\303\251stimo", 0));
        ButtonCancelarEmpP->setText(QApplication::translate("ProfessorEmprestimoDLG", "Cancelar", 0));
    } // retranslateUi

};

namespace Ui {
    class ProfessorEmprestimoDLG: public Ui_ProfessorEmprestimoDLG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFESSOREMPRESTIMODLG_H
