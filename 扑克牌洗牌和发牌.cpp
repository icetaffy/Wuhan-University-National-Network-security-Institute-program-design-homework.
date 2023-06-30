#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define row 4
#define column 13
void Shuffle(int a[][column] )
{
	int rows,col;
	int cardnumber;
	for (cardnumber = 1; cardnumber <= row * column; cardnumber++)
	{
		do
		{
			rows = rand() % 4;
			col = rand() % 13;
		} while (a[rows][col] != 0);
		a[rows][col] = cardnumber;
	}
}
void Deal_cards(int a[][13],const char*wFace[],const char*wSuit[])
{
	int rows;
	int col;
	int cardnumber;
	for (cardnumber = 1; cardnumber <= row * column; cardnumber++)
	{
		for (rows = 0; rows <= 3; rows++)
			for (col = 0; col <= 12; col++)
			{
				if (a[rows][col] == cardnumber)
				{
					printf("%-5s:%-8s%2c",wFace[col],wSuit[rows],cardnumber%4==0?'\n':' ');
				}
			}
	}
}
int main(void)
{
	const char* suit[row] = { "Hearts","Diamonds","Clubs","Spades" };
	const char* face[column] = { "Ace","Deuce","3","4" ,"5","6","7","8","9","10","Jack","Queen","King"};
	int deck[row][column] = { 0 };
	time_t t;
	srand((unsigned int)time(&t));
	Shuffle(deck);
	Deal_cards(deck, face, suit);
	return 0;
}

