// HW6- Page 183 -Alajaj.cpp 
//
/* Abdullah Alajaj
3/11/2017
"I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else's work as my own."
*/
#include <iostream>
#include <iomanip>

using namespace std;

//start main
int main()
{//dclear variable
	double riverWidth, fDistance, costwater, costland, totallineinwater, totalLineinland, totalcost = 999999999, ncost,linewater, lineland;
	double count = 0.0, count2 = 0.0, mileconut;
	// allow user to enter river width, factory distance, cost under water and above land (loop back if entry worng)
	cout << "please enter the width of the river in miles: " << endl;
	cin >> riverWidth;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(200, '\n');
		cout << "please enter only numers for the width of the river in miles: " << endl;
		cin >> riverWidth;
	}

	cout << "please enter the factory distance in miles: " << endl;
	cin >> fDistance;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(200, '\n');
		cout << "please enter only numers for the factory distance in miles: " << endl;
		cin >> fDistance;
	}

	cout << "please enter the cost of laying power line under water per foot: " << endl;
	cin >> costwater;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(200, '\n');
		cout << "please enter only numers for the cost of laying power line under water per foot: " << endl;
		cin >> costwater;
	}

	cout << "please enter the cost of laying power line over land per foot: " << endl;
	cin >> costland;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(200, '\n');
		cout << "please enter only numers for the cost of laying power line over land per foot: " << endl;
		cin >> costland;
	}


	// calc cost 


	while (count2 <= fDistance) // loop till count2 = the land distance was entered by the user
	{
		count2 = count + 0.1; // increase distance by .1 mile 
		totallineinwater = sqrt((riverWidth*riverWidth) + (count2*count2)); // calc how much wire needed aunder water when we increase dis 
		totalLineinland = fDistance - count2; // calc how much wire needed over land when we increase dis 
		ncost = totallineinwater*costwater * 5280 + (totalLineinland*costland * 5280); // calc cost dencrease while dis increase

		if (totalcost > ncost) // if new cost less then old cost enter if statment . total cost set as 99999 as starter to enter the if statment then amount will change within
		{
	
			linewater = sqrt((riverWidth*riverWidth) + (count*count));
			lineland = fDistance - count;
			totalcost = linewater*costwater * 5280 + (lineland*costland * 5280); // this will determent the lowes cost 
			mileconut = count; // this will determent distence needed for lowes cost

		}

		count = count + 0.1; // this will increase destance for total cost

	}
	double costlineinwater = (linewater*costwater * 5280);  // decleared here just to allow setw to work for cout #3

	cout << fixed << showpoint << setprecision(2); // 2 dicaimil places requiaered  

	// show user result 
	cout << "The length of the power line under water is: " << setw(13) << linewater << " miles." << endl;
	cout << "The length of the power line over land is: " << setw(15) << lineland << " miles." << endl;
	cout << "The cost of laying the power line in water is: $"<<setw(10) << costlineinwater << endl;
	cout << "The cost of laying the power line over land is: $" << lineland*costland*5280 << endl;
	cout << "total cost is: $" << setw(42) << totalcost << endl;

	system("pause");
	return 0;
}// end of main

