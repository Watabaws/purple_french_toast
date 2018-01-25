
#include "player_connection.c"

int main(){
  int to_client;
  int from_client;
  int from_cli, to_cli;
  char p2name[100];

  while(1){
    int p2_comm = conn_p2();

/*    printf(" 0  1  2  3 \n");
    char tic_tac_toe[3][3] = {0};
    tic_tac_toe[0][0] = 'X';
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        if (j ==0){
          printf(" %d ", i+1);
        }
        if (tic_tac_toe[i][j] == 0){
          printf(" _ ");
        }
        else{
          printf(" %c ",tic_tac_toe[i][j]);
        }
      }
      printf("\n");
    }

    char move[4];
    printf("Player1 enter your move in this format: row col\n");

    fgets(move, 4, stdin);
    *strchr(move, '\n') = 0;

    printf("Here's your move (row col): %s\n", move);

    write(to_cli, move, sizeof(char*)); */

  }
}
