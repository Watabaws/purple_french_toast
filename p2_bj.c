#include "Blackjack.c"

void p2_blackjack(int to_p1, int from_p1){
    int deck[52] = {0};
  int playerOneSum = 0;
  int playerTwoSum = 0;
  int cardIn;
  
  shuffle(deck);
  
  read(from_p1, &cardIn, sizeof(cardIn));
  
  int p1_card2;
  
  read(from_p1, &p1_card2, sizeof(p1_card2));
  
  int card1 = dealCard(cardIn, deck);
  pic(card1);
  
  playerTwoSum += ConvertCardToVal(dealCard(cardIn, deck));
  cardIn++;
  
  int card2 = dealCard(cardIn, deck);
  pic(card2);
  playerTwoSum += ConvertCardToVal(dealCard(cardIn, deck));
  cardIn++;
  
  printf("Player one's last card was:\n");
  pic(p1_card2);
  write(to_p1, &card2, sizeof(card2));
  int draw = 1;
  
  while(playerTwoSum <= 21 && draw){
      printf("Your sum is %d\n", playerTwoSum);
      printf("Do you want to draw? Type any number for yes and 0 for no.\n");
      char response[5];
      fgets(response, 5, stdin);
      *strchr(response, '\n') = 0;
      
      draw = atoi(response);
      
      if(draw){
          shuffle(deck);
          pic(dealCard(cardIn, deck));
          playerTwoSum += ConvertCardToVal(dealCard(cardIn, deck));
          cardIn++;
      }
  }
  
  
  write(to_p1, &playerTwoSum, sizeof(playerTwoSum));
  read(from_p1, &playerOneSum, sizeof(playerOneSum));
  
  if(playerTwoSum > 21){
      printf("You lose.\n");
  }
  else{
      printf("Player 1's sum was %d\n", playerOneSum);
      if(playerOneSum > 21){
          printf("You win!\n");
      } else {
      if(playerTwoSum > playerOneSum){
          printf("You win!\n");
      }
      else if(playerOneSum > playerTwoSum){
          printf("You lose.\n");
      }
      else{
          printf("Draw.\n");
      }}
  }
  

}
