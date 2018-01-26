#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

void print_board(char ttt[3][3]){
  printf(" 0  1  2  \n");
  for(int i = 0; i < 3; i++){
    printf("%d ", i);
    for(int j = 0; j < 3; j++){
      printf("[%c] ", ttt[i][j]);
    }
    printf("\n");
  }
}

int check_left_diagonal(int move[2], char ttt[3][3]){
  char piece = ttt[move[0]][move[1]];

  move[0] = (move[0] + 1) % 3;
  move[1] = (move[0] - 1) % 3;
  if(ttt[move[0]][move[1]] != piece){
    return 1;
  }

  move[0] = (move[0] + 1) % 3;
  move[1] = (move[0] - 1) % 3;
  if(ttt[move[0]][move[1]] != piece){
    return 1;
  }

  return 0;
}

int check_right_diagonal(int move[2], char ttt[3][3]){
  char piece = ttt[move[0]][move[1]];

  move[0] = (move[0] + 1) % 3;
  move[1] = (move[1] + 1) % 3;
  if(ttt[move[0]][move[1]] != piece){
    return 1;
  }

  move[0] = (move[0] + 1) % 3;
  move[1] = (move[1] + 1) % 3;
  if(ttt[move[0]][move[1]] != piece){
    return 1;
  }

  return 0;
}

int check_vertical(int move[2], char ttt[3][3]){
  char piece = ttt[move[0]][move[1]];

  move[0] = (move[0] + 1) % 3;
  if(ttt[move[0]][move[1]] != piece){
    return 1;
  }

  move[0] = (move[0] + 1) % 3;
  if(ttt[move[0]][move[1]] != piece){
    return 1;
  }

  return 0;
}

int check_horizontal(int move[2], char ttt[3][3]){
  char piece = ttt[move[0]][move[1]];

  move[1] = (move[1] + 1) % 3;
  if(ttt[move[0]][move[1]] != piece){
    return 1;
  }

  move[1] = (move[1] + 1) % 3;
  if(ttt[move[0]][move[1]] != piece){
    return 1;
  }

  return 0;
}

int * get_move(){
  char * response = (char *) malloc(5);
  int rmove = 4, cmove = 4;
  while(rmove >= 3){
    printf("What row would you like to place your piece on?\n");
    fgets(response, 5, stdin);
    //printf("This is your row: %s", response);   
    *strchr(response, '\n') = 0;
    rmove = atoi(response); //Test out what happens if I give this like a letter or smth
    if(rmove >= 3){
      printf("Not a valid row.\n");
    }
  }

  while(cmove >= 3){
    printf("What column would you like to place your piece on?\n");
    fgets(response, 5, stdin);
    *strchr(response, '\n') = 0;
    cmove = atoi(response); //Test out what happens if I give this like a letter or smth
    if(cmove >= 3){
      printf("Not a valid column.\n");
    }
  }

  int * to_ret = (int *) malloc(2 * sizeof(char));
  to_ret[0] = rmove;
  to_ret[1] =  cmove;
  return to_ret;
}

int check_win(int shmove[2], char ttt[3][3]){
  int move[2];
  move[0] = shmove[0];
  move[1] = shmove[1];
  
  char piece = ttt[move[0]][move[1]];
  int won;
  
  won = check_horizontal(move, ttt);
  won += check_vertical(move, ttt);

  if(move[0] == move[1]){
    won += check_right_diagonal(move, ttt);
  }
  else if(move[0] + move[1] == 2){
    won += check_left_diagonal(move, ttt);
  }

  return won;
}

int fullBoard(char board[3][3]){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(board[i][j] == '-'){
                return 0;
            }
        }
    }
    return 1000;
}

int CheckTicTacToe(char board[3][3]){
  int i;
  for (i = 0; i < 3; i++){
    if ( (board[i][0] != '-') && (board[i][0] == board[i][1]) && (board[i][0] == board[i][2]) ){
        //printf("I'M RETURNING0\n");
      return(board[i][0] == 'O' ? -1 : 1);
    }
    else if ( (board[0][i] != '-') && (board[0][i] == board[1][i]) && (board[0][i] == board[2][i]) ){
        //printf("I'M RETURNING1\n");
      return(board[0][i] == 'O' ? -1 : 1);
    }
  }
  if ( (board[0][0] != '-') && (board[0][0] == board[1][1]) && (board[0][0] == board[2][2])){
      //printf("I'M RETURNING2\n");
    return(board[0][0] == 'O' ? -1 : 1);
  }
  if ( (board[2][0] != '-') && (board[2][0] == board[1][1]) && (board[0][0] == board[0][2])){
      //printf("I'M RETURNING3\n");
    return(board[1][1] == 'O' ? -1 : 1);
  }
  return fullBoard(board);
  //0 = no win; -1 = O won; 1 = X won
}


void declare_winner(int playr){
    if(playr == 1){
        printf("Player 1 has won!!\n");
    }
    else if (playr == -1){
        printf("Player 2 has won!!\n");
    }
    else{
        printf("Stalemate.\n");
    }
}
