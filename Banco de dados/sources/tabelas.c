#include "../headers/tabelas.h"

#include <stdlib.h>
#include <stdio.h>

//Algumas variaveis globais
unsigned int qtd_clientes = 0;
unsigned int qtd_produtos = 0;

//---------   ALGUMAS FUNÇÕES QUE SÃO NECESSARIAS PARA A MANIPULAÇÃO DOS DADOS DOS ARQUIVOS ------------//
unsigned int separa (unsigned int* v, unsigned int p, unsigned int r){//necessario para o algoritmo de ordenação
   unsigned int c = v[p], i = p+1, j = r, t;
   while (/*A*/ i <= j) {
      if (v[i] <= c) ++i;
      else if (c < v[j]) --j;
      else {
         t = v[i], v[i] = v[j], v[j] = t;
         ++i; --j;
      }
   }
   // agora i == j+1
   v[p] = v[j], v[j] = c;
   return j;
}

void quicksort (unsigned int* v, int p, int r){//algoritmo de ordenação
   unsigned int j;                         // 1
   if (p < r) {                   // 2
      j = separa (v, p, r);       // 3
      quicksort (v, p, j-1);      // 4
      quicksort (v, j+1, r);      // 5
   }
}

boolean pesquisa_binaria(unsigned int* vetor, unsigned int tamanho, unsigned int item){//algoritmo e busca
    unsigned int inicio = 0;
    unsigned int fim = tamanho-1;
    unsigned int meio;

    while(inicio <= fim){
        meio = (inicio + fim) / 2;
        if(item == vetor[meio]){
            return true;
        }

        if(item < vetor[meio]){
            fim = meio-1;
        }
        else{
            inicio = meio +1;
        }
    }

    return false;
}

//-------------------------------------------------------------------------------------------------------//

void cadastar_cliente(char* nome, char* tipo, unsigned int codigo){
    FILE* arquivo;
    arquivo = fopen("arquivos/cliente.txt", "a+");   //Abre o arquivo para escrita no final do arquivo 'a' e 'b' para escrita em binario.
                                                    //Não apaga o conteúdo pré-existente.

    if( arquivo == NULL){   //Se o ponteiro para o arquivo estiver apontando para NULL, o arquivo naão foi aberto.
        printf("O arquivo nao pode ser aberto. A operacao nao foi concluida!\n");
        system("pause");
        arquivo = NULL;
        return;
    }

    fprintf(arquivo, "%s\n%s\n%d\n", nome, tipo, codigo);
    qtd_clientes++; //Almenta a quantidade de clientes ja cadastrados

    fseek(arquivo,0,SEEK_SET);
    fprintf(arquivo, "%d", qtd_clientes);

    fclose(arquivo);    //Fecha o arquivo, pois não ha necessidade de manter ele aberto
}

void cadastar_produto(unsigned int codigo, double preco, char* descricao){
    Produto pro;
    pro.codigo = codigo;
    pro.descricao = descricao;
    pro.valor = preco;

    FILE* arquivo = fopen("arquivos/produto.txt", "a"); //Abre o arquivo para escrita no final do arquivo 'a'.
                                                        //Não apaga o conteúdo pré-existente.

    if( arquivo == NULL){   //Se o ponteiro para o arquivo estiver apontando para NULL, o arquivo naão foi aberto.
        printf("O arquivo nao pode ser aberto. A operacao nao foi concluida!");
        system("pause");
        arquivo = NULL;
        return;
    }


    fwrite(&pro, sizeof(Produto), 1, arquivo);  //escreve a estrutura completa no arquivo
    fclose(arquivo);    //fecha o arquivo
    arquivo = NULL;

    qtd_produtos++;
}

void cadastar_fornecimento(unsigned int cod_venda, char* data_do_fornecimento,
                           unsigned int qtd_produtos_comprados, boolean pago, unsigned int cod_produto, unsigned int cod_cliente){

    FILE* arquivo_fornecimento = fopen("arquivos/fornecimento.txt", "ab"); //Abre o arquivo para escrita no final do arquivo 'a'.
                                                                            //Não apaga o conteúdo pré-existente.

    //Arquivos para efetuar uma busca para determinar se um cliente estar ou nao nos arquivos de PRODUTO e CLIENTE
    FILE* arquivo_cliente = fopen("arquivos/cliente.txt", "rb");
    FILE* arquivo_produto = fopen("arquivos/produto.txt", "rb");

    //Verificando se algum ponteiro estar apontando para NULL, se estiver deu algum erro ao ler o arquivo
    if(arquivo_fornecimento == NULL || arquivo_cliente == NULL || arquivo_produto == NULL){

        printf("Um dos arquivos nao pode ser aberto. A operacao nao foi concluida!");
        system("pause");
        arquivo_fornecimento = NULL;
        arquivo_cliente = NULL;
        arquivo_produto = NULL;
        return;
    }

    //TEM QUE USAR UM ALGORITMO DE BUSCA PARA
    //VERIFICAR SE O cod_prduto E cod_cliente ESTÃO NOS ARQUIVOS DE CLIENTES E PRODUTOS

    unsigned int* list_cod_cli = malloc(sizeof(unsigned int) * qtd_clientes);
    unsigned int* list_cod_pro = malloc(sizeof(unsigned int) * qtd_produtos);


    unsigned int i;
    for(i = 0; i < qtd_clientes; i++){
        fread(list_cod_cli, sizeof(unsigned int), 1, arquivo_cliente);
        fseek(arquivo_cliente, sizeof(char*), SEEK_CUR);
        fseek(arquivo_cliente, sizeof(char*), SEEK_CUR);
    }

    for(i = 0; i < qtd_clientes; i++){
        printf("%d ", list_cod_cli[i]);
    }
    printf("\n");


    quicksort(list_cod_cli,0,qtd_clientes);


    free(list_cod_cli);
    free(list_cod_pro);


    fclose(arquivo_cliente);
    fclose(arquivo_produto);
    fclose(arquivo_fornecimento);
}



void iniciar_valores_das_qtd(){
    FILE* arquivo;

    arquivo = fopen("arquivos/cliente.txt", "r");
    fscanf(arquivo,"%d",&qtd_clientes);
    fclose(arquivo);

    arquivo = fopen("arquivos/produto.txt", "r");
    fscanf(arquivo,"%d",&qtd_produtos);
    fclose(arquivo);

}



