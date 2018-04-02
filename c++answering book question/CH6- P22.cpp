// CH6- P22.cpp : Defines the entry point for the console application.
//
/*
Abdullah S. Alajaj
Homework 4- P22
02/17/2017

*/
#include "stdafx.h"
#include <iostream>

using namespace std;

// This is the begining of the function which will take the name of EntredValue
void counting(long long EntredValue)
{
	int x, even = 0, odd = 0, zero = 0; //declare three variables for even, odd and zero

	while (EntredValue > 0) //while loop will run till EntredValue bigger then zero
	{
		x = EntredValue % 10;
		EntredValue = EntredValue / 10;

		if (x == 0) //increment zero when condition pass
		{
			zero++;
		}

		else if (x % 2 == 0) //increment even value when condition pass
		{
			even++;
		}

		else //increment value of odd

		{
			odd++;
		}

	}// End of while statment
	cout << "Even Digits count: " << even << endl; //printing even value
	cout << "Odd Digits count: " << odd << endl; //printing odd value
	cout << "Zero Digits count: " << zero << endl; //printing zero value
}//End of EntredValue function 

	int main()
	{

		long EntredValue;
		cout << "Enter Interger" << endl;
			cin >> EntredValue;
			
			counting(EntredValue);
			system("pause");
			return 0;

	}
		
	


	