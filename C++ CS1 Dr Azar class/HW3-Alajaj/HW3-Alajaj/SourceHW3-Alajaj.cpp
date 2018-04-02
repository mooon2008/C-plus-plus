// HW3- Page 183 -Alajaj.cpp 
//
/* Abdullah Alajaj
3/7/2017
"I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else's work as my own."
*/

#include <iostream>
#include<fstream> // to open files 
#include <string> // string for first and last names
#include <iomanip> // to add decimal 



using namespace std;
int main() // start main 
{
	// open files 
	ifstream Input;
	ofstream Output;
	// declare var
	string lastName, FirstName;
	float Salary, Percent_pay, UpdatedSalary;
	int count=0;

	// open file name whih is given
	Input.open("CH3_Ex6Data.txt");
	Output.open("Ch3_Ex6Output.txt");
	// if input file did not open
	if (Input.fail())
	{
		cout << "Input file failed to open" << endl;
		system("pause");
		exit(1);
	}
	// if output file did not open
	if (Output.fail())
	{
		cout << "Output file failed to open" << endl;
		system("pause");
		exit(1);
	}
	// to go through all data 
	while (count < 3)
	{
		// 2 dicemial places
		cout << setprecision(2) << fixed;
		Output << setprecision(2) << fixed;

		if (count = 1)
		{
			// take info from input file 
			Input >> lastName >> FirstName >> Salary >> Percent_pay;
			// calc new salary
			UpdatedSalary = Salary + (0.01 * Percent_pay * Salary);
			// print data to console 
			cout << FirstName << " " << lastName << setw(10) << UpdatedSalary << endl;
			// print data to output file 
			Output << FirstName << " " << lastName << setw(10) << UpdatedSalary << endl;
		}

		if (count = 2)
		{
			// take info from input file 
			Input >> lastName >> FirstName >> Salary >> Percent_pay;
			// calc new salary
			UpdatedSalary = Salary + (0.01 * Percent_pay * Salary);
			// print data to console 
			cout << FirstName << " " << lastName << setw(11) << UpdatedSalary << endl;
			// print data to output file 
			Output << FirstName << " " << lastName << setw(11) << UpdatedSalary << endl;
		}
		
		if (count = 3)
		{
			// take info from input file 
			Input >> lastName >> FirstName >> Salary >> Percent_pay;
			// calc new salary
			UpdatedSalary = Salary + (0.01 * Percent_pay * Salary);
			// print data to console 
			cout << FirstName << " " << lastName << setw(13) << UpdatedSalary << endl;
			// print data to output file 
			Output << FirstName << " " << lastName << setw(13) << UpdatedSalary << endl;
		}
		count++;
	
	}


	system("pause");
	return 0;
} // end main