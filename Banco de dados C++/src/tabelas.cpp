#include "tabelas.h"



///Funções do CLIENTE
Cliente::Cliente(){                                                             //OK
    //contrutor padrão, não faz nada em especial, so instancia o objeto
}
Cliente::Cliente(string nome, string tipo, unsigned int codigo){                //OK
    this->nome = nome;          //construtor sobrecarregado, podendo setar logo esse valores
    this->tipo = tipo;
    this->codigo = codigo;
}
bool Cliente::operator==(const Cliente& c) const{                               //OK
    //Quando eu fizer isso -> cliente1 == cliente2, ele ira retornar 'true' se os codigos forem iguais
    //e 'false' caso contrario.
    if(c.codigo == this->codigo){
        return true;
    }
    return false;
}

//GETS: usados para requisitar os valores do atributos privados dos clientes
string Cliente::get_nome(){                                                     //OK
    return this->nome;  //'this' é um ponteiro para o proprio objeto
}
string Cliente::get_tipo(){                                                     //OK
    return this->tipo;
}
unsigned int Cliente::get_codigo(){                                             //OK
    return this->codigo;
}

//SETS: usados para modificar o valor dos atributos dos objetos
void Cliente::set_codigo(unsigned int codigo){                                  //OK
    this->codigo = codigo;
}
void Cliente::set_nome(string nome){                                            //OK
    this->nome = nome;
}
void Cliente::set_tipo(string tipo){                                            //OK
    this->tipo = tipo;
}

void Cliente::salvar_no_arquivo(){                                              //OK
    ofstream arquivo;       //'ofstream' para escrita em arquivos
    arquivo.open("Arquivos/cliente.txt", ios::app); //'ios::app' é o modo de abertura, 'app' quer dizer que sera adicionado mais
                                                    //informações ao arquivo.

    if(arquivo.is_open()){
        //Escrevendo no arquivo, primeiro o nome, proxima linha o tipo, e proxima linha o codigo
        arquivo << this->nome << "\n" << this->tipo << "\n" << this->codigo << endl;

        arquivo.close();    //Fechando o arquivo
    }
    else{
        cout<<"Operacao nao concluida, o arquivo de 'clientes' nao pode ser aberto!!!"<<endl;
        PAUSE;
    }

}
//-------------------------------------------------------------------------------------







///Funções do PRODUTO
Produto::Produto(){                                                             //OK
    //contrutor padrão, não faz nada em especial, so instancia o objeto
}
Produto::Produto(string nome, double valor, unsigned int codigo){               //OK
    this->nome = nome;      //construtor sobrecarregado, posibilita instanciar o objeto e setar alguns valores do objeto
    this->valor = valor;
    this->codigo = codigo;
}
bool Produto::operator==(const Produto& p) const{                               //OK
    //isso é uma "sobrecarga de operador", estou sobrecarregando o operador "==" para ele ser usado
    //na função "find", ele serve para verificar se um objeto é igual a outro

    if(this->codigo == p.codigo){ //verificando se os codigos dos produtos são iguais, se forem, os obejtos são iguais
        return true;
    }
    return false;
}

//GETS: usados para requisitar os valores do atributos privados dos clientes
string Produto::get_nome(){                                                     //OK
    return this->nome;
}
double Produto::get_valor(){                                                    //OK
    return this->valor;
}
unsigned int Produto::get_codigo(){                                             //OK
    return this->codigo;
}

//SETS: usados para modificar o valor dos atributos dos objetos
void Produto::set_codigo(unsigned int cod){                                     //OK
    this->codigo = cod;
}
void Produto::set_nome(string nome){                                            //OK
    this->nome = nome;
}
void Produto::set_valor(double valor){                                          //OK
    this->valor = valor;
}

void Produto::salvar_no_arquivo(){                                              //OK
    ofstream arquivo;
    arquivo.open("Arquivos/produto.txt", ios::app);

    if(arquivo.is_open()){
        arquivo << this->nome << "\n" << this->valor << "\n" << this->codigo << endl;

        arquivo.close();
    }
    else{
        cout<<"Operacao nao concluida, o arquivo de 'produtos' nao pode ser aberto!!!"<<endl;
        PAUSE;
    }
}
//---------------------------------------------------------------------------------------








