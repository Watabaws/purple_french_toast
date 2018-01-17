all: player1 player2

player1: player1.o player_connection.o
	gcc -o player1 player1.c

player2: player2.o player_connection.o
	gcc -o player2 player2.c

player1.o: player1.c
	gcc -c player1.c

player2.o: player2.c
	gcc -c player2.c

player_connection.o: player_connection.c
	gcc -c player_connection.c
