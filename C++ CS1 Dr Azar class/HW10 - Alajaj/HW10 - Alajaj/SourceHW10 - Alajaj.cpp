// HW10- Page 735 -Alajaj.cpp 
//
/* Abdullah Alajaj
3/29/2017
"I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else's work as my own."
*/
#include <iostream>
#include <string>
#include<iomanip>



using namespace std;

class bankAccount
{
public:
	
	static int GeneratedAccNO;
	void open(string, string);
	
	void deposit(string);
	
	void close(string);
	void withdraw(string);
	void checkBalance(string);
	void transfer();

	bool getName(string);


	//open, close, deposit, withdraw, transfer, check balance, ;

private:
	static double rate;
	string name;
	int acctNO;
	double cBalance = -99999, Sbalance = -99999, findbalance();
	string acctype;
	
	
};

int bankAccount::GeneratedAccNO = 0;
double bankAccount::rate = 0.01;


bool check(bankAccount[], string);


void bankAccount::open(string n, string type)
{
	
	bankAccount myAccounts[10];

	bool exist = false;

	name = n;
	acctype = type;

	if (exist == check(myAccounts, name))
	{
			if (type == "Checking")

			{
				cout << n << " already have an / a " << type << " acount" << endl;
				
			}
			else if (type == "Saving")
			{
				cout << n << " already have an / a " << type << " acount" << endl;
			}
	}

	else
	{
		acctNO = ++bankAccount::GeneratedAccNO;
		if (acctype == "Saving")
		{
			Sbalance = 0;
		}
		else
		{
			cBalance = 0;
		}

		return;
	}
}
bool check(bankAccount[], string);

bool bankAccount::getName( string n)
{
	if (n == name)
	{
		return true;
	}
	else
	return false;
}



int main()
{
	bankAccount myAccounts[10];
	string na, type;
	

	  myAccounts[0].open("Joe Smith", "Checking");
	  myAccounts[0].open("Joe Smith", "Checking");
	  myAccounts[0].open("Joe Smith", "Checking");
	

	cout << bankAccount::GeneratedAccNO << endl;
	system("pause");
	return 0;
}

bool check(bankAccount myAccount[], string s)
{
	bool exist = false;
	int i;
	
	for (i = 0; i < 10; i++)
	{
		if (myAccount[i].getName(s))
		{

			exist = true;
			break;
		}
	}
	return exist;
}
void bankAccount::deposit( string accountType)
{
	if (accountType == "Checking")
	{
		if (cBalance > -1)
			cBalance += 1000; // deposit always will be 1000 since user not entering amount 

		else
			cout << "You do not have Checking account open" << endl;
	}
	else if (accountType == "Saving")
	{
		if (Sbalance > -1)
		Sbalance += 1000;

		else
			cout << "You do not have Saving account open" << endl;
	}
	
	return;
}

void bankAccount::withdraw(string accountType)
{
	if (accountType == "Checking")
	{
		if (cBalance >=1000) // withdraw always will be 1000 since user not entering amount 
			cBalance -= 1000; 

		else
			cout << "You do not have enough moeny for this transaction" << endl;
	}
	else if (accountType == "Saving")
	{
		if (Sbalance >= 1000)// withdraw always will be 1000 since user not entering amount 
			Sbalance -= 1000;

		else
			cout << "You do not have enough moeny for this transaction" << endl;
	}

	return;
}

void bankAccount::checkBalance(string AccountType)
{
	if (AccountType == "Checking")
	{
		if (cBalance >= 0)
			cout << "Your checking account balance is: " << cBalance << endl;

		else
			cout << "You do not a checking account" << endl;
	}
	else if (AccountType == "Saving")
	{
		if (Sbalance >= 0)
			cout << "Your savinging account balance is: " << Sbalance << endl;

		else
			cout << "You do not a sainging account" << endl;
	}



	return;
}

/*

int deleAccout(string name, int accountNum[2])
{
	double balance[2], double rate;


	return 0;
}





int transfer(string name, int accountNum[2])
{
	double balance[2], double rate;


	return 0;
}*/



