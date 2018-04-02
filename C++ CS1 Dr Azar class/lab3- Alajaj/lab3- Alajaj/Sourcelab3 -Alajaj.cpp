#include <iostream>
#include <time.h>
#include <iomanip>
#include <Windows.h>
#include <limits.h>
#include<string>

// Lab3 -Alajaj.cpp 
//
/* Abdullah Alajaj
4/11/2017
"I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else's work as my own."
*/

using namespace std;


void callCard(int, int, int, int[], int[]);
int callone(int, int, int[], int, int[]);
int sum(int, int[], int[], int, int[], int);
void printTotal(int, int[], int[]);
char FindPicture(int);
int cardsShiv(int[]);
int command(int, int, int[], int[]);
void winner(int, int[], int[], int);
//#include <stdio.h>
// col row

void gotoxy(int h, int w)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		COORD pos = { h, w };
		SetConsoleCursorPosition(hConsole, pos);
	}
	return;
}



int main()
{
	int cards[52], picked[52] = { 0 }, i, cal, raw, add = 0;
	int total[8] = { 0 }, win[8] = { 0 };
	char picture, ch = 'Y';
	srand(time(NULL));
	system("color 30"); //teel back color
	gotoxy(0, 22);

	cout << char(3) << char(4) << char(5) << char(6) << endl;

	cardsShiv(cards);

	cout << endl;

	//right justify the output
	cout << right;


	gotoxy(0, 0);

	cout << setw(8) << "dlr" << setw(8) << "plr1" << setw(8) << "plr2"
		<< setw(8) << "plr3" << setw(8) << "plr4" << setw(8) << "plr5"
		<< setw(8) << "plr6" << setw(8) << "plr7" << endl;

	gotoxy(0, 1);
	cout << setw(8) << "===" << setw(8) << "====" << setw(8) << "===="
		<< setw(8) << "====" << setw(8) << "====" << setw(8) << "===="
		<< setw(8) << "====" << setw(8) << "====" << endl;

	// Follow up here from 1:20 to end of lecture
	i = 0;
	cal = 0;
	raw = 2;
	while (cal < 8) // first card to everyone except dealer 
	{
		callCard(cal, raw, i, cards, total);

		cal++;
		i++;
	}
	sum(cal, total, picked, raw, cards, i);
	printTotal(cal, total, picked);
	cal = 0;
	raw = 3;
	while (cal < 8) // second card to everyone
	{
		callCard(cal, raw, i, cards, picked);
		sum(cal, total, picked, raw, cards, i);
		printTotal(cal, total, picked);
		cal++;
		i++;
	}
	printTotal(cal, total, picked);

	cal = 1;// for first player 

	while (cal < 8) //loop for all player and call for card 
	{
		raw = 4;
		while (total[cal] < 21)
		{
			command(cal, raw, total, win);
			printTotal(cal, total, picked);
			add = cal * 8 + 5;
			gotoxy(add, raw);
			cout << "Hit?";
			cin >> ch;
			cout << endl;
			if (ch == 'Y' || ch == 'y')
			{
				callone(cal, raw, cards, i, picked);
				sum(cal, total, picked, raw, cards, i);
				printTotal(cal, total, picked);
				i++;
				raw++;
			}
			else
			{
				break;
			}
			command(cal, raw, total, win);
		}
		cal++;
		command(cal, raw, total, win);
	}
	cal = 0;
	raw = 3;
	while (total[0] < 18)
	{
		command(cal, raw, total, win);
		callone(cal, raw, cards, i, picked);
		sum(cal, total, picked, raw, cards, i);
		printTotal(cal, total, picked);
		raw++;
		i++;
	}

	winner(cal, win, total, raw);


	gotoxy(0, 23);
	cout << "Do you want to play again? Y/y for yes or N/n for No? ";
	cin >> ch;
	if (ch == 'Y' || ch == 'y')
	{
		system("cls");
		main();
	}
	else
	{

		return 0;
	}
}
char FindPicture(int card)
{
	char picture = ' ';
	switch (card % 13)
	{
	case 0: picture = 'A';
		break;
	case 10: picture = 'J';
		break;
	case 11: picture = 'Q';
		break;
	case 12: picture = 'K';
		break;
	default: picture = ' ';
	}

	return picture;

}


void callCard(int cal, int raw, int i, int cards[], int pcards[])
{

	int  suit, value;
	char picture;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (cal == 0 && raw == 3)
	{

		



	}
	else
	{
		// gotoxy(column,row)
		gotoxy(cal * 8, raw);

		suit = cards[i] / 13;


		picture = FindPicture(cards[i]);

		//create a function to return a value calculated in this if else statement.

		if (cards[i] % 13 < 10)
			value = (cards[i] % 13 + 1);
		else
		{
			value = 10;
		}

		if ((suit + 3) == 3 || (suit + 3) == 4)
		{
			SetConsoleTextAttribute(hConsole, 60);
			if (picture == ' ')
				cout << setw(7) << value << char(suit + 3) << endl;
			else
				cout << setw(7) << picture << char(suit + 3) << endl;
			SetConsoleTextAttribute(hConsole, 48);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 48);
			if (picture == ' ')
				cout << setw(7) << value << char(suit + 3) << endl;
			else
				cout << setw(7) << picture << char(suit + 3) << endl;
		}

		Beep(300, 500);

		if (picture == 'A')
			value = 1;
		pcards[cal] += value;

	}

	return;
}

