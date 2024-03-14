#include <stdio.h>
#include "interface.h"
#include <windows.h>
#include <windows.h>


int getTecla()
{
    int ch;
    ch = getch();
    if(ch == 224)
    {
        ch = getch() + 1000;
    }
    return ch;
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
enum DOS_COLORS
{
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
    LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
    LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE
};

void textcolor (int iColor)
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

void textbackground (int iColor)
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x000F;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (iColor << 4));
}


void Borda(int x, int y, int largura, int altura, int tipo, int sombra)     // EsqSup DirSup EsqInf DirInf LHoriz LVertical
{
    char C[][6] = {"\xda\xbf\xc0\xd9\xc4\xb3",
                   "\xc9\xbb\xc8\xbc\xcd\xba"
                  };
    int i, j;
    gotoxy(x, y);
    printf("%c", C[tipo][0]);
    for(i = 0; i < largura; i++) printf("%c", C[tipo][4]);
    printf("%c", C[tipo][1]);
    for(j = 0; j < altura; j++)
    {
        gotoxy(x, y+j+1);
        printf("%c", C[tipo][5]);
        for(i = 0; i < largura; i++) printf(" ");
        printf("%c", C[tipo][5]);
        if(sombra) printf("\xb2");
    }
    gotoxy(x, y+altura);
    printf("%c", C[tipo][2]);
    for(i = 0; i < largura; i++) printf("%c", C[tipo][4]);
    printf("%c", C[tipo][3]);
    if(sombra)
    {
        gotoxy(x+1, y+altura+1);
        for(i = 0; i < largura+2; i++) printf("\xb2");
    }
}


int Menu(char Opcoes[][21], int x[], int y[], int N)
{

    int Tecla;
    int Opcao = 0;
    textbackground(BLACK);
    textcolor(WHITE);
    for(int i = 0; i < N; i++)
    {
        gotoxy(x[i], y[i]);
        printf("%s", Opcoes[i]);
    }
    do
    {
        textbackground(WHITE);
        textcolor(BLACK);
        gotoxy(x[Opcao], y [Opcao]);
        printf("%s", Opcoes[Opcao]);
        Tecla = getTecla();
        textbackground(BLACK);
        textcolor(WHITE);
        gotoxy(x[Opcao], y [Opcao]);
        printf("%s", Opcoes[Opcao]);
        if(Opcao == 13)break;
        if(Tecla == TEC_DIR) Opcao++;
        if(Tecla == TEC_ESQ) Opcao--;
        if(Opcao == N)Opcao = 0;
        if(Opcao < 0) Opcao = N - 1;

    }
    while(Tecla != 13);
    return Opcao;

}

int TelaPrincipal()
{
    int opcao;
    char Opcoes[][21] = {"Cadastros", "Rotinas", "Relatorios","Sair"};
    int x[] = {2, 17, 32, 48};
    int y[] = {2, 2, 2, 2};
    Borda(0, 0, 55, 13, 1, 0);
    gotoxy(2, 5);
    printf("\xc9\xcd\xbb\xc9\xcd\xbb\xc9\xbb\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\n");
       gotoxy(2, 6);
printf("\xba\xcb\xbc\xba\xcd\xb9\xba\xc8\xbb\xc9\xcd\xbb\xc9\xcd\xbb\xc9\xcb\xbb\xc9\xcd\xbb\n");
   gotoxy(2, 7);
printf("\xba\xca\xbb\xcc\xcd\xba\xba\xc9\xb9\xba\xce\xba\xba\xce\xba\xba\xba\xba\xba\xca\xb9\n");
   gotoxy(2, 8);
printf("\xc8\xcd\xbc\xc8\xcd\xbc\xc8\xcd\xbc\xc8\xcd\xbc\xc8\xbb\xba\xc8\xcd\xbc\xc8\xcd\xbc\n");
   gotoxy(2, 9);
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc8\xbc\xc4\xc4\xc4\xc4\xc4\xc4\n");
     gotoxy(23, 12);
    printf("Copyright Lucas @2023 Versao 0.2");
    opcao = Menu(Opcoes, x, y, 4);

    gotoxy(2, 2);
    printf("Cadastros");
    gotoxy(17, 2);
    printf("Rotinas");
    gotoxy(32, 2);
    printf("Relatorios");
    gotoxy(48, 2);
    printf("Sair");

    return opcao;
}


void Rotinas()
{
    system("cls");
    Borda(0, 0, 30, 13, 1, 0);
    gotoxy(13, 2);
    printf("Vendas");
    getch();
}

void Relatorios()
{
    system("cls");
    Borda(0, 0, 30, 13, 1, 0);
    gotoxy(6, 2);
    printf("Tabela de Precos");
    gotoxy(6, 4);
    printf("Relatorio de Vendas");
    getch();
}


