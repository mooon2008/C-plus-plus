// Lab1 -Alajaj.cpp 
//
/* Abdullah Alajaj
3/13/2017
"I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else's work as my own."
*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int process_employee(ifstream &, int&, int&, float&);//prototypes functions
void process_payroll();
void print_summary(ofstream &, float, float, float, float, float);

int main()// start main 
{

	
	// functions call 
	process_payroll( ); 

	system("pause");
	return 0;
}// end main 

int process_employee(ifstream &IN,int& id, int& hours, float& rate) // define to process individual employee info
{
	

	if (IN >> id >> rate >> hours)
	{
		return 1;
	}
	else
		return 0;
}
////while (process_employee(id,hours, rate)) // to read from function 
void process_payroll() // define to process patroll info and print out 
{
	ifstream IN; //input file
	ofstream OUT; //output file
	int i, Hours,Id; // decleare varibles 
	float Gross, Net, Fed, State, SocSec, Rate;
	float	TotalGross = 0, TotalNet = 0, TotalFed = 0, TotalState = 0, TotalSS = 0;
	const float FEDERAL_TAX = 0.16, STATE_TAX = 0.0542, SOC_TAX = 0.07;
	
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

	cout << "Employee Payroll" << endl;// orginaize file . have hadears and labels . (from here, some process repeated to have same output in file and screen)
	cout << setw(6) << "Employee" << setw(6) << "Hours" << setw(9) << "Rate" << setw(7) << "Gross" << setw(8) << "Net" << setw(7) << "Fed" << setw(6) << "State" << setw(7) << "SocSec" << endl;

	OUT << "Employee Payroll" << endl;
	OUT << setw(6) << "Employee" << setw(6) << "Hours" << setw(9) << "Rate" << setw(7) << "Gross" << setw(8) << "Net" << setw(7) << "Fed" << setw(6) << "State" << setw(7) << "SocSec" << endl;

	cout << setprecision(2) << fixed; // add two dicemil places 
	OUT << setprecision(2) << fixed;


	
	///while (IN >> id >> rate >> hour) // start while loop to output info as required
	while (process_employee(IN,Id,Hours, Rate))
	{		
		i= Hours;
		if (i != 40) // start if working hours not equal 40
		{
		if (i < 40)// start if working hours less then 40
		{
			Gross = (Hours * (Rate+0.15));// adding 0.15 per hour bouns to the gross
			Fed = Gross * FEDERAL_TAX; // calculate fed tax, state tax, SS tax and net. calculation can not outside of if statments BC they need to be above their cout or print out .
			State = Gross * STATE_TAX;// calculation independ on Gross which must be inside if statment  
			SocSec = Gross * SOC_TAX;
			Net = Gross - Fed - State - SocSec;

			cout << setw(8) << Id << setw(6) << Hours << '*' << setw(8) << Rate << setw(7) << Gross << setw(8) << Net << setw(7) << Fed << setw(6) << State << setw(7) << SocSec << endl;
			OUT << setw(8) << Id << setw(6) << Hours << '*' << setw(8) << Rate << setw(7) << Gross << setw(8) << Net << setw(7) << Fed << setw(6) << State << setw(7) << SocSec << endl;
		}// end if less then 40 hours
		else// if working hours more then 40
		{
			Gross = (40 *Rate) + ((Hours - 40)*1.5*Rate); // adding bouns 1.5 for every hour more then 40
			Fed = Gross * FEDERAL_TAX;
			State = Gross * STATE_TAX;
			SocSec = Gross * SOC_TAX;
			Net = Gross - Fed - State - SocSec;
			cout << setw(8) << Id << setw(6) << Hours << '$' << setw(8) << Rate << setw(7) << Gross << setw(8) << Net << setw(7) << Fed << setw(6) << State << setw(7) << SocSec << endl;
			OUT<< setw(8) << Id << setw(6) << Hours << '$' << setw(8) << Rate << setw(7) << Gross << setw(8) << Net << setw(7) << Fed << setw(6) << State << setw(7) << SocSec << endl;

		} // end else. working hours more then 40
		} // end if working hours not equal 40
		else  // if working hours equal 40
		{
			Gross = Hours * Rate;
			Fed = Gross * FEDERAL_TAX;
			State = Gross * STATE_TAX;
			SocSec = Gross * SOC_TAX;
			Net = Gross - Fed - State - SocSec;
			cout << setw(8) << Id << setw(6) << Hours << setw(9) << Rate << setw(7) << Gross << setw(8) << Net << setw(7) << Fed << setw(6) << State << setw(7) << SocSec << endl;
			OUT << setw(8) << Id << setw(6) << Hours << setw(9) << Rate << setw(7) << Gross << setw(8) << Net << setw(7) << Fed << setw(6) << State << setw(7) << SocSec << endl;

		} // end else. if working hours =40
		
		TotalGross += Gross; // get total gross, net, fed tax, state tax and SS tax.
		TotalNet += Net;
		TotalFed += Fed;
		TotalState += State;
		TotalSS += SocSec;

	}//end while loop 
	print_summary(OUT, TotalGross, TotalNet, TotalFed, TotalState, TotalSS); // call print_summary function 
	
	IN.close();// close files
	OUT.close();
}// end payroll function

void print_summary(ofstream &OUT, float TotalGross, float TotalNet, float TotalFed, float TotalState, float TotalSS) //define to print total result
{


	cout << endl << "SUMMARY - Totals for All Employees" << endl; // show hadears and labels 
	cout << setw(15) << "GrossPay" << setw(10) << "NetPay" << setw(11) << "FederalTax" << setw(10) << "StateTax" << setw(12) << "SocSecurity" << endl;
	// print out summary total under each labels 
	cout << setw(15) << TotalGross << setw(10) << TotalNet << setw(11) << TotalFed << setw(10) << TotalState << setw(12) << TotalSS << endl;

	OUT << endl << "SUMMARY - Totals for All Employees" << endl; // repeat the same info in output file 
	OUT << setw(15) << "GrossPay" << setw(10) << "NetPay" << setw(11) << "FederalTax" << setw(10) << "StateTax" << setw(12) << "SocSecurity" << endl;
	OUT << setw(15) << TotalGross << setw(10) << TotalNet << setw(11) << TotalFed << setw(10) << TotalState << setw(12) << TotalSS << endl;
}