#-------------------------------------------------
#
# Project created by QtCreator 2016-11-20T11:29:30
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BibliotecaQT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindlg.cpp \
    connectiondb.cpp \
    alunoemprestimodlg.cpp \
    professoremprestimodlg.cpp \
    ajudadlg.cpp \
    cadastrousuariodlg.cpp \
    devolucaodlg.cpp \
    cadastroexemplardlg.cpp \
    cadastropublicacaodlg.cpp \
    ../../../../Desktop/Teste Banco de dados/BibliotecaQT/renovarlivro.cpp

HEADERS  += mainwindow.h \
    logindlg.h \
    connectiondb.h \
    alunoemprestimodlg.h \
    professoremprestimodlg.h \
    ajudadlg.h \
    cadastrousuariodlg.h \
    devolucaodlg.h \
    cadastroexemplardlg.h \
    cadastropublicacaodlg.h \
    ../../../../Desktop/Teste Banco de dados/BibliotecaQT/renovarlivro.h

FORMS    += mainwindow.ui \
    logindlg.ui \
    alunoemprestimodlg.ui \
    professoremprestimodlg.ui \
    ajudadlg.ui \
    cadastrousuariodlg.ui \
    devolucaodlg.ui \
    cadastroexemplardlg.ui \
    cadastropublicacaodlg.ui \
    ../../../../Desktop/Teste Banco de dados/BibliotecaQT/renovarlivro.ui

RESOURCES += \
    resources.qrc
