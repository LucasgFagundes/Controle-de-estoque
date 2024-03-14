#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "produto.h"
#include "cliente.h"

int main()
{
    int Opcao, i, codigo, quem, codigop, oque;
    do
    {

        Opcao = TelaPrincipal();

        if( Opcao == 0)
        {
            system("cls");
            Borda(0, 0, 55, 13, 1, 0);
            gotoxy(22, 2);
            printf("Menu Produto");
            gotoxy(22, 3);

            printf("------------");
            gotoxy(22, 5);
            printf("1 - Produto");
            gotoxy(22, 7);
            printf("2 - Cliente");
            gotoxy(22, 9);
            printf("0 - Sair");
            gotoxy(22, 11);
            printf("Escolha: ");
            Borda(30, 10, 2, 2, 0, 0);
            gotoxy(31, 11);
            scanf("%d", &quem);



            if(quem == 1)
            {

                menuProduto();


            }

            else if(quem == 2)
            {

                menuCliente();
            }
        }
        else if(Opcao == 1)
        {

            Rotinas();
        }
        else if(Opcao == 2)
        {

            Relatorios();
        }
        else if(Opcao == 3)
        {
            break;
        }

    }
    while(quem != 0);


    return 0;
}
