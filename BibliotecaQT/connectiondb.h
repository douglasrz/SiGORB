#ifndef CONNECTIONDB_H
#define CONNECTIONDB_H

#include <QObject>
#include <QSqlDatabase>

//Classe Singleton: somente um objeto dela poderá existir durando toda a execução do programa
//logo, temos somente uma conexão aberta com o banco de dados
class ConnectionDB
{
//Atributos e metodos privados
private:
    ConnectionDB();     //Construtor
    ~ConnectionDB();    //Destrutor

    static ConnectionDB *_con;  //Objeto unico dessa classe
    static QSqlDatabase _bd;    //Objeto conectado ao banco

    static void conectar();     //Connectar ao banco
    static void desconectar();  //Desconectar do banco

//Metodos publicos
public:
    static QSqlDatabase get_bd();   //Pegar o objeto que esta conectado ao banco
    static ConnectionDB *get_con(); //Pegar a referencia para o unico objeto dessa classe

};

#endif // CONNECTIONDB_H
