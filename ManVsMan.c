void manvsman(char board[8][8]){
    char name1[20],name2[20];
    printf("Enter players names:\n");
    scanf("%s", name1);
    scanf("%s", name2);
    Sleep(300);
    int c =(rand()%2) + 1;
    printf("\n\n\t\t                        THE FIRST PLAYER WILL BE CHOOSEN RANDOMLY\n");
    Sleep(300);
    if (c==1) {printf("\n\n\t\t                                      %s will start\n",name1);
    Sleep(200);
    printf("\n\t\t                                      %s is the black\n",name1);
    Sleep(300);
    printf("\n\t\t                                      %s is the white\n\n",name2);}
    else {printf("\n\n\t\t                                      %s will start\n",name2);
    Sleep(300);
    printf("\n\t\t                                      %s is the black\n",name2);
    Sleep(300);
    printf("\n\t\t                                      %s is the white\n\n",name1);}
        int lig, col, joueur = 1;
        grille(board);
        while (!(game_over(board))) {
                quoif(board,joueur);
                remove_pt(board);
                choice(board, &lig, &col, joueur);
                Play(board, lig, col, joueur);
                if (can_play(board, next_player(joueur)))
                    joueur = next_player (joueur);
                else printf ("\nPlayer %d skips his turn\n", next_player(joueur));
                }}

void manvsman_1(char board[8][8]){
    char name1[20],name2[20];
    printf("Enter players names:\n");
    scanf("%s", name1);
    scanf("%s", name2);
    Sleep(300);
    int c = (rand()%2) + 1;
    printf("\n\n\t\t                        THE FIRST PLAYER WILL BE CHOOSEN RANDOMLY\n");
    Sleep(300);
    if (c==1) {printf("\n\n\t\t                                      %s will start\n",name1);
    Sleep(300);
    printf("\n\t\t                                      %s is the black\n",name1);
    Sleep(300);
    printf("\n\t\t                                      %s is the white\n\n",name2);}
    else {printf("\n\n\t\t                                      %s will start\n",name2);
    Sleep(300);
    printf("\n\t\t                                      %s is the black\n",name2);
    Sleep(300);
    printf("\n\t\t                                      %s is the white\n\n",name1);}
        int lig, col, joueur = 1;
        grille(board);
        Display(board);
        while (!(game_over(board))) {
                choice(board, &lig, &col, joueur);
                Play(board, lig, col, joueur);
                Display(board);
                if (can_play(board, next_player(joueur)))
                    joueur = next_player (joueur);
                else printf ("\nPlayer %d skips his turn\n", next_player(joueur));
                }}
