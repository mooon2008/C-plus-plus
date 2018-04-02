// HW12 -Alajaj.cpp 
//
/* Abdullah Alajaj
4/22/2017
"I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else's work as my own."
*/
#include<iostream> 
#include<iomanip>




void Data(char&, int&, char&, char**);

void printout(char**, int, char);
void printfirstonly(char**, int, char);
void printBusinessOnly(char**, int, char);
void printEcononly(char**, int, char);

using namespace std;

int main()// start main  

{

	char ch, tType, column; // decleare variables ch : to ask about continue the program or no. tType: ticket type 

	int row, i, j;

	char **Seats;
	Seats = new char*[13];
	for (i = 0; i < 13; i++)
	Seats[i] = new char [6];

	for (i = 0; i < 13; i++) // assin * for all availabe seats 
	for (j = 0; j < 6; j++)
		Seats[i][j] = '*';

	cout << "This program assigns seats for a plane.\n" << "Do you want to start now? Y/y for yes, N/n for no." << endl;

	cin >> ch;
	ch = static_cast<char>(toupper(ch)); // make sure entry change to capital letter

	while (ch == 'Y') // while loop if answer yes stay on the program if no exit 

	{



		Data(tType, row, column, Seats); // call functions 

		printout(Seats, row, column);


		cout << "This program assigns seats for a plane" << endl;
		cout << "Do you want to start now ? Y / y for yes, N / n for no" << endl;

		cin >> ch;

		ch = static_cast<char>(toupper(ch)); // make sure entry change to capital letter

		if (ch == 'N') // if answer no enter if statment 
		{

			system("pause");

			return 0;
		}
	}// end while  

	system("PAUSE");
	delete Seats;
	return 0;

}



void Data(char& tType, int& row, char& column, char **Seats)// define function Data when user want to select a seat

{
	int compare, compare2, j = 0, j1 = 0;

	cout << "This airplane has 13 rows, with  6 seats on each row. " << endl;



	cout << "Enter ticket type," << endl;// ask user to select a class

	cout << "F for first class," << endl;

	cout << "B for business class," << endl;

	cout << "E for economy class:" << endl;

	cin >> tType;

	tType = static_cast<char>(toupper(tType)); // make sure answer is copital letter

	while (tType != 'F' && tType != 'B' && tType != 'E')// if ticket tpe enter worng loop user till getting correct answer

	{

		cout << "Enter ticket type," << endl;

		cout << "F for first class," << endl;

		cout << "B for business class," << endl;

		cout << "E for economy class:" << endl;

		cin >> tType;

		tType = static_cast<char>(toupper(tType)); // make sure it is capital letter

	}

	cout << "Enter the row number you want to set in: " << endl; //enter row you want to seat in

	switch (tType) // determent class selected and inform user about the class location 

	{

	case 'F':
		printfirstonly(Seats, row, column);
		cout << "Row 1 and 2 are first class." << endl;
		compare = 3;
		compare2 = 0;
		cin >> row;
		while (row > 2 || row < 1)
		{
			cin.clear();
			cin.ignore();
			cout << "Row 1 and 2 are first class" << endl;
			cin >> row;
		}
		break;

	case 'B':
		printBusinessOnly(Seats, row, column);
		cout << "row 3 throuh 7 are business class." << endl;
		compare = 8;
		compare2 = 2;
		cin >> row;

		while (row > 7 || row < 3)
		{
			cin.clear();
			cin.ignore();
			cout << "row 3 throuh 7 are business class." << endl;
			cin >> row;
		}
		break;

	case 'E':
		printEcononly(Seats, row, column);
		cout << "row 8 through 13 are economy class." << endl;
		compare = 14;
		compare2 = 7;
		cin >> row;

		while (row > 13 || row < 8)
		{
			cin.clear();
			cin.ignore();
			cout << "row 8 through 13 are economy class." << endl;
			cin >> row;
		}

		break;

	}// end switch




	while (row <compare2 || row > compare)
	{
		if (tType == 'F')
		{
			cin.clear();
			cin.ignore();
			cout << "Row 1 and 2 are first class" << endl;
			cin >> row;
		}
		else if (tType == 'B')
		{
			cin.clear();
			cin.ignore();
			cout << "row 3 throuh 7 are business class." << endl;
			cin >> row;
		}
		else if (tType == 'E')
		{
			cin.clear();
			cin.ignore();
			cout << "row 8 through 13 are economy class." << endl;
			cin >> row;
		}

	}


	cout << "Enter the seat number (from A to F). " << endl; // allow user to enter column 

	cin >> column;

	column = static_cast<char>(toupper(column)); // make sure it is capital letter

	j = static_cast<int>(column)-65;


	while (Seats[row - 1][j] == 'X')
	{

		cin.ignore();
		cin.clear();
		cout << "Sorry this seat already taken, please select an available seat" << endl;
		cout << "Enter the seat number (from A to F). " << endl; // allow user to enter column 

		cin >> column;
		column = static_cast<char>(toupper(column)); // make sure it is capital letter
		j = static_cast<int>(column)-65;

	}

	while (column <65 || column > 70)
	{

		if (column == 65 || column == 66 || column == 67 || column == 68 || column == 69 || column == 70)
		{
		}
		else

		{
			cin.clear();
			cin.ignore();
			cout << "Enter the seat number (from A to F). " << endl; // allow user to enter column 

			cin >> column;

			column = static_cast<char>(toupper(column)); // make sure it is capital letter
		}
	}
}



