#include <stdio.h>
#include <time.h>


void swap(int a[52], int b, int c){
  int temp = a[b];
  a[b] = a[c];
  a[b] = temp;
}

int shuffle(int cards[52]){
  srand(time(NULL));
  for (int i =0; i < 52; i++){
    printf ("%d \n", cards[i]);
  }
  for (int i = 1; i< 14; i++){
    cards[i*4-1] = i;
    cards[i*4-2] = i;
    cards[i*4-3] = i;
    cards[i*4-4] = i;
  }
  int randnum;
  for (int i =0; i < 52; i++){
    randnum = rand()%((51-0)+0);
    printf ("%d \n", cards[i]);
    swap(&cards[52], i, randnum);
    printf ("%d \n", cards[i]);
  }
}


int ConvertCardToVal(int card){
  if (card == 11 || card == 12 || card == 13){
    return 10;
  }
  else if (card == 1){
    //can be 1 or 11 tho
    return 1;
  }
  return card;
}

int dealCard(int i, int cards[]){
  i = i +1;
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
  shuffle(&deck[52]);
  int playerOneSum = 0;
  int playerTwoSum = 0;
  int cardIn = 0;
  // pic(dealCard(deck, cardIn));
  // pic(dealCard(deck, cardIn));


}
