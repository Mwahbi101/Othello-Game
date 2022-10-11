#include <stdio.h>
#include <stdlib.h>

void ccc(char board[8][8],int joueur){
for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (coup_valide1 (board,i, j, joueur)){
                     board[i][j]= '.';}


    }}Display(board);}
void ccc1(char board[8][8]){
for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (board[i][j]=='.'){
                     board[i][j]= ' ';}
            }

        }}
