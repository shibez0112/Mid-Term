#include "function.h"
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
	srand(time(NULL));
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
	}
	
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
