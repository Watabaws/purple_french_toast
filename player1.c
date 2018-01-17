

int main(){
  int to_client;
  int from_client;
  int from_cli;
  char p2name[100];

  while(1){
    from_client = server_handshake(&to_client); //Set up connection with p2
    //to_cli = client_handshake(&from_cli)
    read(from_client, p2name, sizeof(char*));

    printf("[player1] Ready to play with %s\n", p2name);

    char[3][3] tic_tac_toe;

    //printboard

    char move[4];
    printf("Player1 enter your move in this format: row col\n");

    fgets(move, 4, stdin);
    *strchr(move, '\n') = 0;

    printf("Here's your move (row col): %s\n", move);

    write(to_client, move, sizeof(char*));

  }
}
