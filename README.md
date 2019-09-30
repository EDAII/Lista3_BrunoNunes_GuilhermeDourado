# Lista3_BrunoNunes_GuilhermeDourado

O programa deve ser executado num sistema Linux ou Mac, pois utiliza system("read").
Caso seja executado em Windows, mudar os **system("read")** para **system("pause")**.
Versao do kernel linux 5.2.17-200.fc30.x86_64;

Tenha o *make* e o compilador *c++* instalado na maquina.
Para compilar o programa:

`make`

Para executar o programa:

`make run`

Para limpar os arquivos .o e bin do programa:

`make clean`


O programa consiste num mercado virtual, onde nele tem 3 modulos de operacao, 
venda, estoque e recomendacao.

O modo venda tem o registro no caixa dos produtos que o usuario quer comprar.
Caso o CPF do usuario nao seja encontrado, tem-se a criacao de um novo usuario.

O modo estoque, pode se visualizar os produtos do mercado, todos os produtos estao
ordenados por categoria e nome do produto. Pode-se tambem adicionar produtos e atua-
lizar os produtos do estoque.

O modo recomendacao, mostra a partir do CPF do cliente os produtos recomendados a 
partir do produtos mais comprados pelo mesmo cliente.

Obs.: Caso tenha erros no programa, provavelmente a lista *cliente.txt* e *produto.txt* 
nao foram carregadas, ou CPF foram inseridos erroneamente.
