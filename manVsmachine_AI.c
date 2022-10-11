#include <stdio.h>
#include <stdlib.h>

int get_score(char board[8][8], char pion)
{
   int score = 0;
   int ligne = 0;
   int colonne = 0;


   /* Vérifiez toutes les cases du grille */
   for(ligne = 0; ligne < 8; ligne++)
     for(colonne = 0; colonne < 8; colonne++)
   {
     if (board[ligne][colonne] == pion){  /* Incrémentation du score   */
         score += 1 ;
         continue;
    }
   }
   return score;
}


int delta_score(char board[8][8], char pion_joueur)
{/*cette fonction calcule la différence entre le score du joueur et celui de son adversaire.*/
char pion_adversaire = 'W';
if ( pion_joueur == 'W')
    pion_adversaire= 'B';
int  Myscore = get_score(board, pion_joueur);
int adverScore = get_score(board, pion_adversaire);
return (Myscore - adverScore);
}


void copyBoard(char board[8][8], char copy_board[8][8])
{/*faire une copie du tableau*/
memcpy(copy_board, board , 8 * 8 * sizeof(char));
}



////////////////////////////////minimax /////////////////////////////////////

int minimaxValue(char board[8][8], char originalTurn, char currentTurn, int joueur)
{
/*cette fonction renvoie la valeur calculée par la fonction delta_score()*/
int moveX[60], moveY[60];
int currentTurn_int;
int numMoves = 0;

for (int x = 0; x < 8; x++){
for (int y = 0; y < 8; y++)
{
if (coup_valide1(board, x, y, joueur))
{
moveX[numMoves] = x;
moveY[numMoves] = y ;
numMoves++;    /*créer deux listes des coups valides et calculer leur nombre */
}}
}
if ((joueur == 5) || game_over(board))
{/*la pronfondeur maximale de recherche est d'ordre 5 */
return delta_score(board, originalTurn);
}

char opponent = 'W';
if (currentTurn == 'W')   //identifier le pion de l'adversaire
opponent = 'B';
if (numMoves == 0) /* si aucun mouvement, passer au tour du joueur suivant*/
{
return minimaxValue(board, originalTurn, opponent, joueur + 1);
}
else
{
// Remember the best move
int bestMoveVal = -99999; // pour trouver le max
if (originalTurn != currentTurn)
bestMoveVal = 99999; // pour trouver le min
// essayer pour chaque coup
for (int i = 0; i < numMoves; i++){
// Appliquer le coup dans une copie de la grille
char tempBoard[8][8];
copyBoard(board, tempBoard);
if (currentTurn=='B'){currentTurn_int=1;}
else {currentTurn_int=2;}
Play(tempBoard, moveX[i], moveY[i], currentTurn_int);
// Appel récursif
int val = minimaxValue(tempBoard, originalTurn, opponent,joueur + 1);
/* le principe de cette partie est d'affecter la valeur maximale de delta_score() s'il s'agit
   du tour de la machine et la valeur minimale pour l'adversaire */

if (originalTurn == currentTurn)
{
if (val > bestMoveVal)
bestMoveVal = val;
}
else
{
if (val < bestMoveVal)
bestMoveVal = val;
}
}
return bestMoveVal;
}
return -1;
}

///////////////////////////////////////////minimax decision function /////////////////////////////
void minimaxDecision(char board[8][8],int *lig, int *col,int joueur)
{
int moveX[60], moveY[60];
int numMoves,whoseTurn_int;
for (int x = 0; x < 8; x++){
for (int y = 0; y < 8; y++)
{
if (coup_valide1(board, x, y, joueur)) //deux tableaux représentant les coordonnées des coups valides
{
moveX[numMoves] = x;
moveY[numMoves] = y;
numMoves++; // Incrementer le nombre des coups valides
}
}}
char opponent = 'B';
char whoseTurn='W';
if (numMoves == 0) //  renvoie -1 si aucun coup n'est valide
{
*lig = -1;
*col = -1;
}
else
{

int bestMoveVal = -99999;
int bestX = moveX[0], bestY = moveY[0];

for (int i = 0; i < numMoves; i++)
{
// Créer une copie du tableau et lui appliquer les coups valides
char tempBoard[8][8];
copyBoard(board, tempBoard);
if (whoseTurn=='B'){whoseTurn_int=1;}
else {whoseTurn_int=2;}
Play(tempBoard, moveX[i], moveY[i], whoseTurn_int);
// appel récurssif
int val = minimaxValue(tempBoard, whoseTurn, opponent, 1);

if (val > bestMoveVal)
{
bestMoveVal = val; //retenir le meilleur coup
bestX = moveX[i];
bestY = moveY[i];
}
}

*lig = bestX;     //retenir le meilleur coup
*col = bestY;

}
}

void manVsMachine_AI(char board[8][8])
 {//cette fonction s'exécute si le joueur choisit de jouer avec aide
            int lig, col, joueur = 1;
            printf("\n\n\t\t                                      YOU will start\n\n");
            grille (board);
            while (!game_over (board)) {
                 if(joueur==1){
                 quoif(board,joueur);
                 remove_pt(board);
                 choice (board, &lig, &col,joueur);
                 Play (board, lig, col, joueur);//jouer le coup
                 Display(board);}
                 else if(joueur==2){
                  minimaxDecision(board, &lig, &col,joueur);//donner le meilleur coup pour la machine
                  Play (board, lig, col, joueur);}
                 if (can_play(board, next_player(joueur))) joueur = next_player (joueur);//passer au tour suivant
                 else printf ("\nPlayer %d skips his turn\n", next_player(joueur));}
                 }

void manVsMachine_AI_1(char board[8][8])
 {
//cette fonction s'exécute si le joueur choisit de jouer sans aide
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
            Display(board);   //afficher la grille
            while (!game_over (board)) {
                 if(joueur==x){
                 choice (board, &lig, &col,joueur);
                 Play (board, lig, col, joueur); //jouer le coup
                 }
                 else if(joueur==y){
                  minimaxDecision(board, &lig, &col,joueur); //donner le meilleur coup pour la machine
                  if (!coup_valide1(board, lig, col, joueur)){minimaxDecision(board, &lig, &col,joueur);}
                  Play (board, lig, col, joueur);}
                  Display(board);
                 if (can_play(board, next_player(joueur)))
                    {joueur = next_player (joueur);} //passer au tour suivant
                 else printf ("\nPlayer %d skips his turn\n", next_player(joueur));}
                 }
