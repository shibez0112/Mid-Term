#include "function.h"
int countSameFace(int** hand)     //dem so la bai giong nhau
{                                 //=> tu quy, 3 la, 1 doi
    int count, max = 0;
    for (int i = 0; i < 4; i++){
            count = 1;
        for (int j = i + 1; j < 5; j++){
            if (hand[i][1] == hand[j][1])
            count ++;
        }
        if (count > max)
                max = count;

    }
    return max;
}

void swap(int &a, int &b)
{
    int x = a;
    a = b;
    b = x;
}
int sort(int** hand, int s[5])  //tao 1 mang sap xep bai tang dan
{

    for (int i = 0; i < 5; i++)
    {
        s[i] = hand[i][1];
    }
    for(int i = 0; i < 5; i++)
    {
        for(int j = i+1; j < 5; j++)
        {
            if(s[i] > s[j])
                swap(s[i],s[j]);
        }
    }
    return s[5];
}

int isPair(int** hand)
{
    if (countSameFace(hand) == 2)
        return 1;
    else return 0;
}

int isThreeOfAKind(int** hand)
{
    if (countSameFace(hand) == 3)
        return 1;
    else return 0;
}

int isFourOfAKind(int** hand)
{
    if (countSameFace(hand) == 4)
        return 1;
    else return 0;
}

int isFlush(int** hand)
{
    if (hand[0][0] == hand[1][0] == hand[2][0] == hand[3][0] && hand[0][0] == hand[4][0])
        return 1;
    else return 0;
}

int isStraight(int** hand)
{
    int check = 1, s[5];
    sort(hand, s);

    for (int i = 0; i < 4; i++)
    {
        if ((s[i+1] - s[i]) != 1){
            check = 0;
            break;
        }
    }
    return check;
}

int isStraightFlush(int** hand)
{
    if (isFlush(hand) == 1 && isStraight(hand) == 1)
        return 1;
    else return 0;
}

int isFullHouse(int** hand)
{
    int s[5];
    sort(hand,s);
    if (((s[0] == s[1] != s[2]) || (s[4] == s[3] != s[2])) && isThreeOfAKind(hand) == 1) //kiem tra 2 la giong nhau va khac 3 la con lai
        return 1;
    else return 0;
}

int isTwoPairs(int** hand)
{
    int s[5], count = 0;
    sort(hand,s);
    for (int i = 0; i < 4; i++)
    {
        if (s[i] - s[i+1] == 0)
            count++;
    }
    if (count == 2 && isPair(hand) == 1)  //co 2 doi va 2 la giong nhau != tu quy
        return 1;
    else return 0;
}

