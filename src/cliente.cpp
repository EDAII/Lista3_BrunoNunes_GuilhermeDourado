#include "cliente.hpp"
#include <iostream>

Cliente::Cliente(){
      nomeCliente = "";
      cpf = "";
      socio = 'N';
}

Cliente::Cliente(string nomeCliente,string cpf,char socio){
      this->nomeCliente = nomeCliente;
      this->cpf = cpf;
      this->socio = socio;
}

Cliente::Cliente(string nomeCliente,string cpf,char socio,vector<Produto *> lista_produtos){
      this->nomeCliente = nomeCliente;
      this->cpf = cpf;
      this->socio = socio;
      this->lista_produtos = lista_produtos;
}

Cliente::~Cliente(){
}

string Cliente::get_nomeCliente(){
    return nomeCliente;
}

void Cliente::set_nomeCliente(string nomeCliente){
    this->nomeCliente = nomeCliente;
}

string Cliente::get_cpf(){
    return cpf;
}

void Cliente::set_cpf(string cpf){
    this->cpf = cpf;
}

char Cliente::get_socio(){
  return socio;
}

void Cliente::set_socio(char socio){
  this->socio = socio;
}

void Cliente::salvar_cliente(){

  ofstream myfile3 ("doc/cliente.txt", ios::app);

  if(myfile3.is_open()){
    myfile3 << get_nomeCliente() << '\n';
    myfile3 << get_cpf() << '\n';
    myfile3 << get_socio() << '\n';
    for(Categoria * catego : recomendacoes){
      myfile3 << catego->get_categoria() << endl;
    }
    myfile3 << '$' << '\n';
    myfile3.close();
  } else cout << "Impossibilitado de abrir o arquivo";

}
