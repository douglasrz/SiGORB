/********************************************************************************
** Form generated from reading UI file 'cadastropublicacaodlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADASTROPUBLICACAODLG_H
#define UI_CADASTROPUBLICACAODLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CadastroPublicacaoDLG
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *TituloLE;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *subLE;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *edLE;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *MidLE;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *TipLE;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *volLE;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *cad;
    QPushButton *can;

    void setupUi(QDialog *CadastroPublicacaoDLG)
    {
        if (CadastroPublicacaoDLG->objectName().isEmpty())
            CadastroPublicacaoDLG->setObjectName(QStringLiteral("CadastroPublicacaoDLG"));
        CadastroPublicacaoDLG->resize(400, 300);
        verticalLayout = new QVBoxLayout(CadastroPublicacaoDLG);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(CadastroPublicacaoDLG);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(CadastroPublicacaoDLG);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        TituloLE = new QLineEdit(CadastroPublicacaoDLG);
        TituloLE->setObjectName(QStringLiteral("TituloLE"));

        horizontalLayout->addWidget(TituloLE);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(CadastroPublicacaoDLG);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        subLE = new QLineEdit(CadastroPublicacaoDLG);
        subLE->setObjectName(QStringLiteral("subLE"));

        horizontalLayout_2->addWidget(subLE);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(CadastroPublicacaoDLG);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        edLE = new QLineEdit(CadastroPublicacaoDLG);
        edLE->setObjectName(QStringLiteral("edLE"));

        horizontalLayout_3->addWidget(edLE);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(CadastroPublicacaoDLG);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        MidLE = new QLineEdit(CadastroPublicacaoDLG);
        MidLE->setObjectName(QStringLiteral("MidLE"));

        horizontalLayout_4->addWidget(MidLE);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(CadastroPublicacaoDLG);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        TipLE = new QLineEdit(CadastroPublicacaoDLG);
        TipLE->setObjectName(QStringLiteral("TipLE"));

        horizontalLayout_5->addWidget(TipLE);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(CadastroPublicacaoDLG);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        volLE = new QLineEdit(CadastroPublicacaoDLG);
        volLE->setObjectName(QStringLiteral("volLE"));

        horizontalLayout_6->addWidget(volLE);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        cad = new QPushButton(CadastroPublicacaoDLG);
        cad->setObjectName(QStringLiteral("cad"));

        horizontalLayout_7->addWidget(cad);

        can = new QPushButton(CadastroPublicacaoDLG);
        can->setObjectName(QStringLiteral("can"));

        horizontalLayout_7->addWidget(can);


        verticalLayout->addLayout(horizontalLayout_7);


        retranslateUi(CadastroPublicacaoDLG);

        QMetaObject::connectSlotsByName(CadastroPublicacaoDLG);
    } // setupUi

    void retranslateUi(QDialog *CadastroPublicacaoDLG)
    {
        CadastroPublicacaoDLG->setWindowTitle(QApplication::translate("CadastroPublicacaoDLG", "Dialog", 0));
        label->setText(QApplication::translate("CadastroPublicacaoDLG", "Cadastro de publica\303\247\303\243o", 0));
        label_2->setText(QApplication::translate("CadastroPublicacaoDLG", "T\303\255tulo:", 0));
        label_3->setText(QApplication::translate("CadastroPublicacaoDLG", "Subt\303\255tulo:", 0));
        label_4->setText(QApplication::translate("CadastroPublicacaoDLG", "Editora:", 0));
        label_5->setText(QApplication::translate("CadastroPublicacaoDLG", "M\303\255dia:", 0));
        label_6->setText(QApplication::translate("CadastroPublicacaoDLG", "Tipo de obra:", 0));
        label_7->setText(QApplication::translate("CadastroPublicacaoDLG", "Volume:", 0));
        cad->setText(QApplication::translate("CadastroPublicacaoDLG", "Cadastrar", 0));
        can->setText(QApplication::translate("CadastroPublicacaoDLG", "Cancelar", 0));
    } // retranslateUi

};

namespace Ui {
    class CadastroPublicacaoDLG: public Ui_CadastroPublicacaoDLG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADASTROPUBLICACAODLG_H
