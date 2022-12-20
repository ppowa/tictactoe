#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

void resetBoard();
void printBoard();
int checkLegalSpace();
void playerMove();
void cpuMove();
char checkWinner();
void declareWinner(char);

char board[3][3];
const char PLAYER = 'X';
const char CPU = 'O';

int main(){

    char winner = ' ';
    resetBoard();
    while(winner == ' ' && checkLegalSpace() != 0){

        printBoard();

        playerMove();
        winner = checkWinner();
        if(winner != ' ' || checkLegalSpace() == 0){
            break;
        }

        cpuMove();
        winner = checkWinner();
        if(winner != ' ' || checkLegalSpace() == 0){
            break;
        }
    }
    printBoard();
    declareWinner(winner);

    return 0;

}

void resetBoard(){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j]=' ';
        }
    }

}

void printBoard(){
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int checkLegalSpace(){

    int legalSpaces = 9;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != ' ')
            legalSpaces--;
        }
    }
    return legalSpaces;

}

void playerMove(){

    int x,y;
    
    do {
        printf("Enter Row #(1-3): ");
        scanf("%d", &x);
        x--;
        
        printf("Enter Column #(1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' '){
            printf("INVALID MOVE!\n");
        }

        else{
            board[x][y] = PLAYER;
            break;
        }

    } while(board[x][y] != ' ');

}

void cpuMove(){

    srand(time(0));
    int x, y;

    if(checkLegalSpace > 0){
        do { 
            x = rand() % 3;
            y = rand() % 3;
        } while(board[x][y] != ' ');

        board[x][y] = CPU;
    }
    else{
        declareWinner(' ');
    }

}

char checkWinner(){

    for(int i = 0; i < 3; i++){
        if(board[i][0] == board [i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
    }

    for(int i = 0; i < 3; i++){
        if(board[0][i] == board [1][i] && board[0][i] == board[2][i]){
            return board[0][i];
        }
    }

    if(board[0][0] == board [1][1] && board[0][0] == board[2][2]){
        return board[0][0];
    }
    if(board[0][2] == board [1][1] && board[0][2] == board[2][0]){
        return board[0][2];
    }

    return ' ';

}

void declareWinner(char winner){

    if(winner == PLAYER){
    printf("YOU WIN!");
    }

    else if(winner == CPU){
    printf("YOU LOSE!");
    }

    else{
    printf("IT'S A DRAW!");
    }
}