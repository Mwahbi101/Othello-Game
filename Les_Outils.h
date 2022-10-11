#ifndef LES_OUTILS_H_INCLUDED
#define LES_OUTILS_H_INCLUDED
#endif // LES_OUTILS_H_INCLUDED

void color(int k);
void start();
void modes();
void setting();
char grille(char board[8][8]);
void Display(char board[8][8]);
int case_existe (int lig,int col);
int coup_valide1 (char board[8][8],int lig,int col,int joueur);
int can_play (char board[8][8], int joueur);
int next_player(int joueur);
void choice(char board[8][8], int *lig, int *col, int joueur);
int game_over (char board[8][8]);
void Play(char board[8][8], int lig, int col, int joueur);
void quoif(char board[8][8],int joueur);
void remove_pt(char board[8][8]);
void with_help();
void without_help();
void EXIT();
