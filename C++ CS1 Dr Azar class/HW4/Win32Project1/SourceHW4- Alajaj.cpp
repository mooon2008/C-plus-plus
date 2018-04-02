// HW4- Page 183 -Alajaj.cpp 
//
/* Abdullah Alajaj
3/8/2017
"I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else's work as my own."
*/

#include <iostream>
#include <iomanip> // to add decimal

using namespace std;
int main()

{
	int num1, num2, result;
	char oper;
	cout << "This program calacualte two numbers you enter" << endl;
	cout << "Please enter the first number" << endl;
	cin >> num1;


	if ((num1 < -9999))
	{
		cout << "The value you entered first number not valid" << endl;
		
		system("pause");
		
		cin.clear();
		cin.ignore(200, '\n');

	}
	else
	{
		cout << num1 << endl;

	}

	cout << "Please enter the operation you want to do *, / , - , +, %" << endl;
	cin >> oper;


	cout << "Please enter the second number" << endl;
	cin >> num2;

		if ((num2 < -9999))
		{
			cout << "The value you entered seconds number not valid or zero" << endl;

			system("pause");
			
			cin.clear();
			cin.ignore(200, '\n');
		}

	
		


	switch (oper)
	{
	
			case ('*') :
			{
						   result = num1 * num2;
						   cout << num1 << '*' << num2 << " = " << result << endl;

						   break;
			}
			case ('/') :
			{
						   if (num2 != 0)
						   {

							   result = num1 / num2;
							   cout << num1 << '/' << num2 << " = " << result << endl;
							   break;
						   }
						   else
						   {
							   cout << "You can not divide by 0" << endl;
							   break;
						   }
			}
			case ('+') :
			{
						   result = num1 + num2;
						   cout << num1 << '+' << num2 << " = " << result << endl;

						   break;
			}
			case ('-') :
			{
						   result = num1 - num2;
						   cout << num1 << '-' << num2 << " = " << result << endl;

						   break;
			}
			case ('%') :
			{
						   result = num1 % num2;
						   cout << num1 << '%' << num2 << " = " << result << endl;

						   break;
			}



			default: cout << "The value you entered for operartion not valid" << endl;
					 

	}

	
	
	system("pause");
	return 0;

}


