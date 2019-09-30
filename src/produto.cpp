#include "produto.hpp"
#include <iostream>

Produto::Produto(){
	nome = "";
	valor = 0;
	quantidade = 0;
}

Produto::Produto(string categoria){
	set_categoria(categoria);
}

Produto::Produto(string nome, float valor, int quantidade){
	set_nome(nome);
	set_valor(valor);
	set_quantidade(quantidade);
}

Produto::Produto(string nome, string categoria, float valor, int quantidade){
	set_nome(nome);
	set_categoria(categoria);
	set_valor(valor);
	set_quantidade(quantidade);
}

Produto::Produto(const Produto &rhs): Categoria(rhs), nome(rhs.nome), valor(rhs.valor), quantidade(rhs.quantidade){
}

Produto::~Produto(){
}

string Produto::get_nome(){
	return nome;
}

void Produto::set_nome(string nome){
	this->nome = nome;
}

float Produto::get_valor(){
	return valor;
}

void Produto::set_valor(float valor){
	this->valor = valor;
}

int Produto::get_quantidade(){
	return quantidade;
}

void Produto::set_quantidade(int quantidade){
	this->quantidade = quantidade;
}

void Produto::salvar_info(){

	ofstream myfile ("doc/produtos.txt", ios::app);

	if (myfile.is_open()){
		myfile << get_nome() << '\n';
		myfile << get_categoria() << '\n';
		myfile << get_valor() << '\n';
		myfile << get_quantidade() << '\n';
		myfile << "$\n";
		myfile.close();
	}else cout << "Impossibilitado de abrir o arquivo" << endl;
}
