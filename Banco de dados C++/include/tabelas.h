#ifndef TABELAS_H
#define TABELAS_H


#include <fstream>  //Responsavel pela manipulação de arquivos
#include <iostream> //Entrada e saida de dados
#include <stdlib.h> //Algumas funcoes do windows, ex: system("pause");
#include <string>   //Manipulação de string
#include <vector>   //Manipulacao de vetores
#include <algorithm>//Utilizada para a função 'find'

#ifdef __unix__ //Quando estiver exucutando no linux o PAUSE e LIMPARTELA chamarao funcoes diferentes
#define LIMPARTELA cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
#define PAUSE cout<<"Digite algo para continuar..."<<endl;cin.getc();
#endif // __unix__

#ifdef _WIN32   //Executando do windows
#define LIMPARTELA system("cls");
#define PAUSE system("pause");
#endif // _WIN32

using namespace std;

class Inf_arquivos; //
class Cliente;      //Declarando as classes
class Produto;      //
class Fornecimento; //


//Definindo as estruturas das classes abaisxo

class Inf_arquivos{
public:
    Inf_arquivos();

    void relatorio_de_venda(unsigned int);          //Exibi um pequeno relatorio de vendas, sendo necessario o codigo da venda
    void valor_total_fornecimento(unsigned int);    // ""   o valor de uma determinda venda, usando um codigo da venda
    void listar_prod_venda(unsigned int);           // "" listando os produtos de uma venda
    void listar_devedores();                        //
    void listar_clientes();                         //
    void listar_produtos();                         //
    void excluir_cliente(unsigned int);
    void excluir_produto(unsigned int);

    vector<Produto> get_produtos();                 //Lendo dos arquivos as informações dos produtos castrados
    vector<Cliente> get_clientes();                 // --    --  --       --  --        --  clientes cadastrados
    vector<Fornecimento> get_fonecimentos();        // --    --  --       --  --        --  forncecimentos cadastrados
};

class Cliente{
private:
    unsigned int codigo;    //
    string nome;            //Atributos
    string tipo;            //

public:
    Cliente();  //Construtor padrão
    Cliente(string, string, unsigned int);  //Construtor sobrecarregado
    bool operator==(const Cliente&)const;   //Função que serve para verificar se dois objetos Clientes são iguais

    //GETS
    string get_nome();
    string get_tipo();
    unsigned int get_codigo();

    //SETS
    void set_nome(string);
    void set_tipo(string);
    void set_codigo(unsigned int);

    //OPERACOES
    void salvar_no_arquivo();   //Salvando as informações de um objeto cliente no arquivo de clientes

    //Função statica(podendo ser utilizada chamando apenas a classe, não sendo necessario chamar essa função de um obejto especifico de Cliente)
    //para verificar se um codigo de cliente ja esta sendo usado ou nao
    /**A implementação esta sendo aqui no '.h' pq ele é um metodo statico,
    e não foi possivel implementar ele no '.cpp'*/
    static bool valido(Inf_arquivos* informacoes, unsigned int cod){

        try{    //Tentando ler os clientes já cadastrados, se não for posivel ler o arquivo será lançado uma exeção, ele ta sendo tratada no catch abaixo

            vector<Cliente> list_clientes = informacoes->get_clientes();

            bool achou = false;                                     //Buscando por um clienta ja cadastrado com o mesmo codigo desse objeto
            for(unsigned int i=0; i< list_clientes.size(); i++){
                if(list_clientes[i].get_codigo() == cod){
                    achou = true;
                    break;
                }
            }

            if(!achou){
                return true;
            }
        }
        catch(const char* erro){    //posivel erro de abertura de arquivo
            cerr << erro << endl;
        }

        return false;
    }

};

class Produto{
private:
    unsigned int codigo;    //
    string nome;            //Atributos privados
    double valor;           //

public:
    Produto();                              //Construtor
    Produto(string, double, unsigned int);  //Construtor
    bool operator==(const Produto&)const;   //Como comparar dois objetos Produto

    //GETS
    string get_nome();
    double get_valor();
    unsigned int get_codigo();

    //SETS
    void set_nome(string);
    void set_valor(double);
    void set_codigo(unsigned int);

    //OPERACOES
    void salvar_no_arquivo();

    //Verificar se um codigo de produto é valido, ou seja, se ele nao estiver no arquivo é pq ele é valido
    static bool valido(Inf_arquivos* informacoes, unsigned int cod){

        try{
            vector<Produto> list_produ = informacoes->get_produtos();
            bool achou = false;
            for(unsigned int i=0; i < list_produ.size(); i++){
                if(list_produ[i].get_codigo() == cod){
                    achou = true;
                    break;
                }
            }
            if(!achou){
                return true;
            }
        }
        catch(const char* erro){
            cerr << erro << endl;
        }

        return false;
    }

};

class Fornecimento{
public:
    Fornecimento(); //Construtor
    bool operator==(const Fornecimento&) const; //Como comparar dois objetos 'Fornecimento'

    //Estrutura com informações sobre um determinado produto no fornecimento
    struct inf_produtos{
        unsigned int cod_produto;
        unsigned int qtd;
        double valor;
    };

    unsigned int cod_venda;
    string data_do_fornecimeno;
    string data_da_entrega;
    bool pago;
    unsigned int cod_cliente;       //quem está recebendo o fornecimento
    vector<inf_produtos> produtos;  //lista dos produtos do fornecimento

    //OPERACOES
    void salvar_no_arquivo();

    //verificando se um codigo informado pelo usuário ja nao foi colocado no arquivo
    //se ja esta no arquivo, o codigo informado nao é valido
    static bool valido(Inf_arquivos& informacoes, unsigned int cod){
        try{
            vector<Fornecimento> list_fornecimentos = informacoes.get_fonecimentos();
            bool achou = false;
            for(unsigned int i = 0; i < list_fornecimentos.size(); i++){
                if(list_fornecimentos[i].cod_venda == cod){
                    achou = true;
                    break;
                }
            }

            if(!achou){
                return true;
            }
        }
        catch(const char* erro){
            cerr<<erro<<endl;
        }

        return false;
    }
};

#endif // TABELAS_H
