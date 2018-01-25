#include "player2_connection.c"

int main() {
  int from_p1;
  int to_p1 = conn_p1(&from_p1);
  
  char test_mess[50];
  
  read(from_p1, test_mess, sizeof(test_mess));
  //sprintf(test_mess, "P1 said %s\n", test_mess);
  printf("%s", test_mess);
  
  write(to_p1, test_mess, sizeof(test_mess));
  
}
