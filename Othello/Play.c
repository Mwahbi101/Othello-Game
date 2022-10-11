void Play(char board[8][8], int lig, int col, int joueur) {
    int i, j;
    char cj, ca;

    if (joueur == 1) {
        cj = 'B';
        ca = 'W';
    } else {
        cj = 'W';
        ca = 'B';
    }
    board[lig][col] = cj;

    /* Vertical vers le haut */
    i = lig - 1;
    while (case_existe(i, col) && board[i][col] == ca) i--;
    if (case_existe(i, col) && board[i][col] == cj) {
        i = lig - 1;
        while (board[i][col] == ca) {
            board[i][col] = cj;
            i--;
        }
    }

    /* Vertical vers le bas */
    i = lig + 1;
    while (case_existe(i, col) && board[i][col] == ca) i++;
    if (case_existe(i, col) && board[i][col] == cj) {
        i = lig + 1;
        while (board[i][col] == ca) {
            board[i][col] = cj;
            i++;
        }
    }

    /* Horizontal vers la gauche */
    j = col - 1;
    while (case_existe(lig, j) && board[lig][j] == ca) j--;
    if (case_existe(lig, j) && board[lig][j] == cj) {
        j = col - 1;
        while (board[lig][j] == ca) {
            board[lig][j] = cj;
            j--;
        }
    }

    /* Horizontal vers la droite */
    j = col + 1;
    while (case_existe(lig, j) && board[lig][j] == ca) j++;
    if (case_existe(lig, j) && board[lig][j] == cj) {
        j = col + 1;
        while (board[lig][j] == ca) {
            board[lig][j] = cj;
            j++;
        }
    }

    /* Diagonal \ vers le haut */
    i = lig - 1;
    j = col - 1;
    while (case_existe(i, j) && board[i][j] == ca) {
        i--;
        j--;
    }
    if (case_existe(i, j) && board[i][j] == cj) {
        i = lig - 1;
        j = col - 1;
        while (board[i][j] == ca) {
            board[i][j] = cj;
            i--;
            j--;
        }
    }

    /* Diagonal \ vers le bas */
    i = lig + 1;
    j = col + 1;
    while (case_existe(i, j) && board[i][j] == ca) {
        i++;
        j++;
    }
    if (case_existe(i, j) && board[i][j] == cj) {
        i = lig + 1;
        j = col + 1;
        while (board[i][j] == ca) {
            board[i][j] = cj;
            i++;
            j++;
        }
    }

    /* Diagonal / vers le haut */
    i = lig - 1;
    j = col + 1;
    while (case_existe(i, j) && board[i][j] == ca) {
        i--;
        j++;
    }
    if (case_existe(i, j) && board[i][j] == cj) {
        i = lig - 1;
        j = col + 1;
        while (board[i][j] == ca) {
            board[i][j] = cj;
            i--;
            j++;
        }
    }

    /* Diagonal \ vers le bas */
    i = lig + 1;
    j = col - 1;
    while (case_existe(i, j) && board[i][j] == ca) {
        i++;
        j--;
    }
    if (case_existe(i, j) && board[i][j] == cj) {
        i = lig + 1;
        j = col - 1;
        while (board[i][j] == ca) {
            board[i][j] = cj;
            i++;
            j--;
        }
    }
}
