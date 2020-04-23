#include <iostream>
using namespace std;
#define SUITS 4
#define FACES 13
void shuffleCards(int deck[][FACES]);
void printCardsShuffling(int deck[][FACES], char* suits[], char* faces[]);
int** dealingForHand(int deck[SUITS][FACES]);
void printHand(int** hand, char* suits[], char* faces[]);
