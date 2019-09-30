#ifndef CATEGORIA_HPP
#define CATEGORIA_HPP
#include <string>

using namespace std;

class Categoria{

	private:
		string categoria;
	public:
		Categoria();
		Categoria(string categoria);
		Categoria (const Categoria &rhs);
		~Categoria();

		string get_categoria();
		void set_categoria(string categoria);

};

#endif
