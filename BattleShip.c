#include <stdio.h>

int placeShip(char board[10][10], int shipType, int x, int y, char direction){
  //user: I want a ship on (x,y) to the R direction
  //carrier = 5; battleship = 4; cruiser = 3; submarine = 3; destroyer = 2
  if (direction == 'R'){
    for (int i =0; i <shipType; i++){
      if ((x) >= 11 || (x) <= 0 || (y+i) >= 11 || (y+i) <= 0){
        printf("invalid coordinates\n");
        return -1;
      }
    }
    for (int i =0; i <shipType; i++){
      board[x-1][y-1+i] = '#';
    }
  }
  if (direction == 'L'){
    for (int i =0; i <shipType; i++){
      if ((x) >= 11 || (x) <= 0 || (y-i) >= 11 || (y-i) <= 0){
        printf("invalid coordinates\n");
        return -1;
      }
    }
    for (int i =0; i <shipType; i++){
      board[x-1][y-1-i] = '#';
    }
  }
  if (direction == 'U'){
    for (int i =0; i <shipType; i++){
      if ((x-i) >= 11 || (x-i) <= 0 || (y) >= 11 || (y) <= 0){
        printf("invalid coordinates\n");
        return -1;
      }
    }
    for (int i =0; i <shipType; i++){
      board[x-1-i][y-1] = '#';
    }
  }
  if (direction == 'D'){
    for (int i =0; i <shipType; i++){
      if ((x+i) >= 11 || (x+i) <= 0 || (y) >= 11 || (y) <= 0){
        printf("invalid coordinates\n");
        return -1;
      }
    }
    for (int i =0; i <shipType; i++){
      board[x-1+i][y-1] = '#';
    }
  }
    return 0;
  }

void attackBoard(char board[10][10], int x, int y){
  if (board[x-1][y-1] == '#'){
    board[x-1][y-1] = 'X';
    //increase by one point
    printf("You destroyed an opponent's ship!\n");
  }
  if (board[x-1][y-1] == 0){
    board[x-1][y-1] = 'O';
    printf("You missed!\n");
  }
}



void printBoard(char board[10][10]){
  printf("   ");
  for(int i = 0; i < 10; i++){
    printf(" %d ", i+1);
  }
  printf("\n");
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if (j ==0 && i == 9){
        printf("%d ", i+1);
      }
      else if (j ==0){
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
  char battleshipBoard[10][10] = {0};
  printBoard(battleshipBoard);
  placeShip(battleshipBoard, 2, 5, 5, 'U');
  placeShip(battleshipBoard, 2, 5, 5, 'D');
  attackBoard(battleshipBoard, 5,5);
  printBoard(battleshipBoard);
  attackBoard(battleshipBoard, 1,1);
  printBoard(battleshipBoard);
}
