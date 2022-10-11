#include <stdio.h>
#include <stdlib.h>

/*********************************************************************************/

int case_existe (int lig,int col) {
    return ((col >= 0) && (col < 8) && (lig >= 0) && (lig < 8));

}
int board[8][8];

int coup_valide1 (char board[8][8],int lig,int col,int joueur) {
    int i, j, ok;
    char cj, ca;

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
