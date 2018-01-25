#include "player2_connection.c"

int main() {

  int to_server;
  int from_server;
  int from_serv;
  int to_serv;

  from_server = client_handshake(&to_server);

  printf("[player2] connected to player 1!\n");

    char name[100];
    char p1_move[4];
    printf("What is your player name?\n");
    fgets(name, 100, stdin);
    *strchr(name, '\n') = 0;

    write(to_server, name, sizeof(char *));

    printf("[player2] write complete \n");
    printf("[player2] beginning handshake... \n");
    to_serv = server_handshake_two(&from_serv);
    printf("[player2] handshake complete... \n");

    char p1name[100];
    printf("preparing to read from player1!! %d \n", to_serv);
    read(to_serv, p1name, sizeof(char*));

    printf("Hi %s! Looking forward to playing with u. \n", p1name);

    char tic_tac_toe[3][3];

    //printboard

    read(to_serv, p1_move, 4);

    printf("Here is player1's move: %s\n", p1_move);
}
