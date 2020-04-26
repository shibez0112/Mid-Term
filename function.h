#include <iostream>
using namespace std;
#define SUITS 4
#define FACES 13
void shuffleCards(int deck[][FACES]);
void printCardsShuffling(int deck[][FACES], char* suits[], char* faces[]);
int** dealingForHand(int deck[SUITS][FACES]);
void printHand(int** hand, char* suits[], char* faces[]);
int* createHandTest(int deck[SUITS][FACES], int a[]);
int*** dealingForHands(int deck[SUITS][FACES], int n);
int* GetTheLocation(int deck[SUITS][FACES], int n) ;
int NotiPlayer(int **hand) ;
int **testHand(int hand1[5][2]);
