#include <stdio.h>

int addToBoard(char board[3][3], int x, int y, char charAdded){
  //if x n y between 1 and 3 + nothing there
  if (x >= 4 || x <= 0 || y >= 4 || y <= 0){
    printf("invalid coordinates\n");
    return -1; //invalid coordinates
  }
  else if (board[x-1][y-1] != 0){
    printf("piece exists there\n");
    return -2; //piece already there
  }
  board[x-1][y-1] = charAdded;
  printf("success\n");
  return 0;
}
int CheckTicTacToe(char board[3][3]){
  int i;
  for (i = 0; i < 3; i++){
    if ( (board[i][0] != '0') && (board[i][0] == board[i][1]) && (board[i][0] == board[i][2]) ){
      return(board[i][0] == 'O' ? -1 : 1);
    }
    else if ( (board[0][i] != '0') && (board[0][i] == board[1][i]) && (board[0][i] == board[2][i]) ){
      return(board[0][i] == 'O' ? -1 : 1);
    }
  }
  if ( (board[0][0] != '0') && (board[0][0] == board[1][1]) && (board[0][0] == board[2][2])){
    return(board[0][0] == 'O' ? -1 : 1);
  }
  if ( (board[2][0] != '0') && (board[2][0] == board[1][1]) && (board[0][0] == board[0][2])){
    return(board[1][1] == 'O' ? -1 : 1);
  }
  return 0;
  //0 = no win; -1 = O won; 1 = X won
}

void printBoard(char board[3][3]){
  printf("   ");
  for(int i = 0; i < 3; i++){
    printf(" %d ", i+1);
  }
  printf("\n");
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
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
  char tic_tac_toe[3][3] = {0};
  printBoard(tic_tac_toe);
  addToBoard(tic_tac_toe,1,1,'X');
  addToBoard(tic_tac_toe,2,2,'X');
  addToBoard(tic_tac_toe,3,3,'X');
  printBoard(tic_tac_toe);
  printf("%d\n", CheckTicTacToe(tic_tac_toe));
}
