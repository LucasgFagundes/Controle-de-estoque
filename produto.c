#include <stdio.h>
#include "produto.h"
#include <windows.h>
Produto Produtos[100];
int QtdeProdutos = 0;
Produto DigitarProduto()
{
    struct produto p;

    gotoxy(10, 5);
    scanf("%d", &p.Codigo);
    gotoxy(14, 8);


    scanf(" %[^\n]", p.Descricao);
    gotoxy(9, 11);


    scanf("%lf", &p.Preco);
    gotoxy(9, 14);


    scanf("%d", &p.saldo);
    system("cls");
    return p;
}
void MostrarTelaProduto()
{
system("cls");
    Borda(0, 0, 64, 24, 1, 0);
    gotoxy(11, 2);
    printf("Cadastro de Produtos");
    gotoxy(2, 5);
    printf("Codigo: ");
    Borda(9, 4, 6, 2, 0, 0);
    gotoxy(2, 8);
    printf("Descricao: ");
    Borda(12, 7, 15, 2, 0, 0);
    gotoxy(2, 11);
    printf("Preco: ");
    Borda(8, 10, 8, 2, 0, 0);
    gotoxy(2, 14);
    printf("Saldo: ");
    Borda(8, 13, 6, 2, 0, 0);
    /*    Borda(3, 17, 4, 2, 1, 0);
          gotoxy(4, 18);
     printf("Novo");

     Borda(14, 17, 9, 2, 1, 0);
      gotoxy(15, 18);
     printf("Pesquisar");

         Borda(29, 17, 7, 2, 1, 0);
      gotoxy(30, 18);
     printf("Alterar");
    */



}
void ImprimirProduto(Produto p)
{
    void MostrarTelaProduto();
    gotoxy(10, 5);
    printf("%d", p.Codigo);
    gotoxy(14, 8);
    printf("%s", p.Descricao);
    gotoxy(9, 11);
    printf("%.2lf", p.Preco);
    gotoxy(9, 14);
    printf("%d", p.saldo);
    getch();



}
void ListarProdutos()
{
  int n;
    if(QtdeProdutos == 0)
    {
        return 0;

    }
    for(n = 0;  n < QtdeProdutos; n++)
    {
        ImprimirProduto(Produtos[n]);

    }


}

void PesquisaProduto()
{
    int Codigo, n;
    gotoxy(10, 5);
    scanf("%d", &Codigo);
    for(n = 0; n < QtdeProdutos; n++)
    {
        if(Produtos[n].Codigo == Codigo)
        {
            ImprimirProduto(Produtos[n]);
            getch();
        }



    }




}

int menuProduto()
{
    int Opcao, i = 0;
    char Opcoes[][21] = {"Novo", "Pesquisar", "Altera", "Listar", "Excluir", "Sair"};
    int x[] = {2, 11, 25, 36, 48, 60};
    int y[] = {20, 20, 20, 20,20, 20};
    do
    {
 MostrarTelaProduto();
        Opcao = Menu(Opcoes, x, y, 6);


        if(Opcao == 0)
        {

            Produtos[QtdeProdutos] = DigitarProduto();
            QtdeProdutos++;
        }
        if(Opcao == 3)
        {

            ImprimirProduto(Produtos[QtdeProdutos]);

        }

        if(Opcao == 1)
        {
            PesquisaProduto();


        }

        if(Opcao == 2)
        {


        }
    }
    while(Opcao != 5);
    system("cls");
    return Opcao;
}



