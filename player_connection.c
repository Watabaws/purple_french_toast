#include "player_connection.h"

void error_check(){
    printf("Error! : %s\n", strerror(errno));
}

int server_handshake(int *to_client){
  int from_client;
  char buffer[10000];
  char cpbuff[10000];

  mkfifo("mario", 0600);
  printf("[player1] Waiting for player 2... \n");
  from_client = open("mario", O_RDONLY, 0);
  read(from_client, buffer, sizeof(buffer));
  printf("[player1] received [%s]\n", buffer);
  *to_client = open(buffer, O_WRONLY, 0);
  remove("mario");
  printf("Removing pipe\n");
  error_check();

  strcpy(buffer, cpbuff);
  printf("[player1] removed well known connection\n");
  write(*to_client, buffer, sizeof(buffer));

  read(from_client, buffer, sizeof(buffer));
  printf("[player1] received %s\n", buffer);
  if(strcmp(buffer, cpbuff) != 0){
    printf("Did not receive proper message from p2\n");
    exit(1);
  }

  return from_client;
}

int client_handshake(int *to_server){
  int from_server;
  char buffer[1000];
  char pbuffer[1000];

  *to_server = open("mario", O_WRONLY, 0);

  sprintf(buffer, "%d", getpid());
  strcpy(buffer, pbuffer);
  mkfifo(buffer, 0600);

  write(*to_server, buffer, sizeof(buffer));
  printf("[player2] connected to player1\n");
  from_server = open(buffer, O_RDONLY, 0);
  read(from_server, buffer, sizeof(buffer));
  printf("[player2] received %s\n", buffer);
  remove(buffer);
  printf("[player2] removed private pipe\n");

  if(strcmp(buffer, pbuffer) != 0){
    printf("Did not receive proper message from p1\n");
    exit(1);
  }

  write(*to_server, buffer, sizeof(buffer));

  return from_server;
}

int server_handshake_two(int *to_client){
  int from_client;
  char buffer[10000];
  char cpbuff[10000];

  mkfifo("game", 0600);
  printf("[player2] Waiting for player 1... \n");
  from_client = open("mario", O_RDONLY, 0);
  read(from_client, buffer, sizeof(buffer));
  printf("[player2] received [%s]\n", buffer);
  *to_client = open(buffer, O_WRONLY, 0);
  remove("game");
  printf("Removing pipe\n");
  error_check();

  strcpy(buffer, cpbuff);
  printf("[player2] removed well known connection\n");
  write(*to_client, buffer, sizeof(buffer));

  read(from_client, buffer, sizeof(buffer));
  printf("[player2] received %s\n", buffer);
  if(strcmp(buffer, cpbuff) != 0){
    printf("Did not receive proper message from p2\n");
    exit(1);
  }

  return from_client;
}

int client_handshake_two(int *to_server){
  int from_server;
  char buffer[1000];
  char pbuffer[1000];

  *to_server = open("game", O_WRONLY, 0);

  sprintf(buffer, "%d", getpid());
  strcpy(buffer, pbuffer);
  mkfifo(buffer, 0600);

  write(*to_server, buffer, sizeof(buffer));
  printf("[player1] connected to player2\n");
  from_server = open(buffer, O_RDONLY, 0);
  read(from_server, buffer, sizeof(buffer));
  printf("[player1] received %s\n", buffer);
  remove(buffer);
  printf("[player1] removed private pipe\n");

  if(strcmp(buffer, pbuffer) != 0){
    printf("Did not receive proper message from p1\n");
    exit(1);
  }

  write(*to_server, buffer, sizeof(buffer));

  return from_server;
}