int getHighestCard(int** hand)
{
    int s[5];
    sort(hand, s);
    if (countSameFace(hand) == 1)
        return s[4];
    else return 0;
}
void shuffleCards(int deck[][FACES]) 
{
	int tmp = 0;
	for (int i = 0; i < 4; i++) // khoi tao 52 gia tri cho 52 o trong
	{
		for (int j = 0; j < 13; j++)
		{
			deck[i][j] = tmp + 1;
			tmp += 1;
		}
	}
	/*srand(time(NULL));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			int a = 1 + (rand() % (52)); //l?y ng?u nhiên 1 giá tr? trong kho?ng 1-52
			if (a > 13) //n?u a > 13 thì a n?m ? hàng th? 1,2,3
			{
				int c = a / 13; // xác d?nh v? trí dòng 
				int d = a % 13; // xác d?nh v? trí c?t
				int e = deck[i][j]; // b?t d?u swap giá tr? ? 2 v? trí bi?n ch?y dang ? và v? trí random nh?n du?c 
				deck[i][j] = deck[c][d-1];
				deck[0][a - 1] = e;

			}
			else
			{
				int b = deck[i][j]; // swap tuong t? nhu trên nhung ? hàng th? 0
				deck[i][j] = deck[0][a - 1];
				deck[0][a - 1] = b;
			}
		}
	}*/
	
}
void printCardsShuffling(int deck[][FACES], char* suits[], char* faces[])
{
    bool found;
    for (int n = 0; n <= 52; n++)
    {
        found = false;
        for (int i = 0; found == false && i < SUITS; i++)
        {
            for(int j = 0; found == false && j < FACES; j++)
            {
                if (deck[i][j] == n)    //Tim gia tri tu 1-52
                {
                    cout << deck[i][j] << " " << suits[i] << ", " << faces[j] << endl;
                    found=true;         //dieu kien dung vong lap
                }
            }
        }
    }
}
int** dealingForHand(int deck[SUITS][FACES])
{
	int array[5] ={0};
	bool check ;
	srand(time(NULL));
	do 
	{
		for (int x = 0; x <5; x++)
		{
			array[x] = 1 + (rand() % (52));
		}
		int count1 = 0;
		for (int y = 0; y < 5; y++)
		{
			for (int z = y+1; z < 5-y-1; z++)
			{
				if ( array[z] == array[y])
				{
					count1++;
				}
			}
		}
		if (count1 == 0)
		{
			check = true ;
		}
		else 
		{
			check = false ;
		}
	}
	while (check == false) ;	
	//ham tren dung de generate 5 gia tri ngau nhien ko trung nhau tu bo bai
	int count = 0,temp = 0;
	int newarray[10] = {0};
	for (int k = 0; k < 5; k++)//vong lap de gan cac vi tri cua quan bai vao 1 mang
    {
        int found = false;
        for (int i = 0; found == false && i < SUITS; i++)
        {
            for(int j = 0; found == false && j < FACES; j++)
            {
                if (deck[i][j] == array[count])    //Tim gia tri 
                {   
					newarray[temp] = i;
					newarray[temp+1] = j;
					temp += 2;
					count++;
                    found=true;         //dieu kien dung vong lap
                }
            }
        }
    }

	int** result = new int*[5];
	for (int i = 0; i < 5; i++)
	{
		result[i] = new int [2];
	} 
	temp = 0;
	for (int i = 0; i < 5; i++)//gan gia tri cho mang result
	{
		for (int j = 0; j < 2; j++)
		{
			result[i][j] = newarray[temp];
			temp++;
		}
	}

	return result;
}
void printHand(int** hand, char* suits[], char* faces[])
{
    for (int i = 0; i < 5; i++){
        cout << suits[hand[i][0]] << ", " << faces[hand[i][1]] << endl;
    }
}
int* createHandTest(int deck[SUITS][FACES], int a[])
{
	for (int i = 0; i < 5; i++)
	{
		a[i] = deck[1][i];
	}
	return a;
}
int *Into1Demensional(int deck[SUITS][FACES])//ham nay de chuyen mang 2 chieu thanh 1 chieu
{
	int *array = new int[52];
	int count = 0; 
	for (int i = 0; i < SUITS; i++)
	{
		for (int j = 0;j < FACES; j++)
		{
			array[count] = deck[i][j];
			count++;
		}
	}
	return array;
}
int* GetTheLocation(int deck[SUITS][FACES], int n) 
{	
	int *arraytmp = Into1Demensional(deck);//Ham chua cac gia tri mang 2 chieu thanh 1 chieu 
	int array[n*5]={0}; //tao mang chua so quan bai chia cho moi nguoi
	int count1=0;
	for (int i =0; i < n; i++)
	{	
		for (int j = 0;j < 5;j++)
		{
			array[count1]= arraytmp [i+j+(n-1)*j];//i+j+n*j bieu thi quan bai ma no se lay tu deck, theo thu tu
			count1++;
		}
	}

	int count = 0,temp = 0;
	int *newarray = new int [n*10];// tao mang chua vi tri cua cac quan bai  
	for (int l = 0; l < n; l++)
	{
		for (int k = 0; k < 5; k++)//vong lap de gan cac vi tri cua quan bai vao 1 mang
    	{
        	int found = false;
        	for (int i = 0; found == false && i < SUITS; i++)
        	{
            	for(int j = 0; found == false && j < FACES; j++)
            	{
                	if (deck[i][j] == array[count])    //Tim gia tri 
                	{   
						newarray[temp] = i;
						newarray[temp+1] = j;
						temp += 2;
						count++;
                    	found=true;         //dieu kien dung vong lap
                	}
           	 }
       		}
		
    	}
	}
	return newarray;
}
int*** dealingForHands(int deck[SUITS][FACES], int n)
{
	int *array = GetTheLocation(deck,n);
	int*** distribute = new int**[n];
	for (int i = 0;i < n; i++ )
	{
		distribute[i] = new int *[5];
		for (int j = 0; j <5; j++)
		{
			distribute[i][j] = new int[2];
		}
	}	
	int count = 0;
	for (int i= 0;i < n ; i++)
	{
		for (int j = 0; j < 5;j++) 
		{
			for (int k = 0; k < 2; k++)
			{
				distribute[i][j][k] = array[count];
				count++;
			}
		}
	}
	return distribute;
}
int NotiPlayer(int **hand) 
{	
	if(isStraightFlush(hand))
		{
		cout << "You have Straight Flush!!!" << endl;
		return 0;
		}
	else if (isFourOfAKind(hand)) 
		{
		cout << "You have Four of A Kind!!!"<< endl;
		return 0;
		}
	else if (isFullHouse(hand))
		{
		cout << "You have Full House!!!" << endl;
		return 0;
		}
		
	else if (isFlush(hand))
		{
		cout << "You have Flush!!!" << endl;
		return 0;
		}
	else if (isStraight(hand))
		{
		cout << "You have Straight!!!" << endl;
		return 0;
		}
	else if (isThreeOfAKind(hand))
		{
		cout << "You have Three Of A Kind !!!" << endl;
		return 0;
		}
	else if (isTwoPairs(hand))
		{
		cout << "You have Two Pairs !!!" << endl;
		return 0;
		}
	else if (isPair(hand))
		{
		cout << "You have a Pair !!! "<< endl;
		return 0;
		}
	else 
		{
			cout << "Your highest value card is " << getHighestCard(hand) << endl;
		}
}
int **testHand(int hand1[5][2])
{
	int** result = new int*[5];
	for (int i = 0; i < 5; i++)
	{
		result[i] = new int [2];
	} 
	for (int i = 0; i < 5; i++)//gan gia tri cho mang result
	{
		for (int j = 0; j < 2; j++)
		{
			result[i][j] = hand1[i][j];
		}
	}

	return result;
}