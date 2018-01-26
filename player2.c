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
  char tic_tac_toe[3][3];
  int i,j;
  for(i = 0; i < 3; i++){
      for(j = 0; j < 3; j++){
          tic_tac_toe[i][j] = '-';
      }
  }
  int won = 0;
  while(!won){
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
    print_board(tic_tac_toe);
    if(!won){
        move = get_move();
        while(tic_tac_toe[move[0]][move[1]] != '-'){
            printf("Invalid move!\n");
            move = get_move();
        }

        tic_tac_toe[move[0]][move[1]] = 'O';
        
        print_board(tic_tac_toe);
        
        printf("precheck: %d\n",won);
        won = CheckTicTacToe(tic_tac_toe);
        printf("postcheck: %d\n", won);
        
        write(to_p1, move, sizeof(int) * 2);
    }
  }
  
  declare_winner(won);

}
