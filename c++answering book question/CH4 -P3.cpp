// CH4 -P3.cpp : Defines the entry point for the console application.
//
/*Abdullah S. Alajaj
02/05/2017
CS1514 Homework 3 ch4-p3
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()  //start main function
{
	int number; // declare variable
	cout << "Enter a number between 0 and 35):";
	cin >> number;
	if (number <= 9) // if the number 9 or less show the number as output
	{
		cout << " The output is " << number << endl;
	}
	else if (number >= 10 && number <= 35) // if the number between 10 and 35 show a letter where 10 is A and 35 is Z 
	{
		
		switch (number) // I used switch function just to follow the book ortherwise using static_cast<char>(number + 55) will be the easy way to have the same result and shorter
		{
		case 10: // if entry 10
			{
			cout << " The output is " << 'A' << endl;
			break;
			}
		case 11: // if entry 11
		{
			cout << " The output is " << 'B' << endl;
			break;
		}		
		case 12: // if entry 12
		{
			cout << " The output is " << 'C' << endl;
			break;
		}		
		case 13: // if entry 13
		{
			cout << " The output is " << 'D' << endl;
			break;
		}		
		case 14: // if entry 14
		{
			cout << " The output is " << 'E' << endl;
			break;
		}		
		case 15: // if entry 15
		{
			cout << " The output is " << 'F' << endl;
			break;
		}		
		case 16: // if entry 16
		{
			cout << " The output is " << 'G' << endl;
			break;
		}		
		case 17: // if entry 17
		{
			cout << " The output is " << 'H' << endl;
			break;
		}		
		case 18: // if entry 18
		{
			cout << " The output is " << 'I' << endl;
			break;
		}		
		case 19: // if entry 19
		{
			cout << " The output is " << 'J' << endl;
			break;
		}		
		case 20: // if entry 20
		{
			cout << " The output is " << 'K' << endl;
			break;
		}		
		case 21: // if entry 21
		{
			cout << " The output is " << 'L' << endl;
			break;
		}		
		case 22: // if entry 22
		{
			cout << " The output is " << 'M' << endl;
			break;
		}		
		case 23: // if entry 23
		{
			cout << " The output is " << 'N' << endl;
			break;
		}		
		case 24: // if entry 24
		{
			cout << " The output is " << 'O' << endl;
			break;
		}		
		case 25: // if entry 25
		{
			cout << " The output is " << 'P' << endl;
			break;
		}		
		case 26: // if entry 26
		{
			cout << " The output is " << 'Q' << endl;
			break;
		}		
		case 27: // if entry 27
		{
			cout << " The output is " << 'R' << endl;
			break;
		}		
		case 28: // if entry 28
		{
			cout << " The output is " << 'S' << endl;
			break;
		}		
		case 29: // if entry 29
		{
			cout << " The output is " << 'T' << endl;
			break;
		}		
		case 30: // if entry 30
		{
			cout << " The output is " << 'U' << endl;
			break;
		}		
		case 31: // if entry 31
		{
			cout << " The output is " << 'V' << endl;
			break;
		}		
		case 32: // if entry 32
		{
			cout << " The output is " << 'W' << endl;
			break;
		}		
		case 33: // if entry 33
		{
			cout << " The output is " << 'X' << endl;
			break;
		}		
		case 34: // if entry 34
		{
			cout << " The output is " << 'Y' << endl;
			break;
		}		
		case 35: // if entry 35
		{
			cout << " The output is " << 'Z'<<endl;
			break;
		}
		
		default:
			break;
		}
	}
	else // if entry larger then 35. it is invalid
	{
		cout << "Invalid input." << endl;
		system("PAUSE");
	}
    return 0;
} //end of main 