///Informações sobre FORNECIMENTO
Fornecimento::Fornecimento(){                                                   //OK
    //contrutor padrão, não faz nada em especial, so instancia o objeto
}
bool Fornecimento::operator==(const Fornecimento& f) const{                     //OK
    if(f.cod_venda == this->cod_venda){
        return true;
    }
    return false;
}

void Fornecimento::salvar_no_arquivo(){                                         //OK
    ofstream arquivo;
    arquivo.open("Arquivos/fornecimento.txt", ios::app);

    if(arquivo.is_open()){
        arquivo << this->cod_venda << endl;
        arquivo << this->data_do_fornecimeno << endl;
        arquivo << this->data_da_entrega << endl;
        arquivo << this->pago << endl;
        arquivo << this->cod_cliente << endl;

        vector<inf_produtos>::iterator it;
        for(it = this->produtos.begin(); it != this->produtos.end();it++){
            arquivo << (*it).cod_produto << "\n" << (*it).qtd << "\n" << (*it).valor << endl;
        }
        arquivo << "#\n";
        arquivo.close();
    }
    else{
        cout<<"Operacao nao concluida, o arquivo de 'fornecimento' nao pode ser aberto!!!"<<endl;
        PAUSE;
    }
}
//----------------------------------------------------------------------------------------







///Informações sobre os ARQUIVOS
Inf_arquivos::Inf_arquivos(){
    //Construtor padrao
}

