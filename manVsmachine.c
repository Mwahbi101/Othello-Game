void choice_machine(char board[8][8],int *lig,int *col,int joueur )
{
    *lig = rand()%8;
    *col = rand()%8;
    while (!coup_valide1 (board,*lig, *col, joueur)) {
        *lig = rand()%8;
        *col = rand()%8;}


}
void manVsMachine(char board[8][8])
 {

            int lig, col, joueur = (rand()%2) + 1,x,y;
            if (joueur==2) {printf("\n\n\t\t                                      machine will start");
            char *Quote[5]={" "," "," "," "," "};
            for(int i=0;i<5;i++){
            printf("%s\n",Quote[i]);
            Sleep(300);}
            x=2;
            y=1;
            joueur=1;}
            else {x=1;y=2;}
            grille (board);
            while (!game_over (board)) {
                 if(joueur==x){
                 quoif(board,joueur);
                 remove_pt(board);
                 choice (board, &lig, &col,joueur);
                 Play (board, lig, col, joueur);
                 Display(board);}
                 else if(joueur==y){
                 choice_machine (board,&lig,&col,joueur);
                 Play (board, lig, col, joueur);
                  }
                 if (can_play(board, next_player(joueur)))
                    joueur = next_player (joueur);
                 else printf ("\nPlayer %d skips his turn\n", next_player(joueur));}
                 }


void manVsMachine_1(char board[8][8])
 {

            int lig, col, joueur = (rand()%2) + 1,x,y;
            if (joueur==2) {printf("\n\n\t\t                                      machine will start");
            char *Quote[5]={" "," "," "," "," "};
            for(int i=0;i<5;i++){
            printf("%s\n",Quote[i]);
            Sleep(300);}
            x=2;
            y=1;
            joueur=1;}
            else {x=1;y=2;}
            grille (board);
            Display(board);

            while (!game_over (board)) {
                 if(joueur==y%2+1){
                 choice (board, &lig, &col,joueur);
                 Play (board, lig, col, joueur);}
                 else if(joueur==x%2+1){
                  choice_machine (board,&lig,&col,joueur);
                  Play (board, lig, col, joueur);}
                  Display(board);
                 if (can_play(board, next_player(joueur)))
                    joueur = next_player (joueur);
                 else printf ("\nPlayer %d skips his turn\n", next_player(joueur));}
                 }
