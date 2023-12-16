#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int8_t tictactoe_check(int8_t* gameboard, int win_len);
int rowCheck(int* points, int win_len, int amount);
int columnCheck(int8_t* board, int* points, int win_len, int amount);
int diagonalCheck(int8_t *board, int* points, int win_len, int amount);


int8_t tictactoe_check(int8_t * gameboard, int win_len){
    int x[100], o[100], xAmount = 0, oAmount = 0, xWins = 0, oWins = 0;
    for(int i=0; i<100; i++){
        if(gameboard[i] == 1){
            x[xAmount] = i;
            xAmount++;
        }else if(gameboard[i] == 2){
            o[oAmount] = i;
            oAmount++;
        }

    }

    if(win_len > 1){
        if(xAmount >= win_len){
            xWins = rowCheck(x, win_len, xAmount) + columnCheck(gameboard, x, win_len, xAmount) + diagonalCheck(gameboard, x, win_len, xAmount); 
        }
        if(oAmount >= win_len){
            oWins = rowCheck(o, win_len, oAmount) + columnCheck(gameboard, o, win_len, oAmount) + diagonalCheck(gameboard, o, win_len, oAmount); 
        }
    }
    if(xWins || oWins){
        if(xWins && oWins) return 0;
        if(xWins >=1) return 1;
        if(oWins >=1) return 2;
    }
    return 0;


}

int rowCheck(int* points, int win_len, int amount){
    int summa = 1;
    int voitot = 0;
    int longest = 0;
    for(int i=0; i<amount - 1; i++){
        if(points[i] + 1 == points[i + 1]){
            summa++;
            if(longest < summa){
                longest = summa;
                if(summa >= win_len){
                 voitot++;
                }
            }
        }else {
            summa = 1;
        }
    }

    return voitot;
}

int columnCheck(int8_t * board, int* points, int win_len, int amount){
    int summa = 0, voitot = 0, longest = 0;
    for(int i=0; i<amount; i++){
        for(int j=i; j<amount; j++){
            if(points[i] + 10 == points[j]){
                do{
                    summa++;
                }while(board[points[i] + (10 * summa)] == board[points[i]]);

            }
            if(longest < summa){
                longest = summa;
                if(longest >= win_len){
                 voitot++;
                }
            }
            summa = 0;
        }
    }       
    return voitot;
}

int diagonalCheck(int8_t* board, int* points, int win_len, int amount){
    int summa = 0, voitot = 0, longest = 0;
    for(int i=0; i<amount; i++){
        for(int j=i; j<amount; j++){
            if(points[i] + 11 == points[j]){
                summa++;
                do{
                    summa++;
                }while(board[points[i] + 11 * summa] == board[points[i]]);
            }
            else if((points[i] + 9 * summa == points[j]) && points[i] != 0){
                do {
                    summa++;
                }while(board[points[i] + 9 * summa] == board[points[i]]);
            }
            if(longest < summa){
                longest = summa;
                if(longest >= win_len){
                 voitot++;
                }
            }
            summa = 0;
        
        }
        
    }
    return voitot;
}