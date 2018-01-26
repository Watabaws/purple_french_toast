#include "player2_connection.c"

/*void test_conn(){
  char test_mess[50];

  read(from_p1, test_mess, sizeof(test_mess));
  //sprintf(test_mess, "P1 said %s\n", test_mess);
  printf("%s", test_mess);

  write(to_p1, test_mess, sizeof(test_mess));
}*/

int main() {
  int from_p1;
  int to_p1 = conn_p1(&from_p1);

  printf("Time to play Tic-Tac-Toe!\n");
  char tic_tac_toe[3][3] = {0};
  int won = 100;
  while(won){
    printf("The current board: \n");
    print_board(tic_tac_toe);

    printf("Waiting on Player 1's Move!!\n");

    int read_row, read_col;
    int * move = (int *) malloc(2);

    read(from_p1, &read_col, sizeof(int) * 2);
    move[0] = read_col;
    
    printf("P1 col: %d\n", move[0]);
    
    read(from_p1, &read_row, sizeof(int) * 2);
    move[1] = read_row;
    
    printf("P1 row: %d\n", move[1]);

    tic_tac_toe[move[0]][move[1]] = 'X';
    won = CheckTicTacToe(tic_tac_toe);

    if(won){
      print_board(tic_tac_toe);

      move = get_move();

      tic_tac_toe[move[0]][move[1]] = 'O';
      
      printf("precheck: %d\n",won);
      won = CheckTicTacToe(tic_tac_toe);
      printf("postcheck: %d\n", won);
      write(to_p1, move, sizeof(int) * 2);
      if(!won){
        printf("You win!\n");
      }
    }
    else{
      printf("Player 1 wins!\n");
    }
  }

}
