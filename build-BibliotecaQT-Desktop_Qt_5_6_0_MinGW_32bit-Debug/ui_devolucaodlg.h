/********************************************************************************
** Form generated from reading UI file 'devolucaodlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVOLUCAODLG_H
#define UI_DEVOLUCAODLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_devolucaoDlg
{
public:
    QLabel *label;
    QLineEdit *codLivrotxt;
    QPushButton *buscarBtn;
    QPushButton *devolverBtn;
    QPushButton *cancelarBtn;
    QLabel *label_2;
    QLineEdit *multatxt;
    QTextEdit *livrotxt;
    QLabel *label_3;

    void setupUi(QDialog *devolucaoDlg)
    {
        if (devolucaoDlg->objectName().isEmpty())
            devolucaoDlg->setObjectName(QStringLiteral("devolucaoDlg"));
        devolucaoDlg->resize(400, 300);
        label = new QLabel(devolucaoDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 81, 16));
        codLivrotxt = new QLineEdit(devolucaoDlg);
        codLivrotxt->setObjectName(QStringLiteral("codLivrotxt"));
        codLivrotxt->setGeometry(QRect(120, 30, 181, 20));
        buscarBtn = new QPushButton(devolucaoDlg);
        buscarBtn->setObjectName(QStringLiteral("buscarBtn"));
        buscarBtn->setGeometry(QRect(310, 30, 75, 23));
        devolverBtn = new QPushButton(devolucaoDlg);
        devolverBtn->setObjectName(QStringLiteral("devolverBtn"));
        devolverBtn->setGeometry(QRect(260, 260, 75, 23));
        cancelarBtn = new QPushButton(devolucaoDlg);
        cancelarBtn->setObjectName(QStringLiteral("cancelarBtn"));
        cancelarBtn->setGeometry(QRect(60, 260, 75, 23));
        label_2 = new QLabel(devolucaoDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(230, 190, 47, 13));
        multatxt = new QLineEdit(devolucaoDlg);
        multatxt->setObjectName(QStringLiteral("multatxt"));
        multatxt->setEnabled(false);
        multatxt->setGeometry(QRect(280, 190, 101, 20));
        livrotxt = new QTextEdit(devolucaoDlg);
        livrotxt->setObjectName(QStringLiteral("livrotxt"));
        livrotxt->setEnabled(false);
        livrotxt->setGeometry(QRect(30, 100, 351, 71));
        label_3 = new QLabel(devolucaoDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 80, 71, 16));

        retranslateUi(devolucaoDlg);

        QMetaObject::connectSlotsByName(devolucaoDlg);
    } // setupUi

    void retranslateUi(QDialog *devolucaoDlg)
    {
        devolucaoDlg->setWindowTitle(QApplication::translate("devolucaoDlg", "Dialog", 0));
        label->setText(QApplication::translate("devolucaoDlg", "C\303\263digo do Livro:", 0));
        buscarBtn->setText(QApplication::translate("devolucaoDlg", "Buscar", 0));
        devolverBtn->setText(QApplication::translate("devolucaoDlg", "Devolver", 0));
        cancelarBtn->setText(QApplication::translate("devolucaoDlg", "Cancelar", 0));
        label_2->setText(QApplication::translate("devolucaoDlg", "Multa:", 0));
        label_3->setText(QApplication::translate("devolucaoDlg", "Nome do livro", 0));
    } // retranslateUi

};

namespace Ui {
    class devolucaoDlg: public Ui_devolucaoDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVOLUCAODLG_H