void Inf_arquivos::relatorio_de_venda(unsigned int cod_venda){                  //OK
    vector<Cliente> list_client;
    vector<Fornecimento> list_fornecimento;
    vector<Produto> list_produtos;

    try{
        list_client = this->get_clientes();
    }
    catch(const char* erro){
        cerr<<"Erro -> " << erro << endl;
        PAUSE;
        return;
    }

    try{
        list_fornecimento = this->get_fonecimentos();  //pegando a lista de fornecimentos adastrados.
    }
    catch(const char* erro){
        cerr<<"Erro -> " << erro << endl;
        PAUSE;
        return;
    }

    try{
        list_produtos = this->get_produtos();
    }
    catch(const char* erro){
        cerr<<"Erro -> " << erro << endl;
        PAUSE;
        return;
    }




    Fornecimento forn;          //Setando o valor de 'cod_venda' nesse objeto para passar ele para função 'find'
    forn.cod_venda = cod_venda; //ela ira retornar a posição exata do fornecimento com o codigo especificado, se ele estiver no arquivo

    vector<Fornecimento>::iterator it_for;  //iterador para buscar na lista de fornecimento
    it_for = find(list_fornecimento.begin(), list_fornecimento.end(), forn);    //procurando pelo fornecimento

    if(it_for != list_fornecimento.end()){    //se ele foi encontrado exiba suas informações
        forn = *it_for; //variavel 'forn' recebendo o conteudo do iterador

        Cliente clien;      //essa variavel servira para fazer uma busca com a função 'find'
        clien.set_codigo(forn.cod_cliente);

        vector<Cliente>::iterator it_cli;
        it_cli = find(list_client.begin(), list_client.end(), clien); //buscando o cliente


        cout << endl << "- | Fornecimento numero " << forn.cod_venda <<", "<<forn.data_do_fornecimeno<<"."<<endl;
        cout << "- | Destino: "<<(*it_cli).get_tipo()<<" "<<(*it_cli).get_nome()<<"."<<endl;



        for(unsigned int i = 0; i < forn.produtos.size(); i++){
            Produto prod;
            prod.set_codigo(forn.produtos[i].cod_produto);

            vector<Produto>::iterator it_pro;
            it_pro = find(list_produtos.begin(), list_produtos.end(), prod);    //Buscando pelo produto desse fornecimento

            cout << "- | " << forn.produtos[i].qtd << " caixas de " << (*it_pro).get_nome() << ", RS " << (*it_for).produtos[i].valor<<" cada."<<endl;
        }

        if(forn.pago){
            cout<<"- | Pago na entrega, ("<<forn.data_da_entrega<<")."<<endl;
        }
        else{
            cout<<"- | Ainda nao foi pago."<<endl;
        }
    }
    else{
        cout<<"Codigo de venda invalido!!!"<<endl;
    }

    PAUSE;
}
void Inf_arquivos::valor_total_fornecimento(unsigned int cod_venda){            //OK
    Fornecimento forn;
    forn.cod_venda = cod_venda;
    vector<Fornecimento> list_fornecimentos;

    try{
        list_fornecimentos = this->get_fonecimentos();
    }
    catch(const char* erro){    //o erro é 'const char*' pq é so uma mensagem, tipo: "Erro ao abrir um arquivo!!", isso é uma cadeia de caracteres
        cerr<<"Erro-> "<<erro<<endl;
        PAUSE;
        return;
    }

    vector<Fornecimento>::iterator it;
    it = find(list_fornecimentos.begin(), list_fornecimentos.end(), forn);

    if(it != list_fornecimentos.end()){
        double valor_total = 0;
        forn = *it;

        vector<Fornecimento::inf_produtos>::iterator it_pro;
        for(it_pro = forn.produtos.begin(); it_pro != forn.produtos.end(); it_pro++){
            valor_total = ((*it_pro).valor * (*it_pro).qtd) + valor_total;
        }

        cout<<"O valor total do fornecimento "<<cod_venda<<" e de RS "<<valor_total<<endl;
    }
    else{
        cout<<"Codigo do fornecimento invalido!!!"<<endl;
    }

    PAUSE;
}
void Inf_arquivos::listar_prod_venda(unsigned int cod_venda){                   //OK
    Fornecimento forn;
    forn.cod_venda = cod_venda;
    vector<Fornecimento> list_fornecimentos;

    try{
        list_fornecimentos = this->get_fonecimentos();
    }
    catch(const char* erro){
        cerr<<"Erro-> "<<erro<<endl;
        PAUSE;
        return;
    }


    vector<Fornecimento>::iterator it;
    it = find(list_fornecimentos.begin(), list_fornecimentos.end(), forn);

    if(it != list_fornecimentos.end()){
        Produto pro;
        forn = *it;

        vector<Produto> list_produtos;
        try{
            list_produtos = this->get_produtos();
        }
        catch(const char* erro){
            cerr<<"Erro-> "<<erro<<endl;
            PAUSE;
            return;
        }

        vector<Fornecimento::inf_produtos>::iterator it_inf;
        for(it_inf = forn.produtos.begin(); it_inf != forn.produtos.end(); it_inf++){
            pro.set_codigo((*it_inf).cod_produto);

            vector<Produto>::iterator it_pro;
            it_pro = find(list_produtos.begin(), list_produtos.end(), pro);

            cout<<"- "<<(*it_pro).get_nome()<<endl;
        }
    }
    else{
        cout<<"Codigo do fornecimento invalido!!!"<<endl;
    }

    PAUSE;
}
void Inf_arquivos::listar_devedores(){                                          //OK
    vector<Fornecimento>::iterator it_for;
    vector<Fornecimento> list_fornecimentos;

    try{
        list_fornecimentos = this->get_fonecimentos();
    }
    catch(const char* erro){
        cerr<<"Erro-> "<<erro<<endl;
        PAUSE;
        return;
    }


    for(it_for = list_fornecimentos.begin(); it_for != list_fornecimentos.end(); it_for++){
        if((*it_for).pago == true){
            Cliente cli;
            cli.set_codigo((*it_for).cod_cliente);
            vector<Cliente>::iterator it_cli;
            vector<Cliente> list_cliente;

            try{
                list_cliente = this->get_clientes();
            }
            catch(const char* erro){
                cerr<<"Erro-> "<<erro<<endl;
                PAUSE;
                return;
            }


            it_cli = find(list_cliente.begin(), list_cliente.end(), cli);

            cout<<"- "<<(*it_cli).get_tipo()<<" "<<(*it_cli).get_nome()<<endl;
        }
    }

    PAUSE;
}
void Inf_arquivos::listar_clientes(){                                           //OK
    vector<Cliente>::iterator it;
    vector<Cliente> list_clientes;

    try{
        list_clientes = this->get_clientes();
    }
    catch(const char* erro){
        cerr<<"Erro-> "<<erro<<endl;
        PAUSE;
        return;
    }


    for(it = list_clientes.begin(); it != list_clientes.end(); it++){
        cout<<"- Codigo: "<<(*it).get_codigo()<<", Nome: "<<(*it).get_tipo()<<" "<<(*it).get_nome()<<endl;
    }

}
void Inf_arquivos::listar_produtos(){                                           //OK
    vector<Produto>::iterator it;
    vector<Produto> list_produtos;

    try{
        list_produtos = this->get_produtos();
    }
    catch(const char* erro){
        cerr<<"Erro-> "<<erro<<endl;
        PAUSE;
        return;
    }

    for(it = list_produtos.begin(); it != list_produtos.end(); it++){
        cout<<"- Codigo: "<<(*it).get_codigo()<<", Nome: "<<(*it).get_nome() <<", Valor: " << (*it).get_valor()<<endl;
    }

}
void Inf_arquivos::excluir_cliente(unsigned int codigo){                        //OK
    if(!Cliente::valido(this, codigo)){
        //Se nao é valido é pq esse codigo esta no arquivo, então eu posso buscar por esse cliente que eu vou achar

        vector<Cliente> list_clientes;
        try{
            list_clientes = this->get_clientes();   //Pegando os clientes do arquivo
        }
        catch(const char* erro){
            cout<<"Erro-> "<<erro<<endl;
            PAUSE;
            return;
        }

        Cliente cli;
        cli.set_codigo(codigo);

        vector<Cliente>::iterator it;
        it = find(list_clientes.begin(), list_clientes.end(), cli); //buscando por ele

        list_clientes.erase(it);    //apago ele

        ofstream arquivo;
        arquivo.open("Arquivos/cliente.txt", ios::out); //abrindo o arquivo em modo 'ios::out' ele apaga tudo oq tinha la
        arquivo.close();    //fecho o arquivo, agora o arquivo esta vazio;

        for(unsigned int  i = 0; i < list_clientes.size(); i++){
            list_clientes[i].salvar_no_arquivo();   //salvando um a um os clintes que restaram
        }
    }
    else{
        cout<<"Codigo invalido!!!"<<endl;
        PAUSE;
        return;
    }


}
void Inf_arquivos::excluir_produto(unsigned int codigo){                        //OK
    if(!Produto::valido(this, codigo)){
        //se o codigo informado nao for valido é pq esse codigo esta presente no arquivo, ou seja, se eu procurar eu vou encontrar ele

        vector<Produto> list_produtos;
        try{
            list_produtos = this->get_produtos();   //lendo os produtos do arquivo
        }
        catch(const char* erro){
            cout<<"Erro-> "<<erro<<endl;
            PAUSE;
            return;
        }

        Produto pro;
        pro.set_codigo(codigo);

        vector<Produto>::iterator it;
        it = find(list_produtos.begin(), list_produtos.end(), pro); //buscando o produto

        list_produtos.erase(it);    //apagando ele

        ofstream arquivo;
        arquivo.open("Arquivos/produto.txt", ios::out); //abrindo o arquivo e deixando ele vazio
        arquivo.close();

        for(unsigned int i=0; i< list_produtos.size(); i++){
            list_produtos[i].salvar_no_arquivo();   //salvando o restante dos produtos um a um
        }
    }
    else{
        cout<<"Codigo invalido!!!"<<endl;
        PAUSE;
        return;
    }
}