int cardsShiv(int cards[])
{
	int cnewCard[52] = { 0 }, card, i = 0;
	while (i < 52)
	{

		card = rand() % 52;
		while (cnewCard[card])
		{
			card = rand() % 52;

		}
		cards[i] = card;
		cnewCard[card] = true;
		i++;
	}
	return cards[card];
}
int callone(int i, int j, int cards[], int card, int pcards[])
{

	int  suit, value, add = 0;
	char picture;
	add = i * 8 + 5;
	// gotoxy(column,row)
	gotoxy(add, j);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	suit = cards[card] / 13;




	picture = FindPicture(cards[card]);

	//create a function to return a value calculated in this if else statement.

	if (cards[card] % 13 < 10)
		value = cards[card] % 13 + 1;
	else
		value = 10;

	if ((suit + 3) == 3 || (suit + 3) == 4)
	{
		SetConsoleTextAttribute(hConsole, 60);
		if (picture == ' ')
			cout << setw(2) << value << char(suit + 3) << "    " << endl;
		else
			cout << setw(2) << picture << char(suit + 3) << "     " << endl;
		SetConsoleTextAttribute(hConsole, 48);
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 48);
		if (picture == ' ')
			cout << setw(2) << value << char(suit + 3) << "    " << endl;
		else
			cout << setw(2) << picture << char(suit + 3) << "     " << endl;
	}

	Beep(300, 500);

	if (picture == 'A')
		value = 1;
	pcards[i] = value;

	return pcards[i];
}

int sum(int cal, int total[], int amount[], int raw, int cards[], int card)
{

	if (cal < 8)
		total[cal] += amount[cal];


	return total[cal];
}
void printTotal(int cal, int total[], int amount[])
{




	gotoxy(0, 22);
	cout << "Total: " << setw(1) << total[0] << setw(8) << total[1]
		<< setw(8) << total[2] << setw(8) << total[3] << setw(8) << total[4] << setw(8) <<
		total[5] << setw(8) << total[6] << setw(8) << total[7];
	return;
}
int command(int cal, int raw, int total[], int win[])
{
	int add = 0;
	add = cal * 8 + 5;
	gotoxy(0, 17);

	if (cal != 0)
		cout << "Player " << cal << " turn";
	else
		cout << "                                           ";

	if (total[cal] == 21)
	{
		win[cal] = cal;
	}
	else if (total[cal] > 21 && cal != 0)
	{
		gotoxy(add, raw);
		cout << "BUST!" << endl;
		Beep(330, 100);
		Beep(330, 100);
		Beep(330, 100);
		Beep(262, 100);
	}
	return win[cal];
}
void winner(int cal, int win[], int total[], int raw)
{
	int i = 16;
	cal = 1;
	int w = 17;
	gotoxy(i, w);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (cal<8) // while loop
	{

		if ((total[cal] < 22) && (total[0] > 21))
		{
			if (cal == 4 || cal == 7)
			{
				w++;
				gotoxy(i, w);
			}
			SetConsoleTextAttribute(hConsole, 60);
			cout << "Player " << cal << " WIN,   ";
			SetConsoleTextAttribute(hConsole, 48);
			Beep(880, 500);
			Beep(587.33, 1000);
			Beep(698.16, 500);
			Beep(880, 500);
			Beep(587.33, 1000);
			Beep(698.46, 500);
			Beep(880, 250);
			Beep(1046.50, 250);
			Beep(987.77, 500);
			Beep(783.99, 500);
			Beep(698.46, 250);
			Beep(783.99, 250);
			Beep(880, 500);
			Beep(587.33, 500);
			Beep(523.25, 250);
			Beep(659.26, 250);
			Beep(587.33, 750);

		}
		else
		{
			if ((total[0]<21) && (total[cal] <22) && (total[0]<total[cal]))
			{
				if (cal == 4 || cal == 7)
				{
					w++;
					gotoxy(i, w);
				}

				SetConsoleTextAttribute(hConsole, 60);
				cout << "Player " << cal << " WIN,   ";
				SetConsoleTextAttribute(hConsole, 48);
				Beep(880, 500);
				Beep(587.33, 1000);
				Beep(698.16, 500);
				Beep(880, 500);
				Beep(587.33, 1000);
				Beep(698.46, 500);
				Beep(880, 250);
				Beep(1046.50, 250);
				Beep(987.77, 500);
				Beep(783.99, 500);
				Beep(698.46, 250);
				Beep(783.99, 250);
				Beep(880, 500);
				Beep(587.33, 500);
				Beep(523.25, 250);
				Beep(659.26, 250);
				Beep(587.33, 750);

			}
			else if (total[0] == total[cal] && total[cal]<21)
			{
				if (cal == 4 || cal == 7)
				{
					w++;
					gotoxy(i, w);
				}

				cout << "Player " << cal << " Tie,   ";

			}
			else
			{
				if (cal == 4 || cal == 7)
				{
					w++;
					gotoxy(i, w);
				}
				cout << "Player " << cal << " Loss,  ";

			}// end else
		} // end else 

		cal++;
	}// end while loop

}