#include <iostream>


using namespace std;


class dateType
{
public:
	void setDate(int, int, int);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void printDate() const;
	dateType(int = 1, int = 1, int = 1900);

private:
	int dMonth;
	int dDay;
	int dYear;
};

int main()
{
	dateType date;
	int day, month, year;
	char ch = 'y';
	cout << "Please enter the date: Month, Day, Year" << endl;
	cin >> month >> day >> year;
		
		date.setDate(month, day, year);
		date.printDate();
		cout << endl;
		cout << "Would you like to try again? ";
		cin >> ch;
		if (ch == 'y')
		{
			cout << endl;
			main();
		}
	system("pause");
	return 0;
}

void dateType::setDate(int month, int day, int year)
{
	
	bool d = true, m = true, y = true, leap = false;
	int i = 0, w = 0;
	
	while (y)
	{
		if (year> 0)
		{
			dYear = year;

			y = false;
		}
		else
		{
			y = true;
			break;
		}

	}// end while for year
	


	i = year % 400; 
	w = year % 100;

	if (w != 0 && year % 4 == 0)
	{
		leap = ture;
	}
	else
	{
		if (i == 0)
			leap = ture;
	}


	while (m)
	{
		if (month < 13 && month >0)
		{
			dMonth = month;
			m = false;

		}
		else
		{
			m = true;
			break;
		}
	}// end while for month 
	
	while (d)
	{

		
		if (day < 32 && day >0)
		{
			if (month == 2)
			{
				if (leap && day <30)
				{
					dDay = day;
					d = false;
				}
				else if (!leap && day < 29)
				{
					dDay = day;
					d = false;
				}
				else
				{
					d = true;
					break;
				}
			}// for feb
			else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			{
				if (day < 32)
				{
					dDay = day;
						d = false;
				}
				else
				{
					d = true;
					break;
				}
			}// end day for jan, mar, july, aug, oct, dec
			else
			{
				if (day < 30)
				{
					dDay = day;
					d = false;
				}
				else
				{
					d = true;
					break;
				}
			}// end else 

			
		}
		else
		{
			d = true;
			break;
		}
	}// end while for day
	
	if (d || m || y)
	{
		dDay = 1;
		dMonth = 1;
		dYear = 2018;
	}
	
	return;
}

int dateType::getDay() const
{
	return dDay;
}

int dateType::getMonth() const
{
	return dMonth;
}

int dateType::getYear() const
{
	return dYear;
}

void dateType::printDate() const
{
	cout << dMonth << "-" << dDay << "-" << dYear;
}

// constructor with parameters
dateType::dateType(int month, int day, int year)
{
	setDate(month, day, year);

}
