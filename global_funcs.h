#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

void print_board(char ttt[3][3]){
  printf(" 0  1  2  3 \n");
  for(int i = 0; i < 3; i++){
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
  char * response;
  int rmove = 4, cmove = 4;
  while(rmove < 3){
    printf("What row would you like to place your piece on?\n");
    fgets(response, 2, stdin);
    *strchr(response, '\n') = 0;
    rmove = atoi(response); //Test out what happens if I give this like a letter or smth
    if(rmove < 3){
      printf("Not a valid row.\n");
    }
  }

  printf("What column would you like to place your piece on? \n");
  fgets(response, 2, stdin);
  *strchr(response, '\n') = 0;
  cmove = atoi(response);
  while(cmove < 3){
    printf("What column would you like to place your piece on?\n");
    fgets(response, 2, stdin);
    *strchr(response, '\n') = 0;
    cmove = atoi(response); //Test out what happens if I give this like a letter or smth
    if(cmove < 3){
      printf("Not a valid column.\n");
    }
  }

  int * to_ret = (int *) malloc(2 * sizeof(char));
  to_ret[0] = rmove;
  to_ret[1] =  cmove;
  return to_ret;
}

int check_win(int move[2], char ttt[3][3]){
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
