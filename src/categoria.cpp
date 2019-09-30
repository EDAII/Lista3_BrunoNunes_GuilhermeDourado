#include "categoria.hpp"
#include <iostream>


Categoria::Categoria(){
	categoria = "";
}

Categoria::Categoria(string categoria){
	this->categoria = categoria;
}

Categoria::Categoria (const Categoria &rhs):categoria(rhs.categoria){
}

Categoria::~Categoria(){
}

string Categoria::get_categoria(){
	return categoria;
}

void Categoria::set_categoria(string categoria){
	this->categoria = categoria;
}
