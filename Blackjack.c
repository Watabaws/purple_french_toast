#include <stdio.h>
#include <time.h>



int shuffle(int cards[52]){
  srand(time(NULL));
  for (int i = 1; i< 14; i++){
    cards[i*4-1] = i;
    cards[i*4-2] = i;
    cards[i*4-3] = i;
    cards[i*4-4] = i;
  }
  int randnum;
  for (int i = 0; i < 52; i++){
    randnum = rand()%((51-0)+0);
    int temp = cards[i];
    cards[i] = cards[randnum];
    cards[randnum] = temp;
  }
  for (int i = 0; i < 52; i++){
    printf ("%d \n", cards[i]);
  }
}


int ConvertCardToVal(int card){
  if (card == 11 || card == 12 || card == 13){
    return 10;
  }
  //if user chooses Ace to be 11 change its num to 14
  else if (card == 1){
    return 1;
  }
  else if (card == 14){
    return 11;
  }
  return card;
}

int dealCard(int i, int cards[]){
  if (cards[i] == 1){
    printf("Would you like to use the Ace with a value of 1 or 11?");
  }
  return cards[i];
}


void pic(int num){
  if (num == 1){
    printf("*******\n");
    printf("*     *\n");
    printf("*     *\n");
    printf("*  A  *\n");
    printf("*     *\n");
    printf("*******\n\n");
  }
  else if (num == 11){
    printf("*******\n");
    printf("*     *\n");
    printf("*     *\n");
    printf("*  J  *\n");
    printf("*     *\n");
    printf("*******\n\n");
  }
  else if (num == 12){
    printf("*******\n");
    printf("*     *\n");
    printf("*     *\n");
    printf("*  Q  *\n");
    printf("*     *\n");
    printf("*******\n\n");
  }
  else if (num == 13){
    printf("*******\n");
    printf("*     *\n");
    printf("*     *\n");
    printf("*  K  *\n");
    printf("*     *\n");
    printf("*******\n\n");
  }
  else{
    printf("*******\n");
    printf("*     *\n");
    printf("*     *\n");
    printf("*  %d  *\n", num);
    printf("*     *\n");
    printf("*******\n");
  }
}


int main(){
  int deck[52] = {0};
  shuffle(deck);
  int playerOneSum = 0;
  int playerTwoSum = 0;
  int cardIn = 0;
  pic(dealCard(cardIn, deck));
  playerOneSum += ConvertCardToVal(dealCard(cardIn, deck));
  cardIn++;
  pic(dealCard(cardIn, deck));
  playerOneSum += ConvertCardToVal(dealCard(cardIn, deck));
  printf("%d \n", playerOneSum);

}
