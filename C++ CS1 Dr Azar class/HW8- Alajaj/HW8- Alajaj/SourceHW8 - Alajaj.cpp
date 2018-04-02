// HW7- Page 407 -Alajaj.cpp 
//
/* Abdullah Alajaj
3/12/2017
"I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else's work as my own."
*/
#include<iostream>
#include<cctype>
#include<iomanip>
#include<fstream>



void Data(char& tType, int& row, char& column);

void printout(char form[13][6], int row, char column);

using namespace std;

int main()

{

	char ch, tType, column;

	int row;

	char form[13][6];



	cout << "This program assigns seats for a plane.\n" << "Do you want to start now? Y/y for yes, N/n for no." << endl;

	cin >> ch;



	ch = static_cast<char>(toupper(ch));

	while (ch == 'Y')

	{



		Data(tType, row, column);

		printout(form, row, column);


		cout << "This program assigns seats for a plane.\n" << "Do you want to start now? Y/y for yes, N/n for no." << endl;

		cin >> ch;

		ch = static_cast<char>(toupper(ch));

		if (ch == 'N')

			return 0;

	}// end while  

	system("PAUSE");

	return 0;

}



void Data(char& tType, int& row, char& column)

{



	cout << "The airplane has 13 rows, with  6 seats in each row. " << endl;



	cout << "Enter ticket type," << endl;

	cout << "F for first class," << endl;

	cout << "B for business class," << endl;

	cout << "E for economy class:" << endl;

	cin >> tType;

	tType = static_cast<char>(toupper(tType));

	while (tType != 'F' && tType != 'B' && tType != 'E')

	{

		cout << "Enter ticket type," << endl;

		cout << "F for first class," << endl;

		cout << "B for business class," << endl;

		cout << "E for economy class:" << endl;

		cin >> tType;

		tType = static_cast<char>(toupper(tType));

	}

	switch (tType)

	{

	case 'F':

		cout << "Row 1 and 2 are first class,\n";

		break;

	case 'B':

		cout << "row 3 throuh 7 are business class,\n";

		break;

	case 'E':

		cout << "row 8 through 13 are economy class." << endl;

		break;

	}// end switch



	cout << "Enter the row number you want to sit: " << endl;

	cin >> row;



	cout << "Enter the seat number (from A to F). " << endl;

	cin >> column;

	column = static_cast<char>(toupper(column));

}



void printout(char form[13][6], int row, char column)

{
	{
		ifstream IN;
		ofstream OUT;

		OUT.open("output.txt");

		int i, j;
		char x = 'X';


		cout << "* mean the seat is available; " << endl;

		cout << "X mean the seat is occupied. " << endl;

		cout << setw(12) << "A" << setw(6) << "B" << setw(6) << "C" << setw(6) << "D" << setw(6) << "E" << setw(6) << "F" << endl;
		OUT << setw(12) << "A" << setw(6) << "B" << setw(6) << "C" << setw(6) << "D" << setw(6) << "E" << setw(6) << "F" << endl;


		for (i = 0; i < 13; i++)

		{

			cout << left << setw(3) << "Row " << setw(2) << i + 1;
			OUT << left << setw(3) << "Row " << setw(2) << i + 1;
			for (j = 0; j < 6; j++)

			{

				if (i == row - 1 && j == static_cast<int>(column)-65)

				{
					cout << right << setw(6) << x;
					OUT << right << setw(6) << x;
				}
				else
				{

					cout << right << setw(6) << "*";
					OUT << right << setw(6) << "*";
				}


			}

			cout << endl;
			OUT << endl;
		}

	}

}