#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct Joueur
{
    int actif ;
    char pion ;
} Joueur;

////////////verifier si on est encore dans la table///////////////
int case_existe (int ligne,int colonne)
{

    if ( ligne < 0 || ligne >= 8 || colonne < 0 || colonne >= 8 ) return  FALSE ;
    return TRUE ;
}

//////////////////////verifier le coup entree//////////////////////////////

int coup_valide(char board[8][8],int ligne ,int colonne ,Joueur joueur)

{
    int i, j, ok;
    char pion_joueur = joueur.pion , pion_adversaire ;

    pion_adversaire = ( pion_joueur == 'B')? 'W': 'B' ;

    if (!case_existe(ligne, colonne) || board[ligne][colonne] != ' ') return FALSE ;

    /* Vertical vers le haut */
    i = ligne - 1;
    ok = 0 ;
    while (case_existe(i, colonne) && board[i][colonne] == pion_adversaire)
    {
        i--;
        ok = 1 ;
    }
    if (case_existe(i, colonne) && board[i][colonne] == pion_joueur && ok == 1) return TRUE ;

    /* Vertical vers le bas */
    i = ligne + 1;
    ok = 0;
    while (case_existe(i, colonne) && board[i][colonne] == pion_adversaire)
    {
        i++;
        ok = 1;
    }
    if (case_existe(i, colonne) && board[i][colonne] == pion_joueur && ok == 1) return TRUE;

    /* Horizontal vers la gauche */
    j = colonne - 1;
    ok = 0 ;
    while (case_existe(ligne, j) && board[ligne][j] == pion_adversaire) {
        j--;
        ok = 1  ;
    }
    if (case_existe(ligne, j) && board[ligne][j] == pion_joueur && ok == 1) return TRUE ;

    /* Horizontal vers la droite */
    j = colonne + 1;
    ok = 0;
    while (case_existe(ligne, j) && board[ligne][j] == pion_adversaire) {
        j++;
        ok = 1;
    }
    if (case_existe(ligne, j) && board[ligne][j] == pion_joueur && ok == 1) return TRUE ;

    /* Diagonal \ vers le haut */
    i = ligne - 1;
    j = colonne - 1;
    ok = 0;
    while (case_existe(i, j) && board[i][j] == pion_adversaire) {
        i--;
        j--;
        ok = 1;
    }
    if (case_existe(i, j) && board[i][j] == pion_joueur && ok == 1) return 1;

    /* Diagonal \ vers le bas */
    i = ligne + 1;
    j = colonne + 1;
    ok = 0;
    while (case_existe(i, j) && board[i][j] == pion_adversaire) {
        i++;
        j++;
        ok = 1;
    }
    if (case_existe(i, j) && board[i][j] == pion_adversaire && ok == 1) return TRUE;

    /* Diagonal / vers le haut */
    i = ligne - 1;
    j = colonne + 1;
    ok = 0;
    while (case_existe(i, j) && board[i][j] == pion_adversaire) {
        i--;
        j++;
        ok = 1;
    }
    if (case_existe(i, j) && board[i][j] == pion_joueur && ok == 1) return TRUE;

    /* Diagonal / vers le bas */
    i = ligne + 1;
    j = colonne - 1;
    ok = 0;
    while (case_existe(i, j) && board[i][j] == pion_adversaire) {
        i++;
        j--;
        ok = 1;
    }
    if (case_existe(i, j) && board[i][j] == pion_joueur && ok == 1) return TRUE;

    return 0;
}
