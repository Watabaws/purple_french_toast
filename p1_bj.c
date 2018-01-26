#include "Blackjack.c"

void p1_blackjack(int to_p2, int from_p2){
    
    printf("Welcome to Blackjack!\n");
    
    int deck[52] = {0};
    int playerOneSum = 0;
    int playerTwoSum = 0;
    int cardIn = 0;
    
    shuffle(deck);
    
    int card1 = dealCard(cardIn, deck);
    pic(card1);
    playerOneSum += ConvertCardToVal(dealCard(cardIn, deck));
    cardIn++;
    
    int card2 = dealCard(cardIn, deck);
    pic(card2);
    playerOneSum += ConvertCardToVal(dealCard(cardIn, deck));
    
    write(to_p2, &cardIn, sizeof(cardIn));
    write(to_p2, &card2, sizeof(card2));
    int p2_card2;
    read(from_p2, &p2_card2, sizeof(p2_card2));
    printf("Player two's last card was: \n");
    pic(p2_card2);
    int draw = 1;
    
    while(playerOneSum <= 21 && draw){
        printf("Your sum is: %d \n", playerOneSum);
        printf("Do you want to draw? Type any number for yes, and 0 for no.\n");
        char response[5];
        fgets(response, 5, stdin);
        *strchr(response, '\n') = 0;
        
        draw = atoi(response);
        
        if(draw){
            shuffle(deck);
            pic(dealCard(cardIn, deck));
            playerOneSum += ConvertCardToVal(dealCard(cardIn, deck));
            cardIn++;
        }
    }

    read(from_p2, &playerTwoSum, sizeof(playerTwoSum));
    write(to_p2, &playerOneSum, sizeof(playerOneSum));

    if(playerOneSum > 21){
        printf("You lose.\n");
    }
    else{
        printf("Player 2's sum was %d\n", playerTwoSum);
        if(playerTwoSum > playerOneSum){
            printf("You lose.\n");
        }
        else if (playerOneSum > playerTwoSum){
            printf("You win!\n");
        }
        else{
            printf("Draw.\n");
        }
    }
}
