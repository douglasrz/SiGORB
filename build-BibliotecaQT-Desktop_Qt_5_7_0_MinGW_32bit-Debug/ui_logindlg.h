/********************************************************************************
** Form generated from reading UI file 'logindlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDLG_H
#define UI_LOGINDLG_H

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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDLG
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *iconeLB;
    QVBoxLayout *verticalLayout_2;
    QLabel *usernameLB;
    QLineEdit *usernameLE;
    QVBoxLayout *verticalLayout;
    QLabel *senhaLB;
    QLineEdit *senhaLE;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginBTN;
    QPushButton *cancelarBTN;

    void setupUi(QDialog *LoginDLG)
    {
        if (LoginDLG->objectName().isEmpty())
            LoginDLG->setObjectName(QStringLiteral("LoginDLG"));
        LoginDLG->setWindowModality(Qt::NonModal);
        LoginDLG->resize(260, 350);
        LoginDLG->setMinimumSize(QSize(260, 350));
        LoginDLG->setMaximumSize(QSize(260, 350));
        verticalLayout_4 = new QVBoxLayout(LoginDLG);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        iconeLB = new QLabel(LoginDLG);
        iconeLB->setObjectName(QStringLiteral("iconeLB"));
        iconeLB->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(iconeLB);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        usernameLB = new QLabel(LoginDLG);
        usernameLB->setObjectName(QStringLiteral("usernameLB"));

        verticalLayout_2->addWidget(usernameLB);

        usernameLE = new QLineEdit(LoginDLG);
        usernameLE->setObjectName(QStringLiteral("usernameLE"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(usernameLE->sizePolicy().hasHeightForWidth());
        usernameLE->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(usernameLE);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        senhaLB = new QLabel(LoginDLG);
        senhaLB->setObjectName(QStringLiteral("senhaLB"));

        verticalLayout->addWidget(senhaLB);

        senhaLE = new QLineEdit(LoginDLG);
        senhaLE->setObjectName(QStringLiteral("senhaLE"));
        sizePolicy.setHeightForWidth(senhaLE->sizePolicy().hasHeightForWidth());
        senhaLE->setSizePolicy(sizePolicy);
        senhaLE->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(senhaLE);


        verticalLayout_3->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        loginBTN = new QPushButton(LoginDLG);
        loginBTN->setObjectName(QStringLiteral("loginBTN"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(loginBTN->sizePolicy().hasHeightForWidth());
        loginBTN->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(loginBTN);

        cancelarBTN = new QPushButton(LoginDLG);
        cancelarBTN->setObjectName(QStringLiteral("cancelarBTN"));
        sizePolicy1.setHeightForWidth(cancelarBTN->sizePolicy().hasHeightForWidth());
        cancelarBTN->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(cancelarBTN);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(LoginDLG);

        QMetaObject::connectSlotsByName(LoginDLG);
    } // setupUi

    void retranslateUi(QDialog *LoginDLG)
    {
        LoginDLG->setWindowTitle(QApplication::translate("LoginDLG", "Dialog", 0));
        iconeLB->setText(QString());
        usernameLB->setText(QApplication::translate("LoginDLG", "Username", 0));
        senhaLB->setText(QApplication::translate("LoginDLG", "Senha", 0));
        loginBTN->setText(QApplication::translate("LoginDLG", "Login", 0));
        cancelarBTN->setText(QApplication::translate("LoginDLG", "Cancelar", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDLG: public Ui_LoginDLG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDLG_H
