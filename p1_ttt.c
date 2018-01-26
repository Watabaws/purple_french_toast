#include "global_funcs.c"

void player_1_ttt(int to_p2, int from_p2){    
    printf("Time to play Tic-Tac-Toe. Your move!!\n");

    char tic_tac_toe[3][3];
    int i,j;
    
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            tic_tac_toe[i][j] = '-';
        }
    }

    int won = 0;
    while(!won){
        printf("The current board: \n");
        print_board(tic_tac_toe);

        printf("Get ready to make your move.\n");

        int * move = get_move();
        while(tic_tac_toe[move[0]][move[1]] != '-'){
            printf("Invalid move!\n");
            move = get_move();
        }
            
        tic_tac_toe[move[0]][move[1]] = 'X';
        
        print_board(tic_tac_toe);
        //printf("Sending first arg: %d\n", move[0]);
        //printf("Sending second arg: %d\n", move[1]);
        //printf("precheck: %d\n",won);
        won = CheckTicTacToe(tic_tac_toe);
        //printf("postcheck: %d\n", won);
        //printf("Sending first arg: %d\n", move[0]);
        //printf("Sending second arg: %d\n", move[1]);
        write(to_p2, &move[0], sizeof(int) * 2);
        write(to_p2, &move[1], sizeof(int) * 2);

        if(!won){
            printf("Waiting for Player 2's move\n");

            read(from_p2, move, sizeof(int) * 2);
            printf("Move received!\n");
            
            print_board(tic_tac_toe);

            tic_tac_toe[move[0]][move[1]] = 'O';
            
            print_board(tic_tac_toe);

            //printf("precheck: %d\n",won);
            won = CheckTicTacToe(tic_tac_toe);
            //printf("postcheck: %d\n", won);
        }
        }

        declare_winner(won);
}
