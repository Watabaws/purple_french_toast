#include "player_connection.c"

int main() {

  int to_server;
  int from_server;

  from_server = client_handshake(&to_server);

  printf("[player2] connected to player 1!\n");

    char name[100];
    char p1_move[4];
    printf("What is your player name?\n");
    fgets(name, 100, stdin);
    *strchr(name, '\n') = 0;

    write(to_server, name, sizeof(char *));

    char tic_tac_toe[3][3];

    //printboard

    read(from_server, p1_move, 4);

    printf("Here is player1's move: %s\n", p1_move);
}
