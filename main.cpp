#include "function.h"
int main (){
  int deck [SUITS][FACES] = {0};
  char* suits[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
  char* faces[FACES] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
  shuffleCards(deck);
  //printCardsShuffling(deck,suits,faces);
  //int** hand = dealingForHand(deck); 
    /*for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cout << hand[i][j] << " " ;
    }
    cout << endl;
  }*/
  //int n = 3;
  //int ***hands = dealingForHands(deck,n);
  int hand1[5][2] = {{0,8},{2,8},{1,7},{0,2},{2,12}};
  int **hand = testHand(hand1);
  printHand(hand,suits,faces);
  /*for (int i = 0; i < 5; i++)//gan gia tri cho mang result
	{
		for (int j = 0; j < 2; j++)
		{
			cout << hand[i][j] << " ";
		}
    cout << endl;
	}*/
  NotiPlayer(hand);

}
