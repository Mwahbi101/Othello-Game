#include<stdio.h>
#include<stdlib.h>

void choisir_coupMachine (char board[8][8],int *lig,int *col,int joueur,char nomF) {
    *lig=rand() % (7 + 1 - 0) + 0; //rand() % (max_number + 1 - minimum_number) + minimum_number
    *col=rand() % (7 + 1 - 0) + 0;
    /* On redemande de choisir tant que le coup n'est pas accepte */
    while (!coup_valide (board, *lig, *col, joueur)) {
       *lig=rand()%8;
       *col=rand()%8;
   }

FILE *fichier;
      char *chemin=(char*)malloc(sizeof(char)*200);
      strcpy(chemin,"sauvgardeMouvement");
      strcat(chemin,nomF);
      strcat(chemin,".txt");
      fichier = fopen(chemin,"a");
           if (fichier == NULL)
            {
               exit(EXIT_FAILURE);
            }
            fprintf(fichier,"%d %d\n",*col,*lig);
     fclose(fichier);

}

/*pour jouer contre la machine*/
void hhhh(char board[8][8])
 {
 /* Initialisation du jeu */
            ;
            char nnnn;
            int lig, col, joueur = 1;
            grille (board);
            Display (board);
            /* Deroulement d'une partie */
            while (!game_over(board)) {
                 if(joueur==1)
                 choice (board, &lig, &col,joueur);
                 else if(joueur==2)
                 choisir_coupMachine (board,&lig,&col,joueur,nnnn);
                 Play (board, lig, col, joueur);
                 Display (board);
                 if (can_play(board, next_player(joueur)))
                    joueur = next_player (joueur);
                 else printf ("\nLe joueur %d passe son tour\n", next_player(joueur));}

}


