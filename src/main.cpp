#include "main.hpp"

using namespace std;

int main(){

	string nome;
	string categoria;
	float valor;
	int quantidade;
	string nomeCliente;
	string cpf;
	char socio;
	float fechar_caixa = 0;
	char verificador;
	int opcao;
	int opcao2;
	int opcao3;
	string line;
	int final;
	int contadorAnterior;
	int contadorAtual;

	vector<string> lista_recomendacoes2;
	vector<string> lista_recomendacoes;
	vector<Categoria * > categorias;
	vector<Categoria * > recomendacoes;
	vector<Produto *> produtos;
	vector<Cliente *> clientes;
	vector<Produto *> recom_produtos;
	vector<Produto *> recom_produtos2;


	cout << fixed << setfill ('0') << setw(6) << setprecision(2);

	//clientes.push_back(new Cliente("Amanda", "95203826234", 'S'));

	ifstream arquivo("doc/produtos.txt");
	if(arquivo.is_open()){

		arquivo.seekg(0, ios_base::end);
		final = arquivo.tellg();
		arquivo.seekg(0, ios_base::beg);

		if(final == 0) throw 1;

		do{
				getline (arquivo, line);
				nome = line;
				getline (arquivo, line);
				categoria = line;
				getline (arquivo, line);
				valor = std::stof(line, nullptr);
				getline (arquivo, line);
				quantidade = stoi(line, nullptr ,10);

				if(valida(categoria, categorias)){
						produtos.push_back(new Produto(nome,categoria,valor,quantidade));
				}else{
						categorias.push_back(new Produto(nome,categoria,valor,quantidade));
						produtos.push_back(new Produto(nome,categoria,valor,quantidade));
					}


				getline (arquivo, line);

			}	while(arquivo.tellg() != final);

			arquivo.close();

			line = "";

			ifstream clienteInput("doc/cliente.txt");
			if(clienteInput.is_open()){

				clienteInput.seekg(0, ios_base::end);
				final = clienteInput.tellg();
				clienteInput.seekg(0, ios_base::beg);

				if(final == 0) throw 1;

				cout << final << endl;

				do{
					getline (clienteInput, line);
					nomeCliente = line;
					getline (clienteInput, line);
					cpf = line;
					getline (clienteInput, line);
					socio = line[0];

					cout << nomeCliente << endl;
					cout << cpf << endl;
					cout << socio << endl;

					clientes.push_back(new Cliente (nomeCliente,cpf,socio));
					getline (clienteInput, line);

					for( ; line != "$"; getline (clienteInput, line))
					inserir_cliente(cpf, clientes)->recomendacoes.push_back(new Categoria(line));

					cout << clienteInput.tellg() << endl;

				} while(clienteInput.tellg() != final);

			} else cout << "Arqvuio cliente.txt nao encontrado";

	}else cout << "Arquivo produto.txt nao encontrado";



	do{

	system("clear");

	cout << "====================================" << endl;
	cout << "|        Mercado da Victoria       |" << endl;
  cout << "====================================" << endl;;
	cout << "|  1. Modo Venda                   |" << endl;
	cout << "|  2. Modo Estoque                 |" << endl;
	cout << "|  3. Modo Recomendacao            |" << endl;
	cout << "|  0. Sair                         |" << endl;
	cout << "====================================" << endl;

	cin >> opcao;

	switch(opcao){
		case 1:
		//MODO VENDA

			do{

				system("clear");

				cout << "====================================" << endl;
				cout << "|        Mercado da Victoria       |" << endl;
				cout << "|           MODO VENDA             |" << endl;
     		cout << "====================================" << endl;
				cout << "|  1. Venda Cliente                |" << endl;
      	cout << "|  2. Fechar Caixa                 |" << endl;
				cout << "|  0. Voltar                       |" << endl;
				cout << "====================================" << endl;

				opcao3 = getInput<int>();

				switch(opcao3){
					case 1:

					system("clear");

					cout << "Insira o CPF do cliente: " << endl;
					cpf = getInput<string>();

						if(!busca_cliente(cpf, clientes)){

						cout << "Cliente nao cadastrado, faca o cadastro" << endl;

						cout << "Insira o nome do cliente: " << endl;
						nomeCliente = getInput<string>();
						cout << "O cliente eh socio(s\\N): " << endl;
						socio = getInput<char>();

						clientes.push_back(new Cliente(nomeCliente, cpf, socio));


						}

						socio = inserir_cliente(cpf, clientes)->get_socio();

						inserir_cliente(cpf, clientes)->lista_produtos.clear();

					system("clear");

					do{

					cout << "Nome: " << inserir_cliente(cpf, clientes)->get_nomeCliente() << endl;
					cout << "CPF: " << inserir_cliente(cpf, clientes)->get_cpf() << endl;
					cout << "Socio: " << inserir_cliente(cpf, clientes)->get_socio() << endl << endl;

					for(Produto * produ : (inserir_cliente(cpf, clientes)->lista_produtos) ){
							cout << produ->get_nome() << endl;
							cout << produ->get_quantidade() <<"UN        X" << inserir(produ->get_nome(), produtos)->get_valor() << endl;
							cout << "--------------------  R$" << produ->get_valor() << endl;
						}

					cout << "Digite o nome do produto: ";

					nome = getInput<string>();

					putchar('\n');

					  if(busca(nome, produtos)){
							cout << inserir(nome, produtos)->get_nome() << endl;
							cout << "--------------------  R$" << inserir(nome,produtos)->get_valor() << endl;
							cout << "Qtd: ";
							quantidade = getInput<int>();
							if(quantidade <= (inserir(nome,produtos)->get_quantidade()) && inserir(nome,produtos)->get_quantidade() >= 1){
								valor = inserir(nome,produtos)->get_valor() * quantidade;
								cout << "--------------------  R$" << valor << endl;
								categoria = inserir(nome,produtos)->get_categoria();
								inserir_cliente(cpf, clientes)->lista_produtos.push_back(new Produto(nome, categoria, valor, quantidade));
								inserir_cliente(cpf, clientes)->recomendacoes.push_back(new Categoria(categoria));
								quantidade = inserir(nome,produtos)->get_quantidade() - quantidade;
								inserir(nome,produtos)->set_quantidade(quantidade);
							} else (inserir(nome,produtos)->get_quantidade() == 0) ? cout << "Produto esgotado" << endl : cout << "Quantidade ultrapassa numero de produtos!" << endl;


						} else cout << "Produto nao encontrado" << endl;

							cout << "Deseja adicionar mais um produto(s\\N): ";
							verificador = getInput<char>();

							system("clear");

						}while(verificador!='N');

							cout << "Nome: " << inserir_cliente(cpf, clientes)->get_nomeCliente() << endl;
							cout << "CPF: " << inserir_cliente(cpf, clientes)->get_cpf() << endl;
							cout << "Socio: " << inserir_cliente(cpf, clientes)->get_socio() << endl << endl;

							valor = 0;
							quantidade = 0;

						for(Produto * produ : (inserir_cliente(cpf, clientes)->lista_produtos) ){
							cout << produ->get_nome() << endl;
							cout << produ->get_quantidade() <<"UN        X" << inserir(produ->get_nome(), produtos)->get_valor() << endl;
							cout << "--------------------  R$" << produ->get_valor() << endl;

								valor += produ->get_valor();
								quantidade += produ->get_quantidade();
							}

							cout << "===================================" << endl;

							if(valor != 0){

								cout << "PRECO NORMAL" << endl;
							cout << "Qtd. Total de Itens:       " << quantidade << endl;
								cout << "--------------------  R$" << valor << endl;

								if(socio == 's' || socio == 'S'){

									cout << "===================================" << endl;

									cout << "DESCONTO TOTAL" << endl;
									cout << "--------------------  R$" << valor*0.15 << endl;

									valor = valor*0.85;

									cout << "VALOR TOTAL" << endl;
									cout << "--------------------  R$" << valor<< endl;
								}else cout << "Ainda nao eh socio? vire agora um \nassociado para receber descontos!" << endl;

								fechar_caixa += valor;

									cout << "===================================" << endl;

						}else cout << "Nenhum produto comprado" << endl;

							system("read");
							break;

						case 2:
							system("clear");
							cout << "O montante dessa sessao foi de R$" << fechar_caixa << endl;
							system("read");

							break;

						default: break;
			}

			ofstream myfile2("doc/cliente.txt");

			if(myfile2.is_open()){
				myfile2.close();
			}else cout << "Impossibilitado de abrir o arquivo";

			for(Cliente * cli : clientes) {
				cli->salvar_cliente();
			}

		}while (opcao3!=0);

		break;

		case 2:
		//MODO ESTOQUE
		do{
			system("clear");

			cout << "====================================" << endl;
			cout << "|        Mercado da Victoria       |" << endl;
			cout << "|           MODO ESTOQUE           |" << endl;
     	cout << "====================================" << endl;
			cout << "|  1. Visualizar produtos          |" << endl;
      cout << "|  2. Visualizar categorias        |" << endl;
			cout << "|  3. Atualizar produto            |" << endl;
			cout << "|  4. Adicionar produto novo       |" << endl;
			cout << "|  0. Voltar                       |" << endl;
			cout << "====================================" << endl;

			opcao2 = getInput<int>();

			system("clear");

			switch(opcao2){
				case 1:

					cout << "---------" << produtos[0]->get_categoria() << "---------" << endl;
					categoria = produtos[0]->get_categoria();

              			for(Produto * pro : produtos) {
											if(categoria != pro->get_categoria()){
											cout << "---------" << pro->get_categoria() << "---------" << endl;
											categoria = pro->get_categoria();
										}
                      cout << "Nome: " << pro->get_nome() << endl;
                      cout << "Valor: R$" << pro->get_valor() << endl;
                      cout << "Quantidade: " << pro->get_quantidade() << endl << endl;
                    }
                    system("read");
					break;

				case 2:

                    cout << "Categorias: " << endl;

                    for(Categoria * cat : categorias) {

                        cout << "            " << cat->get_categoria() << endl;
                    }
                    system("read");
                    break;

				case 3:

									cout << "Insira o nome do produto registrado: ";
									nome = getInput<string>();

									if(busca(nome, produtos)){
										cout << "Selecione o valor do produto: ";
										inserir(nome, produtos)->set_valor(getInput<float>());
										cout << "Selecione a quantidade do produto: ";
									  inserir(nome, produtos)->set_quantidade(getInput<int>());
										break;
									}else cout << "Produto nao registrado" << endl;
									system("read");

									break;

				case 4:

									cout << "Nome: ";
									nome = getInput<string>();
									cout << "Categoria: ";
									categoria = getInput<string>();
									cout << "Valor: ";
									valor = getInput<float>();
									cout << "Quantidade: ";
									quantidade = getInput<int>();

										if(valida(categoria, categorias)){
												produtos.push_back(new Produto(nome,categoria,valor,quantidade));
										}else{
												categorias.push_back(new Produto(nome,categoria,valor,quantidade));
												produtos.push_back(new Produto(nome,categoria,valor,quantidade));
											}

									lista_recomendacoes.clear();
									recom_produtos.clear();
									recom_produtos2.clear();

									categoria = "";

									for(Categoria * cat : categorias){
											if(cat->get_categoria() != categoria)
											lista_recomendacoes.push_back(cat->get_categoria());
											categoria = cat->get_categoria();
										}

									sort(lista_recomendacoes.begin(), lista_recomendacoes.end());

										system("read");

									for(string cat2: lista_recomendacoes){
										lista_recomendacoes2.clear();
										for(Produto * pr : produtos){
												if(cat2 == pr->get_categoria()){
													lista_recomendacoes2.push_back(pr->get_nome());
												}
											}
										sort(lista_recomendacoes2.begin(), lista_recomendacoes2.end());
											for(string pr2: lista_recomendacoes2){

													recom_produtos.push_back(new Produto(inserir(pr2, produtos)->get_nome(), inserir(pr2, produtos)->get_categoria(), inserir(pr2, produtos)->get_valor(), inserir(pr2, produtos)->get_quantidade()));
											}
									}

									produtos = recom_produtos;
									break;

				default: break;

			}
		}while (opcao2!=0);

			break;

		case 3:

		do{

		system("clear");

		cout << "====================================" << endl;
		cout << "|        Mercado da Victoria       |" << endl;
		cout << "|         MODO RECOMENDACAO        |" << endl;
		cout << "====================================" << endl;
		cout << "|  1. Visualizar recomendacoes     |" << endl;
		cout << "|  0. Voltar                       |" << endl;
		cout << "====================================" << endl;

		opcao2 = getInput<int>();

		switch (opcao2!=0) {
			case 1:

			lista_recomendacoes.clear();
			recom_produtos.clear();
			recom_produtos2.clear();

				system("clear");

			cout << "Insira o cpf do cliente: " << endl;
			cpf = getInput<string>();

			if(busca_cliente(cpf, clientes)){

				system("clear");

				cout << "Nome: " << inserir_cliente(cpf, clientes)->get_nomeCliente() << endl;
				cout << "CPF: " << inserir_cliente(cpf, clientes)->get_cpf() << endl << endl;

				recomendacoes = inserir_cliente(cpf, clientes)->recomendacoes;

				for(Categoria * cat : recomendacoes)
					lista_recomendacoes.push_back(cat->get_categoria());

				sort(lista_recomendacoes.begin(), lista_recomendacoes.end());

				for(std::vector<string>::iterator it2 = lista_recomendacoes.begin(); it2!=lista_recomendacoes.end(); it2++){
					if(busca(*it2, recom_produtos)){
							quantidade = inserir(*it2, recom_produtos)->get_quantidade();
							inserir(*it2, recom_produtos)->set_quantidade(quantidade+1);
					}else recom_produtos.push_back(new Produto(*it2, *it2, 0, 1));
				}

				while (!recom_produtos.empty()){
				final = -1;
				contadorAnterior = 0;
					for(Produto * proc : recom_produtos){
						final++;
						contadorAtual = proc->get_quantidade();
						if(contadorAtual > contadorAnterior){
							contadorAnterior = contadorAtual;
							quantidade = final;
							categoria = proc->get_nome();
						}
					}


					recom_produtos2.push_back(new Produto(categoria));
					recom_produtos.erase (recom_produtos.begin() + quantidade);



				}

				//VER AS CATEGORIAS ORDENADAS
				//for(Categoria * wtf : recom_produtos2) cout << wtf->get_categoria() << endl;

				final = 0;

					 	for (Produto * rec : recom_produtos2){
							for (Produto * pro : produtos){
							if(final < 10 && pro->get_categoria() == rec->get_categoria()){
							recom_produtos.push_back(new Produto (pro->get_nome(), pro->get_categoria(), pro->get_valor(), pro->get_quantidade()));
							final++;
						}
					}
					if(final > 9) break;
				}

				categoria = recom_produtos[0]->get_categoria();
				cout << "---------" << recom_produtos[0]->get_categoria() << "---------" << endl;

				for(Produto * produc : recom_produtos){
					if(produc->get_categoria() != categoria){
					cout << "---------" << produc->get_categoria() << "---------" << endl;
					categoria = produc->get_categoria();
				}

					cout << "Nome: " <<produc->get_nome() << endl;
					cout << "Valor: R$" << produc->get_valor() << endl;
					cout << "Quantidade: " << produc->get_quantidade() << endl<< endl;

				}

			}else throw 1;

					system("read");

			default : break;
		}
	}while(opcao2 != 0);
		default: break;

}

	}
	while(opcao!=0);




	ofstream myfile("doc/produtos.txt");

	if(myfile.is_open()){
		myfile.close();
	}else cout << "Impossibilitado de abrir o arquivo";

	for(Produto * v : produtos) v->salvar_info();

	return 0;
}
