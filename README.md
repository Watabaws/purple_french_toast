# purple_french_toast

Cynthia Cheng and Adam Abbas 
Period 10 

## Description
A program simulating an arcade, where you can select from multiple games (Tic Tac Toe and Blackjack) and play with another user. The users are running on different terminals and send messages to one another. When one user wins the game, the connection is broken and the user can play another game. 

## Files
global_funcs.c - contains game functions that player1.c and player2.c use

player_connection.c - creates a connection between player1 and player2 using pipes 

player1.c - sends messages to player 2 and uses functions from global_funcs.c to make their next move, also breaks connection between users 

player2.c - sends messages to player 1 and uses functions from global_funcs.c to make their next move, also breaks connection between users 

BattleShip.c, Minesweeper, Connect 4 - didn’t have time to implement, game code

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
Type in: make player1

Open a second terminal and cd into purple_french_toast

Type in: make player2

Then return to the first terminal and type: ./player1

Then return to the second terminal and type: ./player2

Finally select the game you’d like to play. 

Good Luck!

## Known Bugs
Unable to split in Blackjack 
