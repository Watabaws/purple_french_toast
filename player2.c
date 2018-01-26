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
  int won = 1;
  while(won){
    printf("The current board: \n");
    print_board(tic_tac_toe);

    printf("Waiting on Player 1's Move!!\n");

    int * move;

    read(from_p1, move, sizeof(int) * 9);
    printf("Move received!\n");

    tic_tac_toe[move[0]][move[1]] = 'X';
    won = check_win(move, tic_tac_toe);

    if(won){
      print_board(tic_tac_toe);

      printf("What is your move?");
      move = get_move();

      tic_tac_toe[move[0]][move[1]] = 'O';

      won = check_win(move, tic_tac_toe);
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
