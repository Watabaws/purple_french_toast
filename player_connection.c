#include "player_connection.h"

int server_handshake(int *to_client){
  int from_client;
  char buffer[10000];
  mkfifo("mario", 0600);
  printf("[player1] Waiting for player 2... \n");
  from_client = open("mario", O_RDONLY, 0);
  read(from_client, buffer, sizeof(buffer));
  printf("[player1] received [%s]\n", buffer);
  remove("mario");
  printf("[player1] removed well known connection");

  *to_client = open(buffer, O_WRONLY, 0);
  write(*to_client, buffer, sizeof(buffer));

  read(from_client, buffer, sizeof(buffer));
  printf("[player1] received: %s\n", buffer);

  return from_client;

}

int client_handshake(int *to_server){
  int from_server;
  char buffer[1000];

  printf("[player2] connected to player1\n");
  *to_server = open("mario", O_WRONLY, 0);

  sprintf(buffer, "%d", getpid());
  mkfifo(buffer, 0600);

  write(*to_server, buffer, sizeof(buffer));

  from_server = open(buffer, O_RDONLY, 0);
  read(from_server, buffer, sizeof(buffer));

  remove(buffer);
  printf("[player2] removed private pipe\n");

  return from_server;
}
