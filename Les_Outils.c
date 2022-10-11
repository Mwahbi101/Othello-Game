#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define VIDE ' '

void color(int k)
{/*la coloration de la grille et le texte souhaité*/
  HANDLE  hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);

}

void start(){/*affichage de l'insertion « Othello », et le menu, ainsi que le message qui demande à l’utilisateur de choisir l’une des options de la menu.*/
    color(11);
    printf("\t\t  _____________________________________________________________________________________     \n");
    printf("\t\t                                                                                            \n");
    printf("\t\t      OOOOOOO   TTTTTTTTT  H        H  EEEEEEEEEE   L           L          OOOOOOO             \n");
    printf("\t\t     O       O      T      H        H  E            L           L         O       O           \n");
    printf("\t\t     O       O      T      HHHHHHHHHH  EEEEEEEEEE   L           L         O       O             \n");
    printf("\t\t     O       O      T      H        H  E            L           L         O       O             \n");
    printf("\t\t      OOOOOOO       T      H        H  EEEEEEEEEE   LLLLLLLLL   LLLLLLLLL  OOOOOOO                 \n");
    printf("\t\t  _____________________________________________________________________________________     \n\n\n");color(12);
    printf("\t\t +--+--+--+--+--+--+--+--+--+--+--+--+  MENU   +--+--+--+--+--+--+--+--+--+--+--+--+--+\n");
    printf("\t\t |                                                                                    |\n");
    printf("\t\t +                                                                                    +\n");
    printf("\t\t |                                 ----------------                                   |\n");
    printf("\t\t +                                 1- Play                                            +\n");
    printf("\t\t |                                 ----------------                                   |\n");
    printf("\t\t +                                 2- Setting                                         +\n");
    printf("\t\t |                                 ----------------                                   |\n");
    printf("\t\t +                                 3- Exit                                            +\n");
    printf("\t\t |                                                                                    |\n");
    printf("\t\t +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+---+--+--+--+--+--+--+--+--+--+\n");color(11);

    printf("\n\n\n\t\t                                      choose 1,2 or 3\n\n\n");}

void modes(){color(12);/*affichage de menu des modes*/
    printf("\t\t +--+--+--+--+--+--+--+--+--+--+--+--+ PLAY MODE +--+--+--+--+--+--+---+--+--+--+--+--+\n");
    printf("\t\t |                                                                                    |\n");
    printf("\t\t +                                                                                    +\n");
    printf("\t\t |                                 -------------------                                |\n");
    printf("\t\t +                                 1- man vs man                                      +\n");
    printf("\t\t |                                 -------------------                                |\n");
    printf("\t\t +                                 2- man vs machine (easy)                           +\n");
    printf("\t\t |                                 -------------------                                |\n");
    printf("\t\t +                                 3- man vs machine (hard)                           +\n");
    printf("\t\t |                                                                                    |\n");
    printf("\t\t +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+---+--+--+--+--+--+--+--+--+--+\n");color(11);
        printf("\n\t\t                                      choose your mode:");
            }


