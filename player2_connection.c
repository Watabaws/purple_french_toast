#include "player_connection.h"

inc conn_p1(){
  printf("Hi Player 2! What would you like your username to be\n");

  char p2name[100];
  fgets(p2name, 100, stdin);
  *strchr(p1name, '\n') = 0;

  printf("Awesome! Welcome to R-C-ADE! Let's find player 1\n");
  int tto = open("Two_to_One", O_WRONLY, 0);

  mkfifo("One_to_Two");

  write(tto, p2name,  sizeof(p2name));

  int ott = open("One_to_Two", O_RDONLY, 0);

  char p1name[100];
  read(ott, p1name, sizeof(p1name));

  printf("Found player: %s\n");

  printf("Time to play!!\n")


}
