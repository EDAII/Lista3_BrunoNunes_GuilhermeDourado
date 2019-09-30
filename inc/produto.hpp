#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include "categoria.hpp"
#include <string>
#include <fstream>

using namespace std;

class Produto: public Categoria{

	private:
		string nome;
		float valor;
		int quantidade;
	public:
		Produto();
		Produto(string categoria);
		Produto(string nome, float valor, int quantidade);
		Produto(string nome, string categoria, float valor, int quantidade);
		Produto(const Produto &rhs);
		~Produto();

		string get_nome();
		void set_nome(string  nome);

		float get_valor();
		void set_valor(float valor);

		int get_quantidade();
		void set_quantidade(int quantidade);

		void salvar_info();

};


#endif
