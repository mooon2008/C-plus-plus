// CH7- P7.cpp : Defines the entry point for the console application.
//
/*
Abdullah S. Alajaj
Homework 4- Ch7 - p7
02/12/2017

*/
#include "stdafx.h"

#include<iostream>



using namespace std;


// prototype of the functions
void menu(char&, int&, int&, int&, int&);



void addFraction(int, int, int, int, int&, int&);



void subtractFractions(char, int, int, int, int, int&, int&);



void multiplyFractions(char, int, int, int, int, int&, int&);



void divideFractions(char, int, int, int, int, int&, int&);










// start of main function 
int main()



{
	int A1 = 0;
	int A2 = 0;
	int A3 = 0;
	int B1 = 0;
	int B2 = 0;
	int B3 = 0;
	int TheResult = 0;
	
	char oper;

	char choise = 'y';



	char slash = '/';

	while (choise == 'y' || choise == 'Y')  // start of while function if user want to continue using the program
	{

		menu(oper, A1, A2, B1, B2);



		if (oper == '+')



			addFraction(A1, A2, B1, B2, A3, B3);



		else if (oper == '-')



			subtractFractions(oper, A1, A2, B1, B2, A3, B3);



		else if (oper == '*')



			multiplyFractions(oper, A1, A2, B1, B2, A3, B3);



		else if (oper == '/')



			divideFractions(oper, A1, A2, B1, B2, A3, B3);







		cout << A3 << slash << B3 << endl;

		cout << "do you want to continue using the program y/n <" << endl;
		cin >> choise;
	}





	return 0;



}



void menu(char& oper, int& A1, int& A2, int& B1, int&B2)



{



	cout << "This programm calacualte the fraction" << endl;



	cout << "select operation mathad you want to use from the list,(+ , - , * , / )" << endl;



	cin >> oper;



	while (oper != '+' && oper != '/' && oper != '*' && oper != '-')



	{



		cout << "You enter the wrong operator , select one of the following operation,(+ , - , * , / )";


		cin >> oper;



	}



	cout << "Enter the top number of the first fraction : " << endl;



	cin >> A1;



	cout << "Enter button number of the first fraction: " << endl;



	cin >> B1;



	cout << "Enter the top number of the second fraction : " << endl;



	cin >> A2;



	cout << "Enter button number of the second fraction: " << endl;



	cin >> B2;



	return;



}



void addFraction(int A1, int A2, int B1, int B2, int& A3, int& B3)



{



	cout << A1 << " " << B1 << " " << A2 << " " << B2 << endl;



	A3 = (B1*A2) + (B2*A1);



	B3 = (B1*B2);



	cout << "Answer: " << A3 << "/" << B3 << endl;


}



void subtractFractions(char operation, int A1, int A2, int B1, int B2, int& A3, int& B3)



{



	A3 = (B2*A1) - (B1*A2);



	B3 = (B1*B2);



	return;



}



void multiplyFractions(char operation, int A1, int A2, int B1, int B2, int& A3, int& B3)



{



	A3 = (A2*A1);



	B3 = (B1*B2);



	return;



}



void divideFractions(char operation, int A1, int A2, int B1, int B2, int& A3, int& B3)



{



	A3 = (B2*A1);

	B3 = (B1*A2);

	return;


}