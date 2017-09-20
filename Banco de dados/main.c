#include <stdio.h>
#include <stdlib.h>
#include "headers/tabelas.h"

//Teste

int main()
{
    int opcao;
    iniciar_valores_das_qtd();
    do{
        system("cls");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Cadastrar produto\n");
        printf("3 - Definir fornecimento\n");
        printf("8 - Sair\n");
        printf("-> ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:{
                char nome[20];
                char tipo[20];
                unsigned int cod;

                printf("Nome: ");
                scanf("%s", nome);
                printf("Tipo: ");
                scanf("%s", tipo);
                printf("Codigo: ");
                scanf("%d", &cod);

                cadastar_cliente(nome, tipo, cod);

                break;
            }
            case 2:{
                break;
            }
            case 3:{
                break;
            }
            case 7:{
            }
            default:{
                break;
            }
        }

    }while(opcao != 8);

    return 0;
}
