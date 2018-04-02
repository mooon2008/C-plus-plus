#include <iostream>
#include <time.h>
#include <iomanip>
#include <Windows.h>
using namespace std;

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

char FindPicture(int);

int main()
{
	int cards[52], picked[52] = { 0 }, i, j, card, suit, value, total[8] = { 0 };
	char picture;

	srand(time(NULL));
	cout << char(3) << char(4) << char(5) << char(6) << endl;
	i = 0;
	while (i < 52)
	{
		card = rand() % 52;

		//while (picked[card] == 1)
		while (picked[card])
			card = rand() % 52;

		cards[i] = card;

		picked[card] = 1;

		i++;
	}

	i = 0;
	while (i < 52)
	{
		suit = cards[i] / 13;

		picture = FindPicture(cards[i]);
		/*switch (cards[i] % 13)
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
		}*/

		if (cards[i] % 13 < 10)
			value = cards[i] % 13 + 1;
		else
			value = 10;

		if (picture == ' ')
			cout << setw(2) << cards[i] << setw(3) << value << char(suit + 3) << endl;
		else
			cout << setw(2) << cards[i] << setw(3) << picture << char(suit + 3) << endl;
		i++;
	}

	cout << endl;

	//right justify the output
	cout << right;

	system("cls");

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
	while (i < 8)
	{
		// gotoxy(column,row)
		gotoxy(i * 8, 2);
		suit = cards[i] / 13;
		/*switch (cards[i] % 13)
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
		}*/

		picture = FindPicture(cards[i]);

		//create a function to return a value calculated in this if else statement.
		if (cards[i] % 13 < 10)
			value = cards[i] % 13 + 1;
		else
			value = 10;

		if (picture == ' ')
			cout << setw(7) << value << char(suit + 3) << endl;
		else
			cout << setw(7) << picture << char(suit + 3) << endl;
		i++;
	}

	system("pause");
	return 0;
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