all: player1 player2

player1: player1.o player1_connection.c
	gcc -o player1 player1.c

player2: player2.o player1_connection.o
	gcc -o player2 player2.c

player1.o: player1.c p1_ttt.o Blackjack.o p1_bj.o
	gcc -c player1.c

player2.o: player2.c p2_ttt.o Blackjack.o p2_bj.o
	gcc -c player2.c

player1_connection.o: player1_connection.c global_funcs.o
	gcc -c player1_connection.c

player2_connection.o: player2_connection.c global_funcs.o
	gcc -c player2_connection.c

global_funcs.o: global_funcs.c
	gcc -c global_funcs.c

p1_ttt.o : p1_ttt.c
	gcc -c p1_ttt.c

p2_ttt.o: p2_ttt.c
	gcc -c p2_ttt.c

p1_bj.o: p1_bj.c
	gcc -c p1_bj.c

p2_bj.o: p2_bj.c
	gcc -c p2_bj.c

Blackjack.o: Blackjack.c
	gcc -c Blackjack.c


clean:
	rm *.o
