// CH3- P3.cpp : Defines the entry point for the console application.
//
/*
Abdullah S. Alajaj
Homework 2- P14
01/27/2017

*/
#include "stdafx.h"
#include <iomanip> // to use  setprecision
#include "iostream" // to use cin and cout 
using namespace std;

// start of main 
int main()
{
	// a sgin varable  
	double WeightInKilo, WeghtInPound;
	// ask about the weght in Kg
	cout << " please enter the person weight in Kilograms" << endl;
	// allow to enter the weight 
	cin >> WeightInKilo;
	//Convert the weight to pounds 
	WeghtInPound = WeightInKilo * 2.2;
	// formats the outout to 2 decimal plases 
	cout << fixed << showpoint << setprecision(2);
	// show result in pounds 
	cout << "Weight of the person is " <<WeghtInPound<< " Pounds"<< endl;
  
	return 0;
}// end of main 

