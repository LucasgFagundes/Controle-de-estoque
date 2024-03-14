#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
struct cliente
{
    int Codigo;
    char Nome[51];
    char Endereco[71];
    int Telefone;
};
typedef struct cliente Cliente;
struct cliente DigitarCliente();
void PesquisaCliente(Cliente Clientes[], int Nprodutos);
void ImprimirCliente(Cliente Clientes);
void menuCliente();


#endif // CLIENTE_H_INCLUDED
