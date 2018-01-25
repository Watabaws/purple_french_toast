#include "player_connection.h"

int conn_p2(){
  printf("Hi Player 1! What would you like your name to be?\n");

  char p1name[100];
  fgets(p1name, 100, stdin);
  *strchr(p1name, '\n') = 0;

  printf("Awesome! Welcome to R-C-Ade! Let's wait for player 2\n");
  mkfifo("Two_to_One");

  int tto = open("Two_to_One", O_RDONLY, 0);

  char p2name[100];

  int reply = 0;
  char reply_str[4];
  //while(reply){
    read(tto, p2name, sizeof(p2name))

    printf("Found a player: %s\n", p2name);
  //  printf("Start a game with this player? Enter 1 to accept, and 0 to wait for another player.\n")

    //fgets(reply_str, 4, stdin);
    //*strchr(p1name, '\n') = 0;

    //reply = atoi(reply_str);
//  }
  printf("Let's connect!\n");
  int ott = open("One_to_Two", O_WRONLY, 0);

  write(ott, p1name, sizeof(p1name));



}
