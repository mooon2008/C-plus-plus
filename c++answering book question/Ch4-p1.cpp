
/*Abdullah S. Alajaj
02/05/2017
CS1514 Homework 3 ch4-p1
*/
#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int num; //declare variable

	cout << " A program to say if the number you give positive, nggative or zero" << endl;
	cin >> num;

	if (num > 0) // check if positive 
		cout << num << "  is positive number" << endl;
	else if (num< 0) // check if nrgative
		cout << num << "  is negative number" << endl;
	else  //etherwise it is zero
		cout <<" Number is zero" << endl;
	return 0;
}// end main

