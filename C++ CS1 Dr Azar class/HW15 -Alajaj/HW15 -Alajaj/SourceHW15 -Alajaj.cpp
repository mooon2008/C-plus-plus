#include <iostream>

using namespace std;

void dectohex(int num, int base);
void dectoOct(int num, int base);


int main()
{
	int decimalnum, base, base2;
	char ch = 'y';
	while (ch == 'y')
	{
		base = 16;
		base2 = 8;

		cout << endl<<"Enter number in decimal: ";
		cin >> decimalnum;
		cout << endl;

		cout << "Decimal " << decimalnum << " = ";
		dectohex(decimalnum, base);
		cout << " Hexadecimal"<<". and = ";
		dectoOct(decimalnum, base2);
		cout << " Octal";

		cout << endl << "Do you want to try again? y for yes : ";
		cin >> ch;
	}
	system("pause");
	return 0;
}

void dectohex(int num, int base)
{
	char ch[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	int hex = num% base;
	if (num > 0)
	{
		dectohex(num / base, base);
		if (hex < 10)
		{
			cout << hex;
		}
		else
		{
			switch (hex)
			{
			case 10:
			{
					   cout << ch[0];
					   break;
			}
			case 11:
			{
					   cout << ch[1];
					   break;
			}
			case 12:
			{
					   cout << ch[2];
					   break;
			}
			case 13:
			{
					   cout << ch[3];
					   break;
			}
			case 14:
			{
					   cout << ch[4];
					   break;
			}
			case 15:
			{
					   cout << ch[5];
					   break;
			}
			case 16:
			{
					   cout << ch[6];
					   break;
			}
			default: cout << hex;
			}
		}

	}
	return;
}

void dectoOct(int num, int base)
{
	int oct = num% base;
	if (num > 0)
	{
		dectoOct(num / base, base);
		cout << oct;
	}
	return;
}