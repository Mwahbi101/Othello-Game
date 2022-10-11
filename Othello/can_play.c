
int can_play (char board[8][8], int joueur) {
    int i, j;
    for (i=0; i<8; i++)
        for (j=0; j<8; j++)
            if (coup_valide1(board, i, j, joueur)) return 1; /* Le joueur peut encore jouer */

    /* Le joueur ne peut plus jouer */
    return 0;
}
