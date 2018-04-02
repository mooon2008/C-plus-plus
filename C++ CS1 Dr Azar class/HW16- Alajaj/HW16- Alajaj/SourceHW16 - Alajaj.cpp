#include <iostream>
#include <vector>

// HW16 -Alajaj.cpp 
//
/* Abdullah Alajaj
4/25/2017
"I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else's work as my own."
*/

using namespace std;

int insertionSearch(vector<int> &, int); // prototype sorting function 

int main()// start main
{
	vector<int> intlist; // declear variables 
	vector<int>sortlist;
	int temp;
	// asgin input in vector intlist
	intlist.push_back(50);  //1
	intlist.push_back(22);  //2
	intlist.push_back(11);  //3
	intlist.push_back(60);  //4
	intlist.push_back(1);  //5
	intlist.push_back(100);  //6
	intlist.push_back(10);  //7
	intlist.push_back(70);  //8
	intlist.push_back(5);  //9
	intlist.push_back(65);  //10

	cout << "elements before sotring: ";
	
	for (auto p : intlist) // to print out vector values before sorting
		cout << p << " ";

	cout << endl << endl;
	sortlist = intlist;
	for (int w = 0; w < intlist.size(); w++) // loop to insertion sorting all values
	{

		insertionSearch(sortlist, w);


	}

	cout << "elements after sotring:  ";  // to print out vector values after sorting
	for (auto j : sortlist)
		cout << j << " ";

	cout << endl;
	system("pause");
		return 0;
}

int insertionSearch(vector<int> &sortlist, int w)// dclear insertion sorting function to sort cards 
{
	int temp;
	
	while (w>0 && sortlist[w] < sortlist[w - 1])
	{
		temp = sortlist[w];
		sortlist[w] = sortlist[w - 1];
		sortlist[w - 1] = temp;
		w--;

	}
	return sortlist[w];

}// end sorting function 