void setting(){/*affichage de menu des sitting*/
    color(12);
    printf("\t\t +--+--+--+--+--+--+--+--+--+--+--+--+  SETTING  +--+--+--+--+--+--+---+--+--+--+--+--+\n");
    printf("\t\t |                                                                                    |\n");
    printf("\t\t +                                  DO YOU WANT HELP                                  +\n");
    printf("\t\t |                                                                                    |\n");
    printf("\t\t +                                                                                    +\n");
    printf("\t\t |                 | 1- YES |                               | 2- NO |                 |\n");
    printf("\t\t +                                                                                    +\n");
    printf("\t\t |                                                                                    |\n");
    printf("\t\t +                                                                                    +\n");
    printf("\t\t |                                                                                    |\n");
    printf("\t\t +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+---+--+--+--+--+--+--+--+--+--+\n");color(11);
    printf("\n\t\t                                        YES OR NO:");
}
/**********************************************************************************************************/
char grille(char board[8][8]){/* la fonction qui fait l’initialisation de la grille */
    /* On met tout a vide */
    for (int i=0; i<8; i++)
        for (int j=0; j<8; j++)
            board[i][j] = VIDE;
    /* On place les 4 premiers pions */
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
                if ((i==3 && j==3) || (i==4 && j==4)) board[i][j]= 'W';
                else if ((i==3 && j==4) || (i==4 && j==3)) board[i][j]= 'B';
        }
    }
}
/**********************************************************************************************************/
void Display(char board[8][8]){/* Fonction pour afficher la grille */

    printf("\t\t                     ");color(47);
    printf("  |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |\n");color(1);
    for(int i=0;i<8;i++){
    printf("\t\t                     ");color(47);
    printf("  +-----+-----+-----+-----+-----+-----+-----+-----+\n");color(1);
    printf("\t\t                     ");color(47);
    printf("%d |",i);
    for(int j=0;j<8;j++){
            if (board[i][j]=='W'){color(47);printf("  %c  ",board[i][j]);}/*Affichge des pions blancs*/
            else if (board[i][j]=='B') {color(32);printf("  %c  ",board[i][j]);}/*Affichge des pions noirs*/
            else {color(47);printf("  %c  ",board[i][j]);}color(47);/*Affichge des couops possibles*/
            printf("|");
    }
    printf("\n");color(11);
    }
    printf("\t\t                     ");color(47);
    printf("  +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf("\n");color(11);

    }
 ///****************************************************************************************************************** ///

int case_existe (int lig,int col) {/*la fonction qui teste l’existence d’une case */
    return ((col >= 0) && (col < 8) && (lig >= 0) && (lig < 8));
}
 ///****************************************************************************************************************** ///
int coup_valide1 (char board[8][8],int lig,int col,int joueur) {/*la fonction qui verifier qu'un coup est valide */
    int i, j, ok;
    char cj, ca;
/* On definit la couleur du joueur et celle de l'adversaire */
    if (joueur == 1) {
        cj = 'B';
        ca = 'W';
    }
    else {
        cj = 'W';
        ca = 'B';
    }
    if (!case_existe(lig, col) || board[lig][col] != ' ') return 0;

    /* Vertical vers le haut */
    i = lig - 1;
    ok = 0;
    while (case_existe(i, col) && board[i][col] == ca) {
        i--;
        ok = 1;
    }
    if (case_existe(i, col) && board[i][col] == cj && ok == 1) return 1;

    /* Vertical vers le bas */
    i = lig + 1;
    ok = 0;
    while (case_existe(i, col) && board[i][col] == ca) {
        i++;
        ok = 1;
    }
    if (case_existe(i, col) && board[i][col] == cj && ok == 1) return 1;

    /* Horizontal vers la gauche */
    j = col - 1;
    ok = 0;
    while (case_existe(lig, j) && board[lig][j] == ca) {
        j--;
        ok = 1;
    }
    if (case_existe(lig, j) && board[lig][j] == cj && ok == 1) return 1;

    /* Horizontal vers la droite */
    j = col + 1;
    ok = 0;
    while (case_existe(lig, j) && board[lig][j] == ca) {
        j++;
        ok = 1;
    }
    if (case_existe(lig, j) && board[lig][j] == cj && ok == 1) return 1;

    /* Diagonal \ vers le haut */
    i = lig - 1;
    j = col - 1;
    ok = 0;
    while (case_existe(i, j) && board[i][j] == ca) {
        i--;
        j--;
        ok = 1;
    }
    if (case_existe(i, j) && board[i][j] == cj && ok == 1) return 1;

    /* Diagonal \ vers le bas */
    i = lig + 1;
    j = col + 1;
    ok = 0;
    while (case_existe(i, j) && board[i][j] == ca) {
        i++;
        j++;
        ok = 1;
    }
    if (case_existe(i, j) && board[i][j] == cj && ok == 1) return 1;

    /* Diagonal / vers le haut */
    i = lig - 1;
    j = col + 1;
    ok = 0;
    while (case_existe(i, j) && board[i][j] == ca) {
        i--;
        j++;
        ok = 1;
    }
    if (case_existe(i, j) && board[i][j] == cj && ok == 1) return 1;

    /* Diagonal / vers le bas */
    i = lig + 1;
    j = col - 1;
    ok = 0;
    while (case_existe(i, j) && board[i][j] == ca) {
        i++;
        j--;
        ok = 1;
    }
    if (case_existe(i, j) && board[i][j] == cj && ok == 1) return 1;

    return 0;
}
      ///****************************************************************************************************************** ///

int can_play (char board[8][8], int joueur) {/* La fonction determine si un joueur peut encore jouer */
    int i, j;
    for (i=0; i<8; i++)
        for (j=0; j<8; j++)
            if (coup_valide1(board, i, j, joueur)) return 1; /* Le joueur peut encore jouer */

    /* Le joueur ne peut plus jouer */
    return 0;
}
 ///****************************************************************************************************************** ///
int next_player(int joueur) {/* la fonctin qui renvoie le numero du joueur suivant */
    return (joueur%2 + 1);
}
 ///****************************************************************************************************************** ///
void choice(char board[8][8], int *lig, int *col, int joueur) {/*Elle Permet au joueur de choisir un coup */
    char c,x;
    if (joueur==1){printf ("black make your move :\n");}
    else {printf ("white make your move :\n");}
    printf("COLUMN:");/*demande au joueur d’entrer la colonne souhaité*/
    scanf (" %c",&c);
    if(c=='r'|| c=='R') {printf("\n\n\n\n\n\n\n");main();}
    else if(c=='q'|| c=='Q') {printf("\n\n\n\n\n\n\n");EXIT();exit(0);}
    else {
    printf("ROW:");/*demande au joueur d’entrer la ligne souhaité*/
    scanf (" %c", &x);
    if(x=='r'|| x=='R') {printf("\n\n\n\n\n\n\n");main();}
    else if(x=='q'|| x=='Q') {printf("\n\n\n\n\n\n\n");EXIT();exit(0);}
     else {   /* On change les characters en entiers */
    (*col) = (int)(c)-48;
    (*lig)= (int)(x)-48;

    while (!coup_valide1 (board,*lig, *col, joueur)) { /* On redemande de choisir tant que le coup n'est pas accepte */
        printf ("Oops! the move is unacceptable , try again\n");
        if (joueur==1){printf ("black make your move :\n");}
        else {printf ("white make your move :\n");}
        printf("COLUMN:");
        scanf (" %c", &c);
        if(c=='r'|| c=='R') {printf("\n\n\n\n\n\n\n");main();}
        else if(c=='q'|| c=='Q') {printf("\n\n\n\n\n\n\n");EXIT();exit(0);}
        else {printf("ROW:");
        scanf (" %c", &x);
        if(x=='r'|| x=='R') {printf("\n\n\n\n\n\n\n");main();}
        else if(x=='q'|| x=='Q') {printf("\n\n\n\n\n\n\n");EXIT();exit(0);}
        /* On change les characters en entiers */
        else {(*col) = (int)(c)-48;
        (*lig)= (int)(x)-48;}}}}
}}
 ///****************************************************************************************************************** ///

int game_over (char board[8][8]) {/* Verifie si la partie est terminee */
    int i, j, nb_noir, nb_blanc;
    /* On compte les pions noirs et les blancs */
    nb_noir = 0;
    nb_blanc = 0;
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            if (board[i][j] ==' ' && (can_play(board, 1) || can_play(board, 2))) { return 0;}/* La partie n'est pas finie */
            else {
                if (board[i][j] == 'B') nb_noir++;
                else if (board[i][j] == 'W') nb_blanc++;
            }
        }
    }/* La partie est terminee, on affiche la grille et le gagnant */
    Display (board);
    if (nb_noir > nb_blanc)
        printf ("\nPlayer 1 (Black) wins !!!\n");
    else if (nb_blanc > nb_noir)
        printf ("\nPlayer 2(White) wins !!!\n");
    else printf ("\nThe two players are tied\n");
    printf("Black=%d\nWhite=%d",nb_noir,nb_blanc);/*on affiche le score */

    printf ("\n");
    return 1;
}
 /******************************************************************************************************************/
