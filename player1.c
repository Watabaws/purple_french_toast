
#include "player1_connection.c"

/*void test_conn(){
  char test_mess[50] = "Hi player2!!";

  write(to_p2, test_mess, sizeof(test_mess));

  read(from_p2, test_mess, sizeof(test_mess));

  printf("P2 said: %s\n", test_mess);
}*/

int main(){
  int from_p2;
  int to_p2 = conn_p2(&from_p2);

  printf("Time to play Tic-Tac-Toe. Your move!!\n");

  char tic_tac_toe[3][3] = {0};

  int won = 100;
  while(won){
    printf("The current board: \n");
    print_board(tic_tac_toe);

    printf("Get ready to make your move.\n");

    int * move = get_move();
    tic_tac_toe[move[0]][move[1]] = 'X';
    
    print_board(tic_tac_toe);
      printf("Sending first arg: %d\n", move[0]);
      printf("Sending second arg: %d\n", move[1]);
      printf("precheck: %d\n",won);
      won = CheckTicTacToe(tic_tac_toe);
      printf("postcheck: %d\n", won);

    if(won){
      printf("Sending first arg: %d\n", move[0]);
      printf("Sending second arg: %d\n", move[1]);
      write(to_p2, &move[0], sizeof(int) * 2);
      write(to_p2, &move[1], sizeof(int) * 2);

      printf("Waiting for Player 2's move\n");

      read(from_p2, move, sizeof(int) * 2);
      printf("Move received!\n");
      
      print_board(tic_tac_toe);

      tic_tac_toe[move[0]][move[1]] = 'O';

      printf("precheck: %d\n",won);
      won = CheckTicTacToe(tic_tac_toe);
      printf("postcheck: %d\n", won);
      if(!won){
        printf("Player 2 wins.\n");
      }
    }
    else{
      printf("You won!\n");
    }    
  }

  return 0;
  /*
  char move[4];
  printf("Player1 enter your move in this format: row col\n");

  fgets(move, 4, stdin);
  *strchr(move, '\n') = 0;

  printf("Here's your move (row col): %s\n", move);

  write(to_cli, move, sizeof(char*));
  */
}
