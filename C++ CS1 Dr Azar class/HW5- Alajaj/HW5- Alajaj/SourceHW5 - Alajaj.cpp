// HW4- Page 183 -Alajaj.cpp 
//
/* Abdullah Alajaj
3/8/2017
"I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else's work as my own."
*/

#include <iostream>


using namespace std;
int main()
{
	int townA, townB, count =0;  // variables 
	float rateA, rateB, rateA_dec, rateB_dec; // variables 
	// explain the program and ask about pop  for A
	cout << "This program will show number of years needed for town A to have larger population than town B"<< endl;
	cout << endl << "Please enter town A population: " << endl; // town A population 
	cin >> townA;
	
	if (cin.fail()) // if value entered unvalid enter the loop
		count = 1;

	while (count >0) // start of while loop to make sure we have correct entry 
	{
		if (cin.fail()) // if fail to enter correct input for pop A clear and allow user to enter it again
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Please enter numbers only for town A population: " << endl;
			cin >> townA;
			count++;
		}
		else // if there is no fail entry exit the loop
		{
			count = 0;
		}
	}// end while for population twon A

	cout << "Please enter town A growth rate in integer: (ex: for 4% enter 4) " << endl;  // town A rate 
	cin >> rateA;
	if (cin.fail())
		count = 1;
	rateA_dec = rateA * 0.01; // change entry to percentage 

	while (count >0) // start of while loop
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Please enter town A growth rate in integer: (ex: for 4% enter 4) " << endl;  // town A rate 
			cin >> rateA;
			rateA_dec = rateA * 0.01;
			count++;
		}
		else
		{
			count = 0;
		}
	}//  end while for rate A
	
	cout << "Please enter town B population: " << endl; // town B population 
	cin >> townB;
	if (cin.fail())
		count = 1;

	while (count >0) // start while loop for pop B
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Please enter numbers only for town B population: " << endl;
			cin >> townB;
			count++;
		}
		else
		{
			count = 0;
		}
	}// end while for population B

	cout << "Please enter town B growth rate in integer: (ex: for 4% enter 4) " << endl;  // town B rate 
	cin >> rateB;
		count = 1; // to enter  the loop to check for failar or if rate B less than rate A
	rateB_dec = rateB * 0.01;

	while (count >0)  // start while loop for rate B and check if it is < rate A
	{
		if (cin.fail())
		{
				cin.clear();
				cin.ignore(200, '\n');
				cout << "Please enter town B growth rate in integer: (ex: for 4% enter 4) " << endl;  // town A rate 
				cin >> rateB;
				rateB_dec = rateB * 0.01;
				count++;
			
		}
		else // stop counting for wrong entry 
		{
			count = 0;
		}
		if (rateA <= rateB) // start if rate A < rate B allow user to renter input for rate B
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Please enter town B growth rate in integer: (make sure it is less then the rate for town A) " << endl;  // town A rate 
			cin >> rateB;
			rateB_dec = rateB * 0.01;
			count++; // loop back to check if the entry less or not
		}
		else // exit the loop 
		{
			count = 0;
		}
	}//  end while for rate B


	while (townA < townB) // loop to calc how many years it need for the pop A to become larger then pop B
	{
		townA = townA *(1 + rateA_dec);
		townB = townB *(1 + rateB_dec);
		count++;
	}

	//show result  
	cout << "it will take " << count <<" years for town A to become larger then twon B"<<endl;
	cout << "town A population in " <<count<< " years is "<< townA << endl;
	cout << "town B population in " << count << " years is " << townB << endl;
	system("pause");
	return 0;
}