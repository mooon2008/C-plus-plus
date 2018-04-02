/*Abdullah S. Alajaj
02/05/2017
CS1514 Homework 3

Program purpose:
Write a program that prompts the user to input a positive integer. It should then output a message indicating whether the number is a prime number. (Note: an even number is prime if it is 2. An odd integer is prime if it is not divisible by any odd integer less than or equal to the square root of the number.)*/

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{// start the function main
	int number = 0; // variable to store number 

	cout << "Please enter a positive integer: ";
	cin >> number; // store entry on number variable 

	double prime = true; // dclear variable prime defulted as true 
	if (number < 2) // dclear if loop. first check if entry less then 2
		prime = false;  // if so the prime switch to false
	else if (number == 2) // second check if entry = to 2
		prime = true;  // if so prime continue true
	else if (number / 2 == 0) //if the entry divided by 2 equal to zero then false
		prime = false;
	else if (number > 2) // if the number is larger then 2
	{
		int counter = 3;
		double number_as_double = static_cast<double>(number);  // convert varibale entry number to double 
		int upper_limit = static_cast<int> (sqrt(number_as_double)); //  number^2 to to check the upper limit 

		while (counter <= upper_limit) 
		{
			if (number / counter == 0)
			{
				prime = false;
				break;
			}
			counter += 2;
		}
	}
	if (prime == true)
	{
		cout << "\nThe number " << number << " is a prime number." << endl << endl;
	}
	else
	{
		cout << "\nThe number " << number << " is NOT a prime number!" << endl << endl;
	}
	return 0;
}
