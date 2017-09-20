/********************************************************************************
** Form generated from reading UI file 'ajudadlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJUDADLG_H
#define UI_AJUDADLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_ajudaDlg
{
public:
    QTextBrowser *textBrowser;
    QLabel *label;

    void setupUi(QDialog *ajudaDlg)
    {
        if (ajudaDlg->objectName().isEmpty())
            ajudaDlg->setObjectName(QStringLiteral("ajudaDlg"));
        ajudaDlg->resize(400, 300);
        textBrowser = new QTextBrowser(ajudaDlg);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 70, 351, 192));
        label = new QLabel(ajudaDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 231, 41));

        retranslateUi(ajudaDlg);

        QMetaObject::connectSlotsByName(ajudaDlg);
    } // setupUi

    void retranslateUi(QDialog *ajudaDlg)
    {
        ajudaDlg->setWindowTitle(QApplication::translate("ajudaDlg", "Dialog", 0));
        textBrowser->setHtml(QApplication::translate("ajudaDlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">Textando a tela de ajuda para o trabalho de BD</span></p></body></html>", 0));
        label->setText(QApplication::translate("ajudaDlg", "AJUDA", 0));
    } // retranslateUi

};

namespace Ui {
    class ajudaDlg: public Ui_ajudaDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJUDADLG_H
