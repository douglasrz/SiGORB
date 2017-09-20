/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFuncionario;
    QAction *actionPublicacao;
    QAction *actionAlunoCad;
    QAction *actionProfessorCad;
    QAction *actionAlunoEmp;
    QAction *actionProfessorEmp;
    QAction *actionUsuario;
    QAction *actionExemplar;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *usuariosCadastradosBTN;
    QPushButton *publicacoesBTN;
    QPushButton *emprestimosBTN;
    QStackedWidget *paginas;
    QWidget *inicialPG;
    QWidget *usuariosPG;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *buscarPorLB;
    QComboBox *tipoDeBuscaUsuarioCB;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *restricaoDeBuscaUsuarioLB;
    QLineEdit *pesquisaUsuarioLE;
    QPushButton *buscarUsuarioBTN;
    QTableView *usuarioTable;
    QWidget *publicacoesPG;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_5;
    QComboBox *tipoDeBuscaPublicacaoCB;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *buscarPublicacaoLB;
    QLineEdit *pesquisaPublicacaoLE;
    QPushButton *buscarPublicacoesBTN;
    QTableView *publicacoesTable;
    QWidget *emprestimoPG;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_4;
    QComboBox *tipoDeBuscaEmprestimoCB;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_9;
    QLabel *restricaoPesquisaEmprestimoLB;
    QLineEdit *pesquisaEmprestimoLE;
    QPushButton *buscarEmprestimosBTN;
    QTableView *emprestimoTable;
    QMenuBar *menuBar;
    QMenu *menuCadastro;
    QMenu *menuEmprestimo;
    QMenu *menuDevolucao;
    QMenu *menuAjuda;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(514, 389);
        actionFuncionario = new QAction(MainWindow);
        actionFuncionario->setObjectName(QStringLiteral("actionFuncionario"));
        actionPublicacao = new QAction(MainWindow);
        actionPublicacao->setObjectName(QStringLiteral("actionPublicacao"));
        actionAlunoCad = new QAction(MainWindow);
        actionAlunoCad->setObjectName(QStringLiteral("actionAlunoCad"));
        actionProfessorCad = new QAction(MainWindow);
        actionProfessorCad->setObjectName(QStringLiteral("actionProfessorCad"));
        actionAlunoEmp = new QAction(MainWindow);
        actionAlunoEmp->setObjectName(QStringLiteral("actionAlunoEmp"));
        actionProfessorEmp = new QAction(MainWindow);
        actionProfessorEmp->setObjectName(QStringLiteral("actionProfessorEmp"));
        actionUsuario = new QAction(MainWindow);
        actionUsuario->setObjectName(QStringLiteral("actionUsuario"));
        actionExemplar = new QAction(MainWindow);
        actionExemplar->setObjectName(QStringLiteral("actionExemplar"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        usuariosCadastradosBTN = new QPushButton(centralWidget);
        usuariosCadastradosBTN->setObjectName(QStringLiteral("usuariosCadastradosBTN"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(usuariosCadastradosBTN->sizePolicy().hasHeightForWidth());
        usuariosCadastradosBTN->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(usuariosCadastradosBTN);

        publicacoesBTN = new QPushButton(centralWidget);
        publicacoesBTN->setObjectName(QStringLiteral("publicacoesBTN"));
        sizePolicy.setHeightForWidth(publicacoesBTN->sizePolicy().hasHeightForWidth());
        publicacoesBTN->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(publicacoesBTN);

        emprestimosBTN = new QPushButton(centralWidget);
        emprestimosBTN->setObjectName(QStringLiteral("emprestimosBTN"));
        sizePolicy.setHeightForWidth(emprestimosBTN->sizePolicy().hasHeightForWidth());
        emprestimosBTN->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(emprestimosBTN);


        horizontalLayout->addLayout(verticalLayout);

        paginas = new QStackedWidget(centralWidget);
        paginas->setObjectName(QStringLiteral("paginas"));
        paginas->setEnabled(true);
        inicialPG = new QWidget();
        inicialPG->setObjectName(QStringLiteral("inicialPG"));
        paginas->addWidget(inicialPG);
        usuariosPG = new QWidget();
        usuariosPG->setObjectName(QStringLiteral("usuariosPG"));
        verticalLayout_3 = new QVBoxLayout(usuariosPG);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(usuariosPG);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        buscarPorLB = new QLabel(usuariosPG);
        buscarPorLB->setObjectName(QStringLiteral("buscarPorLB"));

        horizontalLayout_2->addWidget(buscarPorLB);

        tipoDeBuscaUsuarioCB = new QComboBox(usuariosPG);
        tipoDeBuscaUsuarioCB->setObjectName(QStringLiteral("tipoDeBuscaUsuarioCB"));

        horizontalLayout_2->addWidget(tipoDeBuscaUsuarioCB);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        restricaoDeBuscaUsuarioLB = new QLabel(usuariosPG);
        restricaoDeBuscaUsuarioLB->setObjectName(QStringLiteral("restricaoDeBuscaUsuarioLB"));

        horizontalLayout_3->addWidget(restricaoDeBuscaUsuarioLB);

        pesquisaUsuarioLE = new QLineEdit(usuariosPG);
        pesquisaUsuarioLE->setObjectName(QStringLiteral("pesquisaUsuarioLE"));

        horizontalLayout_3->addWidget(pesquisaUsuarioLE);

        buscarUsuarioBTN = new QPushButton(usuariosPG);
        buscarUsuarioBTN->setObjectName(QStringLiteral("buscarUsuarioBTN"));

        horizontalLayout_3->addWidget(buscarUsuarioBTN);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout_2);

        usuarioTable = new QTableView(usuariosPG);
        usuarioTable->setObjectName(QStringLiteral("usuarioTable"));

        verticalLayout_3->addWidget(usuarioTable);

        paginas->addWidget(usuariosPG);
        publicacoesPG = new QWidget();
        publicacoesPG->setObjectName(QStringLiteral("publicacoesPG"));
        verticalLayout_4 = new QVBoxLayout(publicacoesPG);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(publicacoesPG);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        label_5 = new QLabel(publicacoesPG);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        tipoDeBuscaPublicacaoCB = new QComboBox(publicacoesPG);
        tipoDeBuscaPublicacaoCB->setObjectName(QStringLiteral("tipoDeBuscaPublicacaoCB"));

        horizontalLayout_5->addWidget(tipoDeBuscaPublicacaoCB);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        buscarPublicacaoLB = new QLabel(publicacoesPG);
        buscarPublicacaoLB->setObjectName(QStringLiteral("buscarPublicacaoLB"));

        horizontalLayout_6->addWidget(buscarPublicacaoLB);

        pesquisaPublicacaoLE = new QLineEdit(publicacoesPG);
        pesquisaPublicacaoLE->setObjectName(QStringLiteral("pesquisaPublicacaoLE"));

        horizontalLayout_6->addWidget(pesquisaPublicacaoLE);

        buscarPublicacoesBTN = new QPushButton(publicacoesPG);
        buscarPublicacoesBTN->setObjectName(QStringLiteral("buscarPublicacoesBTN"));

        horizontalLayout_6->addWidget(buscarPublicacoesBTN);


        verticalLayout_4->addLayout(horizontalLayout_6);

        publicacoesTable = new QTableView(publicacoesPG);
        publicacoesTable->setObjectName(QStringLiteral("publicacoesTable"));

        verticalLayout_4->addWidget(publicacoesTable);

        paginas->addWidget(publicacoesPG);
        emprestimoPG = new QWidget();
        emprestimoPG->setObjectName(QStringLiteral("emprestimoPG"));
        verticalLayout_5 = new QVBoxLayout(emprestimoPG);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_3 = new QLabel(emprestimoPG);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        label_4 = new QLabel(emprestimoPG);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_8->addWidget(label_4);

        tipoDeBuscaEmprestimoCB = new QComboBox(emprestimoPG);
        tipoDeBuscaEmprestimoCB->setObjectName(QStringLiteral("tipoDeBuscaEmprestimoCB"));

        horizontalLayout_8->addWidget(tipoDeBuscaEmprestimoCB);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        restricaoPesquisaEmprestimoLB = new QLabel(emprestimoPG);
        restricaoPesquisaEmprestimoLB->setObjectName(QStringLiteral("restricaoPesquisaEmprestimoLB"));

        horizontalLayout_9->addWidget(restricaoPesquisaEmprestimoLB);

        pesquisaEmprestimoLE = new QLineEdit(emprestimoPG);
        pesquisaEmprestimoLE->setObjectName(QStringLiteral("pesquisaEmprestimoLE"));

        horizontalLayout_9->addWidget(pesquisaEmprestimoLE);

        buscarEmprestimosBTN = new QPushButton(emprestimoPG);
        buscarEmprestimosBTN->setObjectName(QStringLiteral("buscarEmprestimosBTN"));

        horizontalLayout_9->addWidget(buscarEmprestimosBTN);


        verticalLayout_5->addLayout(horizontalLayout_9);

        emprestimoTable = new QTableView(emprestimoPG);
        emprestimoTable->setObjectName(QStringLiteral("emprestimoTable"));

        verticalLayout_5->addWidget(emprestimoTable);

        paginas->addWidget(emprestimoPG);

        horizontalLayout->addWidget(paginas);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 514, 21));
        menuCadastro = new QMenu(menuBar);
        menuCadastro->setObjectName(QStringLiteral("menuCadastro"));
        menuEmprestimo = new QMenu(menuBar);
        menuEmprestimo->setObjectName(QStringLiteral("menuEmprestimo"));
        menuDevolucao = new QMenu(menuBar);
        menuDevolucao->setObjectName(QStringLiteral("menuDevolucao"));
        menuAjuda = new QMenu(menuBar);
        menuAjuda->setObjectName(QStringLiteral("menuAjuda"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(pesquisaUsuarioLE, buscarUsuarioBTN);
        QWidget::setTabOrder(buscarUsuarioBTN, tipoDeBuscaUsuarioCB);
        QWidget::setTabOrder(tipoDeBuscaUsuarioCB, usuarioTable);
        QWidget::setTabOrder(usuarioTable, usuariosCadastradosBTN);
        QWidget::setTabOrder(usuariosCadastradosBTN, publicacoesBTN);
        QWidget::setTabOrder(publicacoesBTN, emprestimosBTN);
        QWidget::setTabOrder(emprestimosBTN, tipoDeBuscaPublicacaoCB);
        QWidget::setTabOrder(tipoDeBuscaPublicacaoCB, pesquisaPublicacaoLE);
        QWidget::setTabOrder(pesquisaPublicacaoLE, buscarPublicacoesBTN);
        QWidget::setTabOrder(buscarPublicacoesBTN, publicacoesTable);
        QWidget::setTabOrder(publicacoesTable, tipoDeBuscaEmprestimoCB);
        QWidget::setTabOrder(tipoDeBuscaEmprestimoCB, pesquisaEmprestimoLE);
        QWidget::setTabOrder(pesquisaEmprestimoLE, buscarEmprestimosBTN);
        QWidget::setTabOrder(buscarEmprestimosBTN, emprestimoTable);

        menuBar->addAction(menuCadastro->menuAction());
        menuBar->addAction(menuEmprestimo->menuAction());
        menuBar->addAction(menuDevolucao->menuAction());
        menuBar->addAction(menuAjuda->menuAction());
        menuCadastro->addAction(actionUsuario);
        menuCadastro->addAction(actionPublicacao);
        menuCadastro->addAction(actionExemplar);
        menuEmprestimo->addAction(actionAlunoEmp);
        menuEmprestimo->addAction(actionProfessorEmp);

        retranslateUi(MainWindow);

        paginas->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Biblioteca", 0));
        actionFuncionario->setText(QApplication::translate("MainWindow", "Funcion\303\241rio", 0));
        actionPublicacao->setText(QApplication::translate("MainWindow", "Publica\303\247\303\243o", 0));
        actionAlunoCad->setText(QApplication::translate("MainWindow", "Aluno", 0));
        actionProfessorCad->setText(QApplication::translate("MainWindow", "Professor", 0));
        actionAlunoEmp->setText(QApplication::translate("MainWindow", "Aluno", 0));
        actionProfessorEmp->setText(QApplication::translate("MainWindow", "Professor", 0));
        actionUsuario->setText(QApplication::translate("MainWindow", "Usu\303\241rio", 0));
        actionExemplar->setText(QApplication::translate("MainWindow", "Exemplar", 0));
        usuariosCadastradosBTN->setText(QApplication::translate("MainWindow", "Usu\303\241rios", 0));
        publicacoesBTN->setText(QApplication::translate("MainWindow", "Publicac\303\265es", 0));
        emprestimosBTN->setText(QApplication::translate("MainWindow", "Emprestimos", 0));
        label->setText(QApplication::translate("MainWindow", "Pagina de Usu\303\241rios", 0));
        buscarPorLB->setText(QApplication::translate("MainWindow", "Busca por", 0));
        tipoDeBuscaUsuarioCB->clear();
        tipoDeBuscaUsuarioCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Todos", 0)
         << QApplication::translate("MainWindow", "Nome", 0)
         << QApplication::translate("MainWindow", "E-mail", 0)
        );
        restricaoDeBuscaUsuarioLB->setText(QApplication::translate("MainWindow", "Todos", 0));
        buscarUsuarioBTN->setText(QApplication::translate("MainWindow", "Buscar", 0));
        label_2->setText(QApplication::translate("MainWindow", "Pagina de publia\303\247\303\265es", 0));
        label_5->setText(QApplication::translate("MainWindow", "Bucar por", 0));
        tipoDeBuscaPublicacaoCB->clear();
        tipoDeBuscaPublicacaoCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Todas", 0)
         << QApplication::translate("MainWindow", "T\303\255tulo", 0)
         << QApplication::translate("MainWindow", "Editora", 0)
         << QApplication::translate("MainWindow", "G\303\252nero", 0)
        );
        buscarPublicacaoLB->setText(QApplication::translate("MainWindow", "Tudo", 0));
        buscarPublicacoesBTN->setText(QApplication::translate("MainWindow", "Buscar", 0));
        label_3->setText(QApplication::translate("MainWindow", "Pagina Emprestimos", 0));
        label_4->setText(QApplication::translate("MainWindow", "Pesquisar por", 0));
        tipoDeBuscaEmprestimoCB->clear();
        tipoDeBuscaEmprestimoCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Tudo", 0)
         << QApplication::translate("MainWindow", "Nome do usu\303\241rio", 0)
         << QApplication::translate("MainWindow", "Id do exemplar", 0)
         << QApplication::translate("MainWindow", "T\303\255tulo do Livro", 0)
        );
        restricaoPesquisaEmprestimoLB->setText(QApplication::translate("MainWindow", "Tudo", 0));
        buscarEmprestimosBTN->setText(QApplication::translate("MainWindow", "Buscar", 0));
        menuCadastro->setTitle(QApplication::translate("MainWindow", "Cadastro", 0));
        menuEmprestimo->setTitle(QApplication::translate("MainWindow", "Emprestimo", 0));
        menuDevolucao->setTitle(QApplication::translate("MainWindow", "Devolu\303\247\303\243o", 0));
        menuAjuda->setTitle(QApplication::translate("MainWindow", "Ajuda", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
