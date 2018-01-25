
#include "player1_connection.c"

void test_conn(){
  char test_mess[50] = "Hi player2!!";

  write(to_p2, test_mess, sizeof(test_mess));

  read(from_p2, test_mess, sizeof(test_mess));

  printf("P2 said: %s\n", test_mess);
}

int main(){
  int from_p2;
  int to_p2 = conn_p2(&from_p2);

  printf("Time to play Tic-Tac-Toe. Your move!!\n")

  char tic_tac_toe[3][3] = {0};

  while(check_win()){
    printf("The current board: \n");
    print_board(tic_tac_toe);

    printf("Get ready to make your move.\n");

    int move[2] = get_move();
    tic_tac_toe[move[0]][move[1]] = 'X';

    check_move(move);

    write(to_p2, tic_tac_toe, sizeof(char) * 9);

    printf("Waiting for Player 2's move\n");

    read(from_p2, tic_tac_toe, sizeof(char) * 9);

    printf("Move received!\n");
  }

  /*
  char move[4];
  printf("Player1 enter your move in this format: row col\n");

  fgets(move, 4, stdin);
  *strchr(move, '\n') = 0;

  printf("Here's your move (row col): %s\n", move);

  write(to_cli, move, sizeof(char*));
  */
}