vector<Cliente> Inf_arquivos::get_clientes(){
    ifstream arquivo;       //'ifstream' para leitura de arquivos
    arquivo.open("Arquivos/cliente.txt", ios::in);  //'ios::in' modo de abertura para ler apartir do inicio do arquivo
    vector<Cliente> list_client;

    if(arquivo.is_open()){

        while(!arquivo.eof()){ //Enquanto não for o final do arquivo fique lendo seus dados
            string nome;        //Variaveis temporarias para armazenar as informações de um registro no arquivo.
            string tipo;        //A cada 3 linhas no arquivo um novo registro é lido.
            string cod_sting;   //

            getline(arquivo, nome);        //pego a primeira linha de um registro, que corresponde ao nome do cliente

            if(nome[0] == '\0'){                //se o '\0' for encontrado então chegou no fim do arquivo
                break;                          //não tente armazenar nada nas proximas variaveis
            }

            getline(arquivo, tipo);        //a linha depois do nome, que corresponde ao tipo do cliente
            getline(arquivo, cod_sting);   //a proxima linha é o codigo do cliente, para não bugar a leitura do arquivo estou
                                                //usando a função getline, ele so armazena em variaveis do tipo string, por isso eu armazeno
                                                //na variavel "cod_string" e depois faço a converção dessa variavel para inteiro, na função abaixo

            unsigned int cod_int = atoi(cod_sting.c_str()); //convertendo o valor da string para int

            Cliente clien(nome,tipo,cod_int);   //gerando um objeto "Cliente"

            list_client.push_back(clien); //colocando numa lisata de clientes cadastrados
        }

        arquivo.close();
    }
    else{
        throw "Erro ao abrir o arquivo cliente!!!"; //Se o arquivo nao for aberto é lançado uma exeção que deverar ser tratada por quem que utilizar essa função
    }


    return list_client;
}
vector<Produto> Inf_arquivos::get_produtos(){
    ifstream arquivo;
    arquivo.open("Arquivos/produto.txt", ios::in);
    vector<Produto> list_prod;

    if(arquivo.is_open()){

        while(!arquivo.eof()){
            string nome;
            string valor_string;
            string cod_string;

            getline(arquivo, nome);

            if(nome[0] == '\0'){
                break;
            }

            getline(arquivo, valor_string);
            getline(arquivo, cod_string);

            unsigned int cod_int = atoi(cod_string.c_str());    //Converte para inteiro
            double valor_doble = atof(valor_string.c_str());    //Converte para double

            Produto produto(nome, valor_doble, cod_int);
            list_prod.push_back(produto);

        }

        arquivo.close();
    }
    else{
        throw "Não foi possivel abrir o arquivo de produtos!!!";
    }

    return list_prod;
}
vector<Fornecimento> Inf_arquivos::get_fonecimentos(){
    ifstream arquivo;
    arquivo.open("Arquivos/fornecimento.txt", ios::in);
    vector<Fornecimento> list_forne;

    if(arquivo.is_open()){
        while(!arquivo.eof()){

            Fornecimento fornecimento;

            string cod_venda_string;
            unsigned int cod_venda_int;

            string data_do_fornecimeno;
            string data_da_entrega;

            string pago_string;
            bool pago_bool;

            string cod_cliente_string;
            unsigned int cod_cliente_int;

            getline(arquivo, cod_venda_string);

            if(cod_venda_string[0] == '\0'){
                break;
            }

            getline(arquivo, data_do_fornecimeno);
            getline(arquivo, data_da_entrega);
            getline(arquivo, pago_string);
            getline(arquivo, cod_cliente_string);

            cod_venda_int = atoi(cod_venda_string.c_str());
            pago_bool = atoi(pago_string.c_str());
            cod_cliente_int = atoi(cod_cliente_string.c_str());


            unsigned int cod_produto_int;
            unsigned int qtd_int;
            double valor_double;

            while(true){
                string cod_produto_string;
                string qtd_string;
                string valor_string;

                getline(arquivo, cod_produto_string);

                if(cod_produto_string[0] != '#'){
                    getline(arquivo, qtd_string);
                    getline(arquivo, valor_string);

                    cod_produto_int = atoi(cod_produto_string.c_str());
                    qtd_int = atoi(qtd_string.c_str());
                    valor_double = atof(valor_string.c_str());
                }
                else{
                    break;
                }

                Fornecimento::inf_produtos inf;
                inf.cod_produto = cod_produto_int;
                inf.qtd = qtd_int;
                inf.valor = valor_double;

                fornecimento.produtos.push_back(inf);
            }


            fornecimento.cod_cliente = cod_cliente_int;
            fornecimento.cod_venda = cod_venda_int;
            fornecimento.data_do_fornecimeno = data_do_fornecimeno;
            fornecimento.data_da_entrega = data_da_entrega;
            fornecimento.pago = pago_bool;

            list_forne.push_back(fornecimento);
        }

        arquivo.close();
    }
    else{
        throw "Não foi possivel abrir o arquivo!!!";
    }

    return list_forne;
}
//----------------------------------------------------------------------------------------

