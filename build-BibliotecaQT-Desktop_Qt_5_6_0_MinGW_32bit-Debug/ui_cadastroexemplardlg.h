/********************************************************************************
** Form generated from reading UI file 'cadastroexemplardlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADASTROEXEMPLARDLG_H
#define UI_CADASTROEXEMPLARDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CadastroExemplarDLG
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *idPublicacaoLB;
    QSpinBox *idPublicacaoSB;
    QHBoxLayout *horizontalLayout_2;
    QLabel *isbnLB;
    QSpinBox *isbnSB;
    QHBoxLayout *horizontalLayout_4;
    QLabel *quantidadeFacLB;
    QSpinBox *quantidadeFacSB;
    QHBoxLayout *horizontalLayout_5;
    QLabel *anoEdicaoLB;
    QSpinBox *anoEdicaoSB;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QLabel *cativoLB;
    QCheckBox *cativoCB;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *cadastrarBTN;
    QPushButton *cancelarBTN;

    void setupUi(QDialog *CadastroExemplarDLG)
    {
        if (CadastroExemplarDLG->objectName().isEmpty())
            CadastroExemplarDLG->setObjectName(QStringLiteral("CadastroExemplarDLG"));
        CadastroExemplarDLG->resize(337, 211);
        verticalLayout = new QVBoxLayout(CadastroExemplarDLG);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        idPublicacaoLB = new QLabel(CadastroExemplarDLG);
        idPublicacaoLB->setObjectName(QStringLiteral("idPublicacaoLB"));

        horizontalLayout->addWidget(idPublicacaoLB);

        idPublicacaoSB = new QSpinBox(CadastroExemplarDLG);
        idPublicacaoSB->setObjectName(QStringLiteral("idPublicacaoSB"));
        idPublicacaoSB->setMaximum(1000000000);

        horizontalLayout->addWidget(idPublicacaoSB);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        isbnLB = new QLabel(CadastroExemplarDLG);
        isbnLB->setObjectName(QStringLiteral("isbnLB"));

        horizontalLayout_2->addWidget(isbnLB);

        isbnSB = new QSpinBox(CadastroExemplarDLG);
        isbnSB->setObjectName(QStringLiteral("isbnSB"));
        isbnSB->setMaximum(1000000000);

        horizontalLayout_2->addWidget(isbnSB);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        quantidadeFacLB = new QLabel(CadastroExemplarDLG);
        quantidadeFacLB->setObjectName(QStringLiteral("quantidadeFacLB"));

        horizontalLayout_4->addWidget(quantidadeFacLB);

        quantidadeFacSB = new QSpinBox(CadastroExemplarDLG);
        quantidadeFacSB->setObjectName(QStringLiteral("quantidadeFacSB"));
        quantidadeFacSB->setMaximum(1000000000);

        horizontalLayout_4->addWidget(quantidadeFacSB);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        anoEdicaoLB = new QLabel(CadastroExemplarDLG);
        anoEdicaoLB->setObjectName(QStringLiteral("anoEdicaoLB"));

        horizontalLayout_5->addWidget(anoEdicaoLB);

        anoEdicaoSB = new QSpinBox(CadastroExemplarDLG);
        anoEdicaoSB->setObjectName(QStringLiteral("anoEdicaoSB"));
        anoEdicaoSB->setMaximum(1000000000);

        horizontalLayout_5->addWidget(anoEdicaoSB);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        cativoLB = new QLabel(CadastroExemplarDLG);
        cativoLB->setObjectName(QStringLiteral("cativoLB"));

        horizontalLayout_6->addWidget(cativoLB);

        cativoCB = new QCheckBox(CadastroExemplarDLG);
        cativoCB->setObjectName(QStringLiteral("cativoCB"));

        horizontalLayout_6->addWidget(cativoCB);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        cadastrarBTN = new QPushButton(CadastroExemplarDLG);
        cadastrarBTN->setObjectName(QStringLiteral("cadastrarBTN"));

        horizontalLayout_7->addWidget(cadastrarBTN);

        cancelarBTN = new QPushButton(CadastroExemplarDLG);
        cancelarBTN->setObjectName(QStringLiteral("cancelarBTN"));

        horizontalLayout_7->addWidget(cancelarBTN);


        verticalLayout->addLayout(horizontalLayout_7);


        retranslateUi(CadastroExemplarDLG);

        QMetaObject::connectSlotsByName(CadastroExemplarDLG);
    } // setupUi

    void retranslateUi(QDialog *CadastroExemplarDLG)
    {
        CadastroExemplarDLG->setWindowTitle(QApplication::translate("CadastroExemplarDLG", "Dialog", 0));
        idPublicacaoLB->setText(QApplication::translate("CadastroExemplarDLG", "Id Publicac\303\243o", 0));
        isbnLB->setText(QApplication::translate("CadastroExemplarDLG", "ISBN", 0));
        quantidadeFacLB->setText(QApplication::translate("CadastroExemplarDLG", "Quantidade de Faciculos", 0));
        anoEdicaoLB->setText(QApplication::translate("CadastroExemplarDLG", "Ano de Edi\303\247\303\243o", 0));
        cativoLB->setText(QApplication::translate("CadastroExemplarDLG", "Cativo", 0));
        cativoCB->setText(QString());
        cadastrarBTN->setText(QApplication::translate("CadastroExemplarDLG", "Cadastar", 0));
        cancelarBTN->setText(QApplication::translate("CadastroExemplarDLG", "Cancelar", 0));
    } // retranslateUi

};

namespace Ui {
    class CadastroExemplarDLG: public Ui_CadastroExemplarDLG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADASTROEXEMPLARDLG_H
