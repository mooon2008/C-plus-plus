// ch2- P14.cpp : Defines the entry point for the console application.
/*
Abdullah S. Alajaj
Homework 2- P14
01/27/2017

*/

#include "stdafx.h"
#include "iostream"

using namespace std;

// main is the function with no parameters that value
int main()
{
	// variables

	double SizeHardDrive, ActsToHard;
	// ask user about the hard driver size
	cout << "Hard Drive Storage Capacity" << endl;

	cout << "\n Please Specify Size if Hard drive in Giga bytes" << endl;
	//allow user to enter amount
	cin >> SizeHardDrive;
	// multi hard drive size to Giga bytes
	//1GB = 1000 MB, 1MB = 1000KB. 1 KB = 1000 bytes
	double Temp = SizeHardDrive * (1000 * 1000 * 1000);
	// divide hrad drive size by actual storage
	ActsToHard = Temp / (1024 * 1024 * 1024);
	// show result 
	cout << "Actual storage capacity is " << ActsToHard << endl;

	return 0;
}

