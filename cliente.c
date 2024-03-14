#include <stdio.h>
#include "cliente.h"
#include <windows.h>
Cliente Clientes[100];
int  Nclientes = 0;
Cliente DigitarCliente()
{
    Cliente Clientes;
    printf("Digite o Codigo do Cliente: ");
    scanf("%d", &Clientes.Codigo);
    printf("Nome: ");
    scanf(" %[^\n]", Clientes.Nome);
    printf("Endereco: ");
    scanf(" %[^\n]", Clientes.Endereco);
    printf("Telefone: ");
    scanf("%d", &Clientes.Telefone);
    return Clientes;
}

void ImprimirCliente(Cliente Clientes)
{

    printf("\n\nCodigo: %d\n", Clientes.Codigo);
    printf("Endereco: %s\n", Clientes.Endereco);
    printf("Nome: %s\n", Clientes.Nome);
    printf("Telefone: %d\n\n", Clientes.Telefone);



}




void PesquisaCliente(Cliente Clientes[], int Nprodutos)
{
    int Codigo, n;
    printf("Digite o codigo do cliente:");
    scanf("%d", &Codigo);
    for(n = 0; n < Nprodutos; n++)
    {
        if(Clientes[n].Codigo == Codigo)
        {
            ListarClientes(Clientes[n], Nprodutos);
        }



    }
}

void ListarClientes(Cliente Clientes[], int Nprodutos)
{
    int n;
    if(Nprodutos == 0)
    {
        return 0;

    }
    for(n = 0;  n < Nprodutos; n++)
    {
        ImprimirCliente(Clientes[n]);

    }


}

void menuCliente()
{
    int Opcao, i = 0;


    do
    {

    interfacecliente();
     /*   printf("Cliente");
        printf("1 - Novo Cliente");
        printf("2 - Pesquisar Cliente");
        printf("3 - Alterar cadastro");
        printf("4 - Excluir Cliente");
        printf("5 - Listar Cliente");
        printf("0 - Voltar\n\n");
        printf("Escolha: ");*/
        scanf("%d", &Opcao);
        if(Opcao == 1)
        {
            Clientes[Nclientes] = DigitarCliente();
            Nclientes++;
        }
        if(Opcao == 5)
        {
            for(i = 0; i < Nclientes; i++)
            {
                ImprimirCliente(Clientes[i]);
            }
        }

        if(Opcao == 2)
        {
            PesquisaCliente(Clientes, Nclientes);

        }
    }
    while(Opcao != 0);

}


void interfacecliente()
{

    Borda(0, 0, 60, 24, 1, 0);
    gotoxy(11, 2);
    printf("Clientes");
    gotoxy(2, 5);
    printf("Codigo");
    Borda(9, 4, 6, 2, 0, 0);
    gotoxy(2, 8);
    printf("Nome");
    Borda(9, 7, 35, 2, 0, 0);
    gotoxy(2, 11);
    printf("Endereco");
    Borda(11,10 , 35, 2, 0, 0);
    gotoxy(2, 14);
    printf("Telefone");
    Borda(11,13 , 35, 2, 0, 0);
}

