#include <iostream>
#include "tabelas.h"
using namespace std;


int main()
{
    int opcao;
    Inf_arquivos informacoes;

    do{
        cout<<"1 - Cadastrar cliente "<<endl;
        cout<<"2 - Cadastrar produto "<<endl;
        cout<<"3 - Cadastrar fornecimento "<<endl;
        cout<<"4 - Relatorio de um fornecimento "<<endl;
        cout<<"5 - Valor total do fornecimento "<<endl;
        cout<<"6 - Quais produtos foram entregues num determinado fornecimento "<<endl;
        cout<<"7 - Quais clientes estao devendo "<<endl;
        cout<<"8 - Listar produtos "<<endl;
        cout<<"9 - Listar clientes "<<endl;
        cout<<"10 - Excluir cliente "<<endl;
        cout<<"11 - Excluir produto "<<endl;
        cout<<"12 - Sair"<<endl;
        cout<<"->";
        cin>>opcao;

        ///lembrar de retirar alguns atributos irelevantess
        switch(opcao){
            case 1:{//OK
                string nome;
                string tipo;
                unsigned int cod;

                Cliente cli;

                LIMPARTELA;
                cout<<"--CADASTRAR CLIENTE--"<<endl<<endl;

                cout<<"Codigo: ";
                fflush(stdin);
                cin >> cod;

                if(!Cliente::valido(&informacoes, cod)){    //verificando a validade do codigo informado pelo usuario
                    cout<<"Cliente ja cadastrado!!!"<<endl;
                    PAUSE;
                    break;
                }

                cout<<"Nome: ";
                fflush(stdin);      //limpando o buffer pois se tiver algo la ele nao ira pegar o nome que o usuário digitou
                getline(cin, nome); //pegando uma linha inteira que o usuário digitar, incluindo os espaços em brancos

                cout<<"Tipo: ";
                fflush(stdin);
                getline(cin, tipo);


                cli.set_codigo(cod);
                cli.set_nome(nome);
                cli.set_tipo(tipo);

                cli.salvar_no_arquivo();    //salvando no arquivo de cliente
                break;

            }
            case 2:{//OK
                string nome;
                double valor;
                unsigned int cod;

                Produto prod;

                LIMPARTELA;
                cout<<"--CADASTRAR PRODUTO--"<<endl<<endl;

                cout<<"Codigo: ";
                cin >> cod;

                if(!Produto::valido(&informacoes, cod)){     //verificando a validade do codigo do produto informado
                    cout<<"Produto ja cadastrado!!!"<<endl;
                    PAUSE;
                    break;
                }

                cout<<"Nome: ";
                fflush(stdin);  //limpando o buffer
                getline(cin, nome); //lendo uma linha inteira no prompt

                cout<<"Valor: ";
                fflush(stdin);
                cin >> valor;

                prod.set_codigo(cod);
                prod.set_nome(nome);
                prod.set_valor(valor);


                prod.salvar_no_arquivo();    //armazenando no arquivo de produtos

                break;
            }
            case 3:{//OK
                Fornecimento fornecimento;  //criando um objeto fornecimento

                LIMPARTELA;
                cout<<"--CADASTRAR FORNECIMENTO--"<<endl<<endl;

                unsigned int cod_venda;
                cout<<"Codigo do fornecimento: ";
                cin>>cod_venda;

                if(!Fornecimento::valido(informacoes, cod_venda)){  //verificando a validade do codigo do fornecimento informado
                    cout<<"O codigo dessa venda ja esta cadastrada, tente novamente!!!"<<endl;
                    PAUSE;
                    break;
                }

                fornecimento.cod_venda = cod_venda;

                bool conti;
                while(true){
                    unsigned int cod_cliente;

                    cout<<"Codigo do cliente: ";
                    cin>>cod_cliente;

                    Cliente cli;
                    if(Cliente::valido(&informacoes, cod_cliente)){
                        fornecimento.cod_cliente = cod_cliente;
                    }
                    else{

                        cout<<"Codigo invalido!!!"<<endl<<"'1' para digitar outro codigo"<<endl<<"'0' para cancelar o cadastrar fornecimento: "<<endl;
                        cin>>conti;

                        if(!conti){
                            break;
                        }
                    }

                }

                if(!conti){
                    break;
                }

                cout<<"Data do fornceminto: ";
                cin>>fornecimento.data_do_fornecimeno;  //esperando a data do fornecimento

                cout<<"Data da entrega: ";
                cin>>fornecimento.data_da_entrega;

                cout<<"Digite '1' se ja foi pago ou '0' se ainda vai ser pago: ";
                cin>>fornecimento.pago;

                cout<<endl<<endl<<"--Produtos do fornecimento--"<<endl;

                bool continuar = true;              //variavel que ficará responsavel pela parada do loop abaixo
                while(continuar){
                    Fornecimento::inf_produtos pro; //criando uma estrutura que terá as seguintes informações
                                                    //PRODUTO, QUANTIDADE, PRECO.


                    unsigned int cod_produto;
                    cout<<"Codigo do produto: ";
                    cin>>cod_produto;


                    if(!Produto::valido(&informacoes, cod_produto)){ //Se esse codigo nao for valido é pq ele ja esta cadastrado
                                                                    //ou seja ele existe no estoque

                        cout<<"Quantidade de caixar enviadas: ";
                        cin>>pro.qtd;

                        cout<<"Valor unitario das caixa: ";
                        cin>>pro.valor;

                        pro.cod_produto = cod_produto;

                        fornecimento.produtos.push_back(pro);   //adicionando esse produto com suas informações na lista de produtos
                                                                //desse fornecimento.
                    }
                    else{
                        cout<<endl<<"PRODUTO INVALIDO!!!"<<endl;    //se o codigo do produto informado acima não estiver relacionado com nenhum
                                                                    //produto cadastrado no sistema, então nao precisa perguntar qual o preço por caixa
                                                                    //e muito menos a quantidade de caixas, só mostre essa menssagem de produto invalido.
                    }


                    cout<<endl<<"'1' para adicionar produto ao fornecimento\n'0' finalizar os dados do fornecimento\n->";   //pergundando se ainda tem produtos nesse fornecimento
                    cin>>continuar;     //se sim, pergunte qual o novo produto, e repita os passo acima
                    cout<<endl<<endl;
                }

                //se nao foi adicionado nenhum produto a este fornecimento então o fornecimento não pode ser salvo, pois não
                //ha sentido num fornecimento sem produtos
                if(fornecimento.produtos.size() == 0){
                    cout<<"Operacao de fornecimento nao concluida,(alguns dados podem estar faltando)!!"<<endl;
                    PAUSE;
                }
                else{
                    fornecimento.salvar_no_arquivo(); //salvando esse fornecimento no arquivo
                }


                break;
            }
            case 4:{//OK
                unsigned int cod_venda;

                LIMPARTELA;
                cout<<"--RELATORIO DO FORNECIMENTO--"<<endl<<endl;

                cout<<"Digite o codigo do fornecimento: "<<endl;
                cin>>cod_venda;

                informacoes.relatorio_de_venda(cod_venda);

                break;
            }
            case 5:{//OK
                unsigned int cod_venda;

                LIMPARTELA;
                cout<<"--VALOR DE UM FORNECIMENTO--"<<endl<<endl;

                cout<<"Digite o codigo do fornecimento: ";
                cin>>cod_venda;

                informacoes.valor_total_fornecimento(cod_venda);
                break;
            }
            case 6:{//OK
                LIMPARTELA;
                cout<<"--LISTA DE PRODUTOS DE UM FORNECIMENTO--"<<endl<<endl;

                unsigned int cod_venda;
                cout<<"Codigo do fornecimento: ";
                cin>>cod_venda;

                informacoes.listar_prod_venda(cod_venda);

                break;
            }
            case 7:{//OK
                LIMPARTELA;
                cout<<"--LISTA CLIENTES DEVEDORES--"<<endl<<endl;

                informacoes.listar_devedores();

                break;
            }
            case 8:{//OK
                LIMPARTELA;
                cout<<"--LISTA DE PRODUTOS--"<<endl<<endl;

                informacoes.listar_produtos();

                PAUSE;
                break;
            }
            case 9:{//OK
                LIMPARTELA;
                cout<<"--LISTA DE CLIENTES--"<<endl<<endl;
                informacoes.listar_clientes();

                PAUSE;
                break;
            }
            case 10:{//OK
                LIMPARTELA;
                cout<<"--EXCLUIR CLIENTE--"<<endl<<endl;
                informacoes.listar_clientes();
                cout<<endl<<endl;
                unsigned int cod;
                cout<<"Digite o codigo do cliente: ";
                cin>>cod;

                informacoes.excluir_cliente(cod);

                break;
            }
            case 11:{//OK
                LIMPARTELA;
                cout<<"--EXCLUIR PRODUTO--"<<endl<<endl;

                informacoes.listar_produtos();
                cout<<endl<<endl;

                unsigned int cod;
                cout<<"Digite o codigo do produto: ";
                cin>>cod;

                informacoes.excluir_produto(cod);

                break;
            }
            case 12:{//OK
                break;
            }
            default:{
                cout<<"Operacao invalida!!!"<<endl;
                PAUSE;
                break;
            }
        }

        LIMPARTELA;
    }while(opcao != 12);

    cout << "Bye world!" << endl;
    return 0;
}
