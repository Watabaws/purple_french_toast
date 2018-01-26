#include "global_funcs.c"

int conn_p1(int *from_p1){
  printf("Hi Player 2! What would you like your username to be\n");

  char p2name[100];
  fgets(p2name, 100, stdin);
  *strchr(p2name, '\n') = 0;

  printf("Awesome! Welcome to R-C-ADE! Let's find player 1\n");
  int tto = open("Two_to_One", O_WRONLY, 0);

  mkfifo("One_to_Two", 0600);

  write(tto, p2name,  sizeof(p2name));

  int ott = open("One_to_Two", O_RDONLY, 0);

  char p1name[100];
  read(ott, p1name, sizeof(p1name));

  printf("Found player: %s\n", p1name);

  printf("Time to play!!\n");

  *from_p1 = ott;

  return tto;


}
