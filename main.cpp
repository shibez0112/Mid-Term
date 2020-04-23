#include "function.h"
int main (){
  int deck [SUITS][FACES] = {0};
  char* suits[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
  char* faces[FACES] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
  shuffleCards(deck);
  //printCardsShuffling(deck,suits,faces);
  int** hand = dealingForHand(deck); 
  printHand(hand,suits,faces);
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cout << hand[i][j] << " " ;
    }
    cout << endl;
  }
  return 0;
}