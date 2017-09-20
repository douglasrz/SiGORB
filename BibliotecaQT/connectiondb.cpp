#include "connectiondb.h"
#include <QDebug>
#include <QSqlError>

//Iniciando variaveis estaticas
//Em C++ quando uma variavel é estatica ele deve ser inicializada
QSqlDatabase ConnectionDB::_bd = QSqlDatabase::addDatabase("QMYSQL");
ConnectionDB *ConnectionDB::_con = new ConnectionDB();

//Construtor
ConnectionDB::ConnectionDB()
{
    //Setando os atributos de acesso ao banco
    _bd.setHostName("localhost");
    _bd.setDatabaseName("biblioteca_qt");
    _bd.setUserName("funcionario");
    _bd.setPassword("senhafunc");

    //Depois de setado é só conectar
    conectar();
}

//Destrutor
ConnectionDB::~ConnectionDB()
{
    delete _con;
    desconectar();
}

void ConnectionDB::conectar()
{
    //O metodo 'idOpen()' abre um conexão com o banco
    _bd.open();

    if(_bd.isOpen())
    {
        qDebug() << "Conectado";
    }
    else
    {
        qDebug() << _bd.lastError();
    }


}

void ConnectionDB::desconectar()
{
    //O metodo 'close()' fecha a conexão com o banco
    _bd.close();
}

ConnectionDB *ConnectionDB::get_con()
{
    //Se o unico objeto dessa classe não foi instanciado
    //primeiro instancie ele para depois retornar uma referencia para ele
    if(!_con){
        _con = new ConnectionDB();
    }

    return _con;
}


QSqlDatabase ConnectionDB::get_bd()
{
    //Se o banco não foi aberto
    //primeiro abra ele
    //depois retorne ele
    if(!_bd.isOpen())
    {
        conectar();
    }

    return _bd;
}
