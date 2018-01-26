
#include "player1_connection.c"
#include "p1_ttt.c"
#include "p1_bj.c"

/*void test_conn(){
  char test_mess[50] = "Hi player2!!";

  write(to_p2, test_mess, sizeof(test_mess));

  read(from_p2, test_mess, sizeof(test_mess));

  printf("P2 said: %s\n", test_mess);
}*/

int main(){
  int from_p2;
  int to_p2 = conn_p2(&from_p2);

  //player_1_ttt(to_p2, from_p2);
  printf("Player 1! What game would you like to play? Type in 0 for tic-tac-toe and any other number for blackjack!\n");
  
  char respons[5];
  fgets(respons, 5, stdin);
  *strchr(respons, '\n') = 0;
  
  int response = atoi(respons);
  
  write(to_p2, &response, sizeof(response));
  
  if(!response){
      player_1_ttt(to_p2, from_p2);
  }
  else{
      p1_blackjack(to_p2, from_p2);
  }
}
        
