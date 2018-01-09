#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stringh>
#include <errno.h>

int server_handshake(int *to_client){
  int from_client;
  char buffer[10000];
  mkfifo("mario", 0600);
  printf("[server] handshake: making well known pipe and waiting for pp \n");
  from_client = open("mario", O_RDONLY, 0);
  read(from_client, buffer, sizeof(buffer));
  printf("[server] handshake: received [%s]\n", buffer);
  remove("mario");
  printf("[server] removed wkp");

  *to_client = open(buffer, O_WRONLY, 0);
  write(*to_client, buffer, sizeof(buffer));

  read(from_client, buffer, sizeof(buffer));
  printf("[server] received: %s\n", buffer);

  return from_client

}

int client_handshake(int *to_server){
  int from_server;
  char buffer[1000];

  printf("[client] handshake: connecting to well known pipe\n");
  *to_server = open("mario", O_WRONLY, 0);

  sprintf(buffer, "%d", getpid());
  mkfifo(buffer, 0600);

  write(*to_server, buffer, sizeof(buffer));

  from_server = open(buffer, O_RDONLY, 0);
  read(from_server, buffer, sizeof(buffer));

  remove(buffer);
  printf("[client] removed private pipe\n");

  write(*to_server, ACK, sizeof(buffer));

  return from_server;
}