void Play(char board[8][8], int lig, int col, int joueur) {/*la fonction censée de jouer les coups et capturer les pions de l’adversaire*/
    int i, j;
    char cj, ca;

    if (joueur == 1) {
        cj = 'B';
        ca = 'W';
    } else {
        cj = 'W';
        ca = 'B';
    }
    board[lig][col] = cj;

    /* Vertical vers le haut */
    i = lig - 1;
    while (case_existe(i, col) && board[i][col] == ca) i--;
    if (case_existe(i, col) && board[i][col] == cj) {
        i = lig - 1;
        while (board[i][col] == ca) {
            board[i][col] = cj;
            i--;
        }
    }

    /* Vertical vers le bas */
    i = lig + 1;
    while (case_existe(i, col) && board[i][col] == ca) i++;
    if (case_existe(i, col) && board[i][col] == cj) {
        i = lig + 1;
        while (board[i][col] == ca) {
            board[i][col] = cj;
            i++;
        }
    }

    /* Horizontal vers la gauche */
    j = col - 1;
    while (case_existe(lig, j) && board[lig][j] == ca) j--;
    if (case_existe(lig, j) && board[lig][j] == cj) {
        j = col - 1;
        while (board[lig][j] == ca) {
            board[lig][j] = cj;
            j--;
        }
    }

    /* Horizontal vers la droite */
    j = col + 1;
    while (case_existe(lig, j) && board[lig][j] == ca) j++;
    if (case_existe(lig, j) && board[lig][j] == cj) {
        j = col + 1;
        while (board[lig][j] == ca) {
            board[lig][j] = cj;
            j++;
        }
    }

    /* Diagonal \ vers le haut */
    i = lig - 1;
    j = col - 1;
    while (case_existe(i, j) && board[i][j] == ca) {
        i--;
        j--;
    }
    if (case_existe(i, j) && board[i][j] == cj) {
        i = lig - 1;
        j = col - 1;
        while (board[i][j] == ca) {
            board[i][j] = cj;
            i--;
            j--;
        }
    }

    /* Diagonal \ vers le bas */
    i = lig + 1;
    j = col + 1;
    while (case_existe(i, j) && board[i][j] == ca) {
        i++;
        j++;
    }
    if (case_existe(i, j) && board[i][j] == cj) {
        i = lig + 1;
        j = col + 1;
        while (board[i][j] == ca) {
            board[i][j] = cj;
            i++;
            j++;
        }
    }

    /* Diagonal / vers le haut */
    i = lig - 1;
    j = col + 1;
    while (case_existe(i, j) && board[i][j] == ca) {
        i--;
        j++;
    }
    if (case_existe(i, j) && board[i][j] == cj) {
        i = lig - 1;
        j = col + 1;
        while (board[i][j] == ca) {
            board[i][j] = cj;
            i--;
            j++;
        }
    }

    /* Diagonal \ vers le bas */
    i = lig + 1;
    j = col - 1;
    while (case_existe(i, j) && board[i][j] == ca) {
        i++;
        j--;
    }
    if (case_existe(i, j) && board[i][j] == cj) {
        i = lig + 1;
        j = col - 1;
        while (board[i][j] == ca) {
            board[i][j] = cj;
            i++;
            j--;
        }
    }
}
 ///****************************************************************************************************************** ///
