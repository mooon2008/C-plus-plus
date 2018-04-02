// Lab2- Alajaj.cpp 
//
/* Abdullah Alajaj
3/14/2017
"I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else's work as my own."
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include<string>
using namespace std;

int process_NUMemployees(ifstream&, string, float, int, int);// prototypes functions
int max_pay(int, float, string, ofstream&);
int min_pay(int, float, string, ofstream&);
int average_pay(int, float, ofstream&);
void payroll();


int main() //start main function only will start to call for payroll function
{

	payroll();
	
	


	system("pause");
	return 0;
}// end main

int process_NUMemployees(ifstream& IN,string name[], float pay[], int hours[],int& count) // process employees info from input file
{
	
int	i = 0;// decleare variables
count = i;
	
	cout << setprecision(2) << fixed; // set dicemal of 2

	while (IN >> name[i] >> pay[i] >> hours[i]) // load info and count records
	{

		i++;
	}
	
	count = i;
	
	return count;
}// end of employees function

int max_pay(int count, float payrate[], string name[],ofstream& OUT)// Max pay function to find the max that was payed
{
	int max = -999999, index;
	
	for (int i = 0; i < count; i++) // max rate
	{
	if (payrate[i]> max)
	{
	max = payrate[i];
	index = i;
	}
	}// end for loop
	cout << "Maximum Pay Rate: "<< name[index] <<" @ " << payrate[index] << endl;
	OUT << "Maximum Pay Rate: " << name[index] << " @ " << payrate[index] << endl;
	return max;
}// end max_pay function 

int mix_pay(int count, float payrate[], string name[], ofstream& OUT) // Mix pay function to find the mix that was payed
{
	int min = 999999, index;

	for (int i = 0; i < count; i++) // mix rate
	{
		if (payrate[i]< min)
		{
			min = payrate[i];
			index = i;
		}
	}// end for  loop
	cout << "Minimum Pay Rate: " << name[index] << " @ " << payrate[index] << endl;
	OUT << "Minimum Pay Rate: " << name[index] << " @ " << payrate[index] << endl;
	return min;
}// end mix_pay function 

int average_pay(int count, float payrate[], ofstream& OUT)// average pay function to find average 
{
	int i;
	float total_pay = 0, average;
	for ( i = 0; i < count; i++)
	{
		total_pay += payrate[i];
	}
	
	average = total_pay / i;
	cout << "Average Pay: $" << average << endl;
	OUT << "Average Pay: $" << average << endl;
	return total_pay;
}// end of average function

void payroll()//////////////// start of payroll function
{
	ifstream IN;// dcleare variables 
	ofstream OUT;
	int hours[15], count, i;
	float payrate[15], gross[15], adjusted_gross[15];
	string name[15];
	char bonus[15];

	IN.open("Input.txt"); // open files
	OUT.open("output.txt");

	if (IN.fail()) // if files did not open let me know
	{
		cout << "Input file fail to open" << endl;
		system("pause");
		exit(1);
	}// end if
	if (OUT.fail())
	{
		cout << "Output file fail to open" << endl;
		system("pause");
		exit(1);
	}// end if

	process_NUMemployees(IN, name, payrate, hours, count); // call for emlpyees function to load data 

	if (count < 11) // if statment to find the number of records if it is more then ten exit
	{
		cout << "Number of Employees: " << count << endl;
		OUT << "Number of Employees: " << count << endl;
	}
	else
	{
		cout << " This program only allow 15 records. You have " << count << " records" << endl;
		OUT << " This program only allow 15 records. You have " << count << " records" << endl;
		system("pause");
	
	}

	max_pay(count, payrate,name,OUT);
	mix_pay(count, payrate, name,OUT);
	average_pay(count, payrate,OUT);

	cout << endl << "October 2009 Payroll:" << endl << endl;
	OUT << endl << "October 2009 Payroll:" << endl << endl;
	
	cout << setw(17) << left << "Name" << setw(9) << "Hours" << setw(7) << "Rate" << setw(8) << "Gross" << setw(8) << "Bonus" << setw(8) << "Adjusted Gross" << endl;
	OUT << setw(17) << left << "Name" << setw(9) << "Hours" << setw(7) << "Rate" << setw(8) << "Gross" << setw(8) << "Bonus" << setw(8) << "Adjusted Gross" << endl;

	i = 0;
	
	while (i<count)
	{
		bonus[i] = 'N';
		gross[i] = hours[i] * payrate[i];
		if (hours[i] <30)
		{
			adjusted_gross[i] = gross[i] - (hours[i] * .25);
		}
		else if (hours[i]>45)
		{
			bonus[i] = 'Y';
			adjusted_gross[i] = gross[i] + 50;
		}
		else
		{
			adjusted_gross[i] = gross[i];
		}
		cout << setw(17) << left<< name[i]<<right << setw(5) << hours[i] << setw(8) << payrate[i] << setw(8) << gross[i] << setw(8) << bonus[i] << setw(17) << adjusted_gross[i]<< endl;
		OUT << setw(17) << left << name[i] << right << setw(5) << hours[i] << setw(8) << payrate[i] << setw(8) << gross[i] << setw(8) << bonus[i] << setw(17) << adjusted_gross[i] << endl;

		i++;
	}

	IN.close();
	OUT.close();
}// end payroll function