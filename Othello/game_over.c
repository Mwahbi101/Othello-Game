#define VIDE ' '
int game_over (char board[8][8]) {
    int i, j, nb_noir, nb_blanc;
    nb_noir = 0;
    nb_blanc = 0;
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            if (board[i][j] ==' ' && (can_play(board, 1) || can_play(board, 2))) { return 0;}
            else {
                if (board[i][j] == 'B') nb_noir++;
                else if (board[i][j] == 'W') nb_blanc++;
            }
        }
    }
    Display (board);
    if (nb_noir > nb_blanc)
        printf ("\nLe joueur 1 a gagne !!!\n");
    else if (nb_blanc > nb_noir)
        printf ("\nLe joueur 2 a gagne !!!\n");
    else printf ("\nLes deux joueurs sont a egalite\n");
    printf("noir=%d\nblanc=%d",nb_noir,nb_blanc);

    printf ("\n");
    return 1;
}
