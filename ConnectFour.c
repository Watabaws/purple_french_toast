#include <stdio.h>

int addToBoard(char board[6][7], int col, char charAdded){
  for (int i = 0; i < 6; i++){
    if (board[5-i][col-1] == 0){
      board[5-i][col-1] = charAdded;
      printf("success\n");
      return 0;
    }
  }
  printf("invalid move\n");
  return -1;
}

int CheckConnectFour(char board[6][7]){

}

void printBoard(char board[6][7]){
  printf("   ");
  for(int i = 0; i < 7; i++){
    printf(" %d ", i+1);
  }
  printf("\n");
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 7; j++){
      if (j ==0){
        printf(" %d ", i+1);
      }
      if (board[i][j] == 0){
        printf(" _ ");
      }
      else{
        printf(" %c ",board[i][j]);
      }
    }
    printf("\n");
  }
}

int main(){
  char connect_four[6][7] = {0};
  printBoard(connect_four);
  addToBoard(connect_four, 4, 'R');
  addToBoard(connect_four, 7, 'B');
  addToBoard(connect_four, 4, 'B');
  addToBoard(connect_four, 4, 'B');
  addToBoard(connect_four, 4, 'B');
  addToBoard(connect_four, 4, 'B');
  addToBoard(connect_four, 4, 'B');
  printBoard(connect_four);
}
