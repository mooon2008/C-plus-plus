// Ch2- P21.cpp : Defines the entry point for the console application.
/*
Abdullah S. Alajaj
Homework 2- P21
01/27/2017

*/

#include "stdafx.h"
#include"iostream"

using namespace std;
// start with main funcation
int main()
{
	// assgin var
	float AmountRice, NuBags;

	// Ask about amount of rice
	cout << "Enter amount of rice in each bag: " << endl;
	//allow entry to sgin to the var
	cin >> AmountRice;
	// calc number of bags required
	NuBags = (2205 / AmountRice);
	// show result 
	cout << "The required bags are: " << ceil(NuBags) << endl;

    return 0;
} // end of main

