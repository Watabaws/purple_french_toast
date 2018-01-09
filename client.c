

int main() {

  int to_server;
  int from_server;

  from_server = client_handshake(&to_server);
  char input[100];
  while(1){
    printf("Message to server:\n");
    fgets(input, BUFFER_SIZE, stdin);
    *strchr(input, '\n') = 0;
    write(to_server, input, sizeof(char *));
  }
}
