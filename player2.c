#include "player2_connection.c"
#include "p2_ttt.c"
#include "p2_bj.c"

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
  
  //player_2_ttt(to_p1, from_p1);
  
  printf("Let's wait to see what game Player 1 chooses!\n");
  
  int game;
  read(from_p1, &game, sizeof(game));
  
  if(!game){
      player_2_ttt(to_p1, from_p1);
  }
  else{
      p2_blackjack(to_p1, from_p1);
  }

}