void quoif(char board[8][8],int joueur){
for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (coup_valide1 (board,i, j, joueur)){
                     board[i][j]= '*';}
    }}Display(board);}
 ///****************************************************************************************************************** ///
void remove_pt(char board[8][8]){
for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (board[i][j]=='*'){
                     board[i][j]= ' ';}
            }

        }}
void with_help(){
    int joueur=1,b,lig, col;
    char c;
    char board[8][8];
    modes();
    scanf(" %c",&c);
    b=(int)(c)-48;
    if(c=='r'|| c=='R') {printf("\n\n\n\n\n\n\n");main();}
    else if(c=='q'|| c=='Q') {printf("\n\n\n\n\n\n\n");EXIT();exit(0);}
    else{
    if (b==1){
    char *Quote[5]={"\t\t                        Type R to return to the menu any time you want"," ","\t\t                               Type Q to Exit any time you want"," "," "};
    for(int i=0;i<5;i++){
    printf("%s\n",Quote[i]);
    Sleep(300);}
    manvsman(board);}
    else if (b==2){    char *Quote[9]={"\t\t                        Type R to return to the menu any time you want"," ","\t\t                               Type Q to Exit any time you want"," ","\t\t                                           READY?"," "," "," ","\t\t                                           START!\n\n"};
    for(int i=0;i<9;i++){
    printf("%s\n",Quote[i]);
    Sleep(300);}
    printf("\n\n\t\t                        THE FIRST PLAYER WILL BE CHOOSEN RANDOMLY\n");
    manVsMachine(board);}
    else if (b==3){    char *Quote[9]={"\t\t                        Type R to return to the menu any time you want"," ","\t\t                               Type Q to Exit any time you want"," ","\t\t                                           READY?"," "," "," ","\t\t                                           START!\n\n"};
    for(int i=0;i<9;i++){
    printf("%s\n",Quote[i]);
    Sleep(300);}
    printf("\n\n\t\t                        THE FIRST PLAYER WILL BE CHOOSEN RANDOMLY\n");
    manVsMachine_AI(board);}
    else modes();}
}
void without_help(){
    int joueur=1,b,lig, col;
    char c;
    char board[8][8];
    modes();
    scanf(" %c",&c);
    b=(int)(c)-48;
    if(c=='r'|| c=='R') {printf("\n\n\n\n\n\n\n");main();}
    else if(c=='q'|| c=='Q') {printf("\n\n\n\n\n\n\n");EXIT();}
    else{
    if (b==1){
    char *Quote[5]={"\t\t                        Type R to return to the menu any time you want"," ","\t\t                               Type Q to Exit any time you want"," "," "};
    for(int i=0;i<5;i++){
    printf("%s\n",Quote[i]);
    Sleep(300);}
    manvsman_1(board);}
    else if (b==2){char *Quote[9]={"\t\t                        Type R to return to the menu any time you want"," ","\t\t                               Type Q to Exit any time you want"," ","\t\t                                           READY?"," "," "," ","\t\t                                           START!\n\n"};
    for(int i=0;i<9;i++){
    printf("%s\n",Quote[i]);
        Sleep(300);}
        printf("\n\n\t\t                        THE FIRST PLAYER WILL BE CHOOSEN RANDOMLY\n");
            manVsMachine_1(board);}
        else if (b==3){    char *Quote[9]={"\t\t                        Type R to return to the menu any time you want"," ","\t\t                               Type Q to Exit any time you want"," ","\t\t                                           READY?"," "," "," ","\t\t                                           START!\n\n"};
    for(int i=0;i<9;i++){
    printf("%s\n",Quote[i]);
        Sleep(300);}
        printf("\n\n\t\t                        THE FIRST PLAYER WILL BE CHOOSEN RANDOMLY\n");
        manVsMachine_AI_1(board);}
        else modes();}
}


void EXIT(){color(10);
    printf("\t\t                / .===. \\                \n");
    printf("\t\t                \\/ 6 6 \\/\                \n");
    printf("\t\t                ( \\___/ )                \n");
    printf("\t\t   _________ooo__\\_____/_____________    \n");
    printf("\t\t  /                                  \\  \n");
    printf("\t\t |      SEE                           |\n");
    printf("\t\t |          YOU                       |\n");
    printf("\t\t |              NEXT                  |\n");
    printf("\t\t |                   TIME             |\n");
    printf("\t\t |                        !!!         |\n");
    printf("\t\t  \\______________________ooo_________/  \n");
    printf("\t\t                 |  |  |                 \n");
    printf("\t\t                 |_ | _|                 \n");
    printf("\t\t                 |  |  |                 \n");
    printf("\t\t                 |_ | _|                 \n");
    printf("\t\t                 /-'Y'-\\                \n");
    printf("\t\t                (__/ \\__)               \n");

}
