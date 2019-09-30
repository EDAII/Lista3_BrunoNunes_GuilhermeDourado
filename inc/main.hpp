#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include "categoria.hpp"
#include "produto.hpp"
#include "cliente.hpp"
#include <vector>
#include <cstring>
#include <iomanip>
#include <algorithm>

bool valida(string cat, std::vector<Categoria *> v);
bool busca(string produto, std::vector<Produto *> p);
bool busca_cliente(string cpf, std::vector<Cliente *> c);
Produto * inserir(string produto, std::vector<Produto *> p);
Produto * inserir_categoria(string categoria, std::vector<Produto *> p);
Cliente * inserir_cliente(string cpf, std::vector<Cliente *> c);

bool valida(string cat, vector<Categoria *> v){
		int a = v.size();

		if(a==0){
			return false;
		}

		for(int i = 0; i < a; i++){
			if(v[i]->get_categoria() == cat){
				return true;
			}
		}
		return false;

}

bool busca(string produto, std::vector<Produto *> p){
      int a = p.size();

      if(a==0){
        return false; //TODO fazer excecao
      }

      for(int i = 0; i < a; i++){
        if(p[i]->get_nome() == produto) return true;
      }
      return false;

}

bool busca_cliente(string cpf, std::vector<Cliente *> c){
	int a = c.size();

	if(a==0){
		throw('a');
	}

	for(int i = 0; i < a; i++){
		if(c[i]->get_cpf() == cpf) return true;
	}
	return false;

}

Produto * inserir(string produto, std::vector<Produto *> p){

  int a = p.size();

  for(int i = 0; i < a; i++){
    if(p[i]->get_nome() == produto) return p[i];
  }
  return NULL;
}

Produto * inserir_categoria(string categoria, std::vector<Produto *> p){

  int a = p.size();

  for(int i = 0; i < a; i++){
    if(p[i]->get_categoria() == categoria) return p[i];
  }
  return NULL;
}

Cliente * inserir_cliente(string cpf, std::vector<Cliente *> c){

  int a = c.size();

  for(int i = 0; i < a; i++){
    if(c[i]->get_cpf() == cpf) return c[i];
  }
  return NULL;
}

template <typename T1>

T1 getInput(){
    while(true){
    T1 valor;
    cin >> valor;
    if(cin.fail()){
        cin.clear();
        cin.ignore(32767,'\n');
        cout << "Entrada inválida! Insira novamente: " << endl;
    }
    else{
        cin.ignore(32767,'\n');
        return valor;
    }
    }
}



#endif
