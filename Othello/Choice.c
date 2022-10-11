int c,x;
void choice(char board[8][8], int *lig, int *col, int joueur) {
    printf ("%d make your move :\n",joueur);
    printf("colonne:");
    scanf ("%d", &c);
    printf("ligne:");
    scanf ("\n%d", &x);
    (*col) = c;
    (*lig)= x;

    while (!coup_valide1 (board,*lig, *col, joueur)) {
        printf ("Ce coup n'est pas valide  make your move :%d\n",joueur);
        printf ("%d make your move :\n",joueur);
        printf("colonne:");
        scanf ("%d", &c);
        printf("ligne:");
        scanf ("\n%d", &x);
        (*col) = c;
        (*lig)=x;
}
}
