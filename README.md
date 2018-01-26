# purple_french_toast
## R-C-ADE

Cynthia Cheng and Adam Abbas 
Period 10 

## Description
A program simulating an arcade, where you can select from multiple games (Tic Tac Toe and Blackjack) and play with another user. The users are running on different terminals and send messages to one another. When one user wins the game, the connection is broken and the user can play another game. 

## Files
global_funcs.c - contains game functions that player1.c and player2.c use

player_connection.c - creates a connection between player1 and player2 using pipes 

player1.c - The wrapper code for player 1, calls the functions to connect and play with player 1

player2.c - The wrapper code for player 2, calls the functions to connect and play with player 1 

P1_bj.c - Code to play blackjack as player 1, called by player1.c

P2_bj.c - Code to play blackjack as player 2, called by player2.c

P1_ttt.c - Code to play tic-tac-toe as player 1, called by player1.c

P2_ttt.c - Code to play tic-tac-toe as player 2, called by player2.c

Player1_connection.c - Code to establish a connection with player 2, giving you file descriptors to talk to and listen to player 2

Player2_connection.c - Code to establish a connection with player 1, giving you file descriptors to talk to and listen to player 1

BattleShip.c, Minesweeper.c, ConnectFour.c - didn’t have time to implement, game code

## Game Instructions
Tic Tac Toe - objective: get three in a row

Take turns filling in a board

Try to get three of your pieces (either a ‘X’ or ‘O’) in a row

Win! 

BlackJack - objective: get closer to 21 than your opponent (but not over 21)

Draw two cards 

Continue to Hit (draw another card) until you Stand (abstain from card drawing) or reach over 21. 

Compare and win!

Values of Cards:

Aces: 1 or 11 (you can choose but if you input something invalid will default to 1)

Face Cards: 10

Everything else: the number on the card

## Instructions

Open terminal and cd into purple_french_toast

Type in: `make`

In the first terminal type: `./player1`

Open up a second terminal and type: `./player2`

Follow the instructions! You’ll be able to establish a connection, pick a game, play it, and have fun!!

Good Luck!

## Known Bugs

Unable to split in Blackjack 

Certain inputs (that are completely not what we asked for) can lead to a segfault.
