/********************************************************************************
** Form generated from reading UI file 'cadastrousuariodlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADASTROUSUARIODLG_H
#define UI_CADASTROUSUARIODLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CadastroUsuarioDLG
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *infP;
    QHBoxLayout *horizontalLayout;
    QLabel *nomeLB;
    QLineEdit *nomeLE;
    QHBoxLayout *horizontalLayout_2;
    QLabel *emailLB;
    QLineEdit *emailLE;
    QHBoxLayout *horizontalLayout_3;
    QLabel *telefoneLB;
    QLineEdit *telefoneLE;
    QHBoxLayout *horizontalLayout_4;
    QLabel *dataNascimentoLB;
    QSpacerItem *horizontalSpacer_4;
    QDateEdit *dataNascimentoDATE;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *infC;
    QHBoxLayout *horizontalLayout_5;
    QLabel *cidadeLB;
    QLineEdit *cidadeLE;
    QHBoxLayout *horizontalLayout_6;
    QLabel *ufLB;
    QLineEdit *ufLE;
    QHBoxLayout *horizontalLayout_7;
    QLabel *ruaLB;
    QLineEdit *ruaLE;
    QHBoxLayout *horizontalLayout_8;
    QLabel *bairroLB;
    QLineEdit *bairroLE;
    QHBoxLayout *horizontalLayout_9;
    QLabel *numeroDaCasaLB;
    QLineEdit *numeroDaCasaLE;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_10;
    QRadioButton *alunoRarioB;
    QRadioButton *professorRadioB;
    QHBoxLayout *horizontalLayout_12;
    QLabel *informacaoLB;
    QLineEdit *informacaoLE;
    QHBoxLayout *horizontalLayout_13;
    QLabel *cursoLB;
    QComboBox *cursoCBX;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *cadastrarBTN;
    QPushButton *cancelarBTN;
    QLabel *label;

    void setupUi(QDialog *CadastroUsuarioDLG)
    {
        if (CadastroUsuarioDLG->objectName().isEmpty())
            CadastroUsuarioDLG->setObjectName(QStringLiteral("CadastroUsuarioDLG"));
        CadastroUsuarioDLG->resize(600, 350);
        CadastroUsuarioDLG->setMinimumSize(QSize(600, 350));
        CadastroUsuarioDLG->setMaximumSize(QSize(600, 350));
        gridLayout = new QGridLayout(CadastroUsuarioDLG);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        infP = new QLabel(CadastroUsuarioDLG);
        infP->setObjectName(QStringLiteral("infP"));
        infP->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(infP);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        nomeLB = new QLabel(CadastroUsuarioDLG);
        nomeLB->setObjectName(QStringLiteral("nomeLB"));

        horizontalLayout->addWidget(nomeLB);

        nomeLE = new QLineEdit(CadastroUsuarioDLG);
        nomeLE->setObjectName(QStringLiteral("nomeLE"));

        horizontalLayout->addWidget(nomeLE);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        emailLB = new QLabel(CadastroUsuarioDLG);
        emailLB->setObjectName(QStringLiteral("emailLB"));

        horizontalLayout_2->addWidget(emailLB);

        emailLE = new QLineEdit(CadastroUsuarioDLG);
        emailLE->setObjectName(QStringLiteral("emailLE"));

        horizontalLayout_2->addWidget(emailLE);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        telefoneLB = new QLabel(CadastroUsuarioDLG);
        telefoneLB->setObjectName(QStringLiteral("telefoneLB"));

        horizontalLayout_3->addWidget(telefoneLB);

        telefoneLE = new QLineEdit(CadastroUsuarioDLG);
        telefoneLE->setObjectName(QStringLiteral("telefoneLE"));

        horizontalLayout_3->addWidget(telefoneLE);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        dataNascimentoLB = new QLabel(CadastroUsuarioDLG);
        dataNascimentoLB->setObjectName(QStringLiteral("dataNascimentoLB"));

        horizontalLayout_4->addWidget(dataNascimentoLB);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        dataNascimentoDATE = new QDateEdit(CadastroUsuarioDLG);
        dataNascimentoDATE->setObjectName(QStringLiteral("dataNascimentoDATE"));
        dataNascimentoDATE->setCalendarPopup(true);

        horizontalLayout_4->addWidget(dataNascimentoDATE);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_5->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        infC = new QLabel(CadastroUsuarioDLG);
        infC->setObjectName(QStringLiteral("infC"));
        infC->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(infC);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        cidadeLB = new QLabel(CadastroUsuarioDLG);
        cidadeLB->setObjectName(QStringLiteral("cidadeLB"));

        horizontalLayout_5->addWidget(cidadeLB);

        cidadeLE = new QLineEdit(CadastroUsuarioDLG);
        cidadeLE->setObjectName(QStringLiteral("cidadeLE"));

        horizontalLayout_5->addWidget(cidadeLE);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        ufLB = new QLabel(CadastroUsuarioDLG);
        ufLB->setObjectName(QStringLiteral("ufLB"));

        horizontalLayout_6->addWidget(ufLB);

        ufLE = new QLineEdit(CadastroUsuarioDLG);
        ufLE->setObjectName(QStringLiteral("ufLE"));

        horizontalLayout_6->addWidget(ufLE);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        ruaLB = new QLabel(CadastroUsuarioDLG);
        ruaLB->setObjectName(QStringLiteral("ruaLB"));

        horizontalLayout_7->addWidget(ruaLB);

        ruaLE = new QLineEdit(CadastroUsuarioDLG);
        ruaLE->setObjectName(QStringLiteral("ruaLE"));

        horizontalLayout_7->addWidget(ruaLE);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        bairroLB = new QLabel(CadastroUsuarioDLG);
        bairroLB->setObjectName(QStringLiteral("bairroLB"));

        horizontalLayout_8->addWidget(bairroLB);

        bairroLE = new QLineEdit(CadastroUsuarioDLG);
        bairroLE->setObjectName(QStringLiteral("bairroLE"));

        horizontalLayout_8->addWidget(bairroLE);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        numeroDaCasaLB = new QLabel(CadastroUsuarioDLG);
        numeroDaCasaLB->setObjectName(QStringLiteral("numeroDaCasaLB"));

        horizontalLayout_9->addWidget(numeroDaCasaLB);

        numeroDaCasaLE = new QLineEdit(CadastroUsuarioDLG);
        numeroDaCasaLE->setObjectName(QStringLiteral("numeroDaCasaLE"));

        horizontalLayout_9->addWidget(numeroDaCasaLE);


        verticalLayout_2->addLayout(horizontalLayout_9);


        verticalLayout_5->addLayout(verticalLayout_2);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        alunoRarioB = new QRadioButton(CadastroUsuarioDLG);
        alunoRarioB->setObjectName(QStringLiteral("alunoRarioB"));
        alunoRarioB->setChecked(true);

        horizontalLayout_10->addWidget(alunoRarioB);

        professorRadioB = new QRadioButton(CadastroUsuarioDLG);
        professorRadioB->setObjectName(QStringLiteral("professorRadioB"));

        horizontalLayout_10->addWidget(professorRadioB);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        informacaoLB = new QLabel(CadastroUsuarioDLG);
        informacaoLB->setObjectName(QStringLiteral("informacaoLB"));

        horizontalLayout_12->addWidget(informacaoLB);

        informacaoLE = new QLineEdit(CadastroUsuarioDLG);
        informacaoLE->setObjectName(QStringLiteral("informacaoLE"));

        horizontalLayout_12->addWidget(informacaoLE);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        cursoLB = new QLabel(CadastroUsuarioDLG);
        cursoLB->setObjectName(QStringLiteral("cursoLB"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cursoLB->sizePolicy().hasHeightForWidth());
        cursoLB->setSizePolicy(sizePolicy);

        horizontalLayout_13->addWidget(cursoLB);

        cursoCBX = new QComboBox(CadastroUsuarioDLG);
        cursoCBX->setObjectName(QStringLiteral("cursoCBX"));

        horizontalLayout_13->addWidget(cursoCBX);


        verticalLayout_3->addLayout(horizontalLayout_13);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        cadastrarBTN = new QPushButton(CadastroUsuarioDLG);
        cadastrarBTN->setObjectName(QStringLiteral("cadastrarBTN"));

        horizontalLayout_11->addWidget(cadastrarBTN);

        cancelarBTN = new QPushButton(CadastroUsuarioDLG);
        cancelarBTN->setObjectName(QStringLiteral("cancelarBTN"));

        horizontalLayout_11->addWidget(cancelarBTN);


        verticalLayout_3->addLayout(horizontalLayout_11);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);

        label = new QLabel(CadastroUsuarioDLG);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 2);

        label->raise();

        retranslateUi(CadastroUsuarioDLG);

        QMetaObject::connectSlotsByName(CadastroUsuarioDLG);
    } // setupUi

    void retranslateUi(QDialog *CadastroUsuarioDLG)
    {
        CadastroUsuarioDLG->setWindowTitle(QApplication::translate("CadastroUsuarioDLG", "Cadastro de Usu\303\241rio", 0));
        infP->setText(QApplication::translate("CadastroUsuarioDLG", "Informa\303\247\303\265es pessoais", 0));
        nomeLB->setText(QApplication::translate("CadastroUsuarioDLG", "Nome*", 0));
        emailLB->setText(QApplication::translate("CadastroUsuarioDLG", "E-mail*", 0));
        telefoneLB->setText(QApplication::translate("CadastroUsuarioDLG", "Telefone", 0));
        dataNascimentoLB->setText(QApplication::translate("CadastroUsuarioDLG", "Data de Nascimento*", 0));
        infC->setText(QApplication::translate("CadastroUsuarioDLG", "Informa\303\247\303\265es de contato", 0));
        cidadeLB->setText(QApplication::translate("CadastroUsuarioDLG", "Cidade*", 0));
        ufLB->setText(QApplication::translate("CadastroUsuarioDLG", "UF", 0));
        ruaLB->setText(QApplication::translate("CadastroUsuarioDLG", "Rua", 0));
        bairroLB->setText(QApplication::translate("CadastroUsuarioDLG", "Bairro", 0));
        numeroDaCasaLB->setText(QApplication::translate("CadastroUsuarioDLG", "N\303\272mero da Casa", 0));
        alunoRarioB->setText(QApplication::translate("CadastroUsuarioDLG", "Aluno", 0));
        professorRadioB->setText(QApplication::translate("CadastroUsuarioDLG", "Professor", 0));
        informacaoLB->setText(QApplication::translate("CadastroUsuarioDLG", "Matr\303\255cula*", 0));
        cursoLB->setText(QApplication::translate("CadastroUsuarioDLG", "Curso", 0));
        cadastrarBTN->setText(QApplication::translate("CadastroUsuarioDLG", "Cadastrar", 0));
        cancelarBTN->setText(QApplication::translate("CadastroUsuarioDLG", "Cancelar", 0));
        label->setText(QApplication::translate("CadastroUsuarioDLG", "* (Obrigat\303\263rio)", 0));
    } // retranslateUi

};

namespace Ui {
    class CadastroUsuarioDLG: public Ui_CadastroUsuarioDLG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADASTROUSUARIODLG_H
