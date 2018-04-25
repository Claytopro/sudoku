/*
By: Clayton provan  
date: 4/24/2018
*/
#include <sudoku.h>

int main(){
    int board[9][9];
    createBoard(board);
    printBoard(board);
    fillBoard(board);
    printBoard(board);
   
    return 0;
}

void createBoard(int board[][9]){
    int i,j;
    /*initlize board to be filled with -1*/
    for(i=0; i<9;i++){
        for(j=0; j<9;j++){
            board[i][j] = 0;
        }
    } 
}

int checkSpot(int board[][9],int col,int row, int value){
    int i;

    if(board == NULL){
        return 0;
    }
/*checks rows if it is possible to place value*/
    for(i=0; i<9;i++){
        if(board[col][i] == value){
            return 0;
        }
    }
/*checks collunms if value has appeared before*/
    for(i=0; i<9;i++){
        if(board[i][row] == value){
            return 0;
        }
    }
/*check sector for matching number*/
        col = (col/3) * 3;
        row = (row/3) *3;
        /*check horizontal, verticle, and diagonal in sector*/
        for(i=0; i<3;i++){
            if(board[col+i][row]==value){
                return 0;
            }
            if(board[col][row+i] == value){
                return 0;
            }
  
        }
        


    return 1;
}
/*solves board*/
void fillBoard(int board[][9]){
        int i,j,k;
        /*int r = (srand()%10) +1; */

        for(i=0; i<9; i++){
            for(j=0; j<9; j++){
               for(k=1;k<10;k++){
                  if(checkSpot(board,i,j,k)){
                    board[i][j] = k;
                    }
               }
            }
        }
        


}

/*assume has dimensions 9x9*/
void printBoard(int board[][9]){
    int i,j;
    for(i=0; i<9;i++){
        for(j=0; j<9;j++){
            printf("%d ",board[i][j]);
            if( (j+1) % 3 ==0 && j!=8){
                printf("| ");
            }
        }
        printf("\n");
          if( (i+1) % 3 ==0 && i!=8){
                printf("------+-------+-------\n");
            }
    }
    printf("\n");
}

