#include <stdio.h>
#include <stdlib.h>
#define VIDE ' '
int main()
{
    int joueur=1;
    int a;
    int b;
    char board[8][8];
    int lig, col ;
    printf("\t\t  _____________________________________________________________________________________     \n");
    printf("\t\t                                                                                            \n");
    printf("\t\t      *******   *********  *        *  **********   *           *          *******             \n");
    printf("\t\t     *       *      *      *        *  *            *           *         *       *           \n");
    printf("\t\t     *       *      *      **********  **********   *           *         *       *             \n");
    printf("\t\t     *       *      *      *        *  *            *           *         *       *             \n");
    printf("\t\t      *******       *      *        *  **********   *********   ********   *******                 \n");
    printf("\t\t  _____________________________________________________________________________________     \n");
    printf(" \t\t\t\t\t\t\t          \n");
    printf("\t\t +--+--+--+--+--+--+--+--+--+--+--+--+  MENU   +--+--+--+--+--+--+--+--+--+--+--+--+--+\n");
    printf("\t\t |                                                                                    |\n");
    printf("\t\t +                                                                                    +\n");
    printf("\t\t |                                 ----------------                                   |\n");
    printf("\t\t +                                 1- Play                                            +\n");
    printf("\t\t |                                 ----------------                                   |\n");
    printf("\t\t +                                 2- how to play                                     +\n");
    printf("\t\t |                                 ----------------                                   |\n");
    printf("\t\t +                                 3- Exit                                            +\n");
    printf("\t\t |                                                                                    |\n");
    printf("\t\t +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+---+--+--+--+--+--+--+--+--+--+\n");
    char *Quote[5]={' ',' ',' ',' ',' '};
    for(int i=0;i<5;i++){
        printf("%c\n",Quote[i]);
        Sleep(300);}

    printf("choose 1,2 or 3\n");
    scanf("%d",&a);
    /*for(int i=0;i<5;i++){
        printf("%c\n",Quote[i]);
        Sleep(300);}*/
    if (a==1){     printf("\t\t +--+--+--+--+--+--+--+--+--+--+--+--+ PLAY MODE +--+--+--+--+--+--+---+--+--+--+--+--+\n");
    printf("\t\t |                                                                                    |\n");
    printf("\t\t +                                                                                    +\n");
    printf("\t\t |                                 -------------------                                |\n");
    printf("\t\t +                                 1- man vs man                                      +\n");
    printf("\t\t |                                 -------------------                                |\n");
    printf("\t\t +                                 2- man vs machine 1                                +\n");
    printf("\t\t |                                 -------------------                                |\n");
    printf("\t\t +                                 3- man vs machine 2                                +\n");
    printf("\t\t |                                                                                    |\n");
    printf("\t\t +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+---+--+--+--+--+--+--+--+--+--+\n");
        /*for(int i=0;i<5;i++){
        printf("%c\n",Quote[i]);
        Sleep(300);}*/
        printf("choose your mode:");
        scanf("%d",&b);
        if (b==1){
        grille(board);
        while (!(game_over(board))) {
                ccc(board,joueur);
                ccc1(board);

                choice(board, &lig, &col, joueur);
                Play(board, lig, col, joueur);

                if (can_play(board, next_player(joueur)))
                    joueur = next_player (joueur);
                else printf ("\nLe joueur %d passe son tour\n", next_player(joueur));
                }
        }
        else if (b==2){manVsMachine(board);
        }
        else printf("ERROR");
    }
    else if (a==2) printf("\t\t\t\t\t\t        good bye") ;
    else printf("error");


    return 0;
}
