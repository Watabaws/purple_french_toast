#include <stdio.h>

void initializeBoard(char board[20][20]){
  srand(time(NULL));
  int randnum, rando;
  for (int i = 0; i <50; i++){
    randnum = rand()%((20-0)+0);
    rando = rand()%((20-0)+0);
    board[randnum][rando] = 'B';
  }
}

int minesSurrounding(char board[20][20], int x, int y){
  if (x >= 21 || x <= 0 || y >= 21 || y <= 0){
    printf("invalid coordinates\n");
    return -1; //invalid coordinates
  }
  if (y=0){
    
  }
}

int firstMove(char board[20][20], int x, int y){

}

void printBoard(char board[20][20]){
  printf("   ");
  for(int i = 0; i < 20; i++){
    if (i > 9){
      printf(" %d ", i+1);
    }
    else{
    printf("  %d ", i+1);
  }
  }
  printf("\n");
  for(int i = 0; i < 20; i++){
    for(int j = 0; j < 20; j++){
      if (j ==0 && i >= 9){
        printf("%d ", i+1);
      }
      else if (j ==0){
        printf(" %d ", i+1);

      }
      if (board[i][j] == 0){
        printf("  _ ");
      }
      else{
        printf("  %c ",board[i][j]);
      }
    }
    printf("\n");
  }
  printf("\n");

}

int main(){
  char mineBoard[20][20] = {0};
  printBoard(mineBoard);
  initializeBoard(mineBoard);
  printBoard(mineBoard);
}
