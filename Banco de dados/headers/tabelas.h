#ifndef TABELAS_H_INCLUDED
#define TABELAS_H_INCLUDED

typedef enum{               //Definindo um enum para usar o "true" e o "false", pois no 'c' não existe o tipo de dado "boolean"
    true = 1, false = 0     //O valor de "true" é 1 e o "false" é 0
}boolean;

typedef struct{             //Estrutura da tabela Cliente
    unsigned int codigo;    //O codigo é um número inteiro não negativo
    char* nome[20];             //Cadeia de caracteres
    char* tipo[20];             //Cadeia de caracteres
}Cliente;

typedef struct{
    unsigned int codigo;
    char* descricao[50];
    double valor;
}Produto;

typedef struct{
    unsigned int cod_venda;
    char* data_do_fornecimento[10];
    unsigned int qtd_produto;
    boolean pago;

    unsigned int cod_produto;   //NOVOS: para saber qual o produto que esta sendo vendido.
    unsigned int cod_cliente;   //NOVOS: para saber quem é foi o cliente.

}Fornecimento;


void cadastar_cliente(char*, char*, unsigned int);
void cadastar_produto(unsigned int, double, char*);
void cadastar_fornecimento(unsigned int, char*, unsigned int, boolean, unsigned int, unsigned int);

void iniciar_valores_das_qtd();
#endif // TABELAS_H_INCLUDED
