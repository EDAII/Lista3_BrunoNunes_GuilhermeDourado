#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <string>
#include <vector>
#include <fstream>
#include "produto.hpp"


using namespace std;

class Cliente{

private:
    string nomeCliente;
    string cpf;
    char socio;


public:

    vector<Produto *> lista_produtos;
    vector<Categoria *> recomendacoes;

    Cliente();
    Cliente(string nomeCliente,string cpf,char socio);
    Cliente(string nomeCliente,string cpf,char socio,vector<Produto *> lista_produtos);
    ~Cliente();

    string get_nomeCliente();
    void set_nomeCliente(string nomeCliente);

    string get_cpf();
    void set_cpf(string cpf);

    char get_socio();
    void set_socio(char socio);

    void salvar_cliente();

};


#endif
