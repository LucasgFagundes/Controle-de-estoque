#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#define TEC_ENTER 13
#define TEC_TAB 9
#define TEC_BACKSPACE 8
#define TEC_ESC 27
#define TEC_DIR 1077
#define TEC_ESQ 1075
#define TEC_BAIXO 1080
#define TEC_CIMA 1072
#define TEC_DEL 1083
#define TEC_END 1079
#define TEC_INSERT 1082
#define TEC_HOME 1071
#define TEC_PAGE_UP 1073
#define TEC_PAGE_DOWN 1081
int getTecla();
void gotoxy(int x, int y);
enum DOS_COLORS;
void textcolor (int iColor);
void textbackground (int iColor);
void Borda(int x, int y, int largura, int altura, int tipo, int sombra);
void menuinicial();
int TelaPrincipal();

#endif // INTERFACE_H_INCLUDED
