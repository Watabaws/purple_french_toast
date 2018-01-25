#include "player2_connection.c"

void test_conn(){
  char test_mess[50];

  read(from_p1, test_mess, sizeof(test_mess));
  //sprintf(test_mess, "P1 said %s\n", test_mess);
  printf("%s", test_mess);

  write(to_p1, test_mess, sizeof(test_mess));
}

int main() {
  int from_p1;
  int to_p1 = conn_p1(&from_p1);

  printf("Time to play Tic-Tac-Toe!\n")
  char tic_tac_toe[3][3] = {0};
    while(check_win()){
    printf("The current board: \n")
    print_board(tic_tac_toe);

    printf(" Waiting on Player 1's Move!!\n");

    read(from_p1, tic_tac_toe, sizeof(char) * 9)

    printf("Move received!\n");

    print_board(tic_tac_toe);

    printf("What is your move?");
    int move[2] = get_move();

    tic_tac_toe[move[0], move[1]] = 'O';

    check_move(move);

    write(to_p1, tic_tac_tow, sizeof(char) * 9)
  }

}