void printout(char **Seats, int row, char column)// define printout function to show info in file and screen 

{


	int i, j; // dcleare  variables
	char x = 'X';




	cout << "* mean the seat is available; " << endl;

	cout << "X mean the seat is taken. " << endl;
	// show hadears labels 
	cout << setw(12) << "A" << setw(6) << "B" << setw(6) << "C" << setw(6) << "D" << setw(6) << "E" << setw(6) << "F" << endl;


	for (i = 0; i < 13; i++) // for loop to print labels for rows 

	{

		cout << left << setw(3) << "Row " << setw(2) << i + 1;
		for (j = 0; j < 6; j++) // loop for column marks

		{

			if (i == row - 1 && j == static_cast<int>(column)-65) // when finding the seat selected by user print X

			{
				cout << right << setw(6) << x;
				Seats[i][j] = x;
			}// end if 
			else // other wise print *
			{

				cout << right << setw(6) << Seats[i][j];
			}// end else


		}// end loop for columns

		cout << endl;
	}//end for loop for rows 


}//end function

void printfirstonly(char **Seats, int row, char column)
{
	int i, j; // dcleare  variables
	char x = 'X';




	cout << "* mean the seat is available; " << endl;

	cout << "X mean the seat is taken. " << endl;
	// show hadears labels 
	cout << setw(12) << "A" << setw(6) << "B" << setw(6) << "C" << setw(6) << "D" << setw(6) << "E" << setw(6) << "F" << endl;


	for (i = 0; i < 2; i++) // for loop to print labels for rows 

	{

		cout << left << setw(3) << "Row " << setw(2) << i + 1;
		for (j = 0; j < 6; j++) // loop for column marks

		{

			if (i == row - 1 && j == static_cast<int>(column)-65) // when finding the seat selected by user print X

			{
				cout << right << setw(6) << x;
				Seats[i][j] = x;
			}// end if 
			else // other wise print *
			{

				cout << right << setw(6) << Seats[i][j];
			}// end else


		}// end loop for columns

		cout << endl;
	}//end for loop for rows 
}
void printBusinessOnly(char **Seats, int row, char column)
{
	int i, j; // dcleare  variables
	char x = 'X';




	cout << "* mean the seat is available; " << endl;

	cout << "X mean the seat is taken. " << endl;
	// show hadears labels 
	cout << setw(12) << "A" << setw(6) << "B" << setw(6) << "C" << setw(6) << "D" << setw(6) << "E" << setw(6) << "F" << endl;


	for (i = 2; i < 7; i++) // for loop to print labels for rows 

	{

		cout << left << setw(3) << "Row " << setw(2) << i + 1;
		for (j = 0; j < 6; j++) // loop for column marks

		{

			if (i == row - 1 && j == static_cast<int>(column)-65) // when finding the seat selected by user print X

			{
				cout << right << setw(6) << x;
				Seats[i][j] = x;
			}// end if 
			else // other wise print *
			{

				cout << right << setw(6) << Seats[i][j];
			}// end else


		}// end loop for columns

		cout << endl;
	}//end for loop for rows 
}
void printEcononly(char **Seats, int row, char column)
{
	int i, j; // dcleare  variables
	char x = 'X';




	cout << "* mean the seat is available; " << endl;

	cout << "X mean the seat is taken. " << endl;
	// show hadears labels 
	cout << setw(12) << "A" << setw(6) << "B" << setw(6) << "C" << setw(6) << "D" << setw(6) << "E" << setw(6) << "F" << endl;


	for (i = 7; i < 13; i++) // for loop to print labels for rows 

	{

		cout << left << setw(3) << "Row " << setw(2) << i + 1;
		for (j = 0; j < 6; j++) // loop for column marks

		{

			if (i == row - 1 && j == static_cast<int>(column)-65) // when finding the seat selected by user print X

			{
				cout << right << setw(6) << x;
				Seats[i][j] = x;
			}// end if 
			else // other wise print *
			{

				cout << right << setw(6) << Seats[i][j];
			}// end else


		}// end loop for columns

		cout << endl;
	}//end for loop for rows 
}