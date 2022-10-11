#ifndef MANVSMACHINE_AI_H_INCLUDED
#define MANVSMACHINE_AI_H_INCLUDED
#endif // MANVSMACHINE_AI_H_INCLUDED


int get_score(char board[8][8], char pion);
int delta_score(char board[][8], char pion_joueur);
void copyBoard(char board[8][8], char copy_board[8][8]);
int minimaxValue(char board[8][8], char originalTurn, char currentTurn, int joueur);
void minimaxDecision(char board[8][8],int *lig, int *col,int joueur);
void manVsMachine_AI(char board[8][8]);
void manVsMachine_AI_1(char board[8][8]);
