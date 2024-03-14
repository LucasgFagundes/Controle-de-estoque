#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED
struct produto{
 int Codigo;
    char Descricao[51];
    double Preco;
    int saldo;
};

typedef struct produto Produto;

struct produto DigitarProduto();
void ImprimirProduto();
void ListarProdutos();
int menuProduto();

#endif // PRODUTO_H_INCLUDED
