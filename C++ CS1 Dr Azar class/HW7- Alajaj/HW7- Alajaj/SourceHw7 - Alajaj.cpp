// HW7- Page 516 -Alajaj.cpp 
//
/* Abdullah Alajaj
3/12/2017
"I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else's work as my own."
*/
#include <iostream>
#include <string>
using namespace std;

string subword(string); //prototypes functions 
int vowel(char ch);

int main()
{
	string word, newWord; // dclear varibales
	// allow user to enter a word 
	cout << "Enter a word you want to remove the vowels from: ";
	cin >> word;
	// assin the word without vlowels after porcessing subword function to newWord varible
	newWord = subword(word);
//show result to the user 
	cout << " the word without vowels: " << newWord << endl;

	system("pause");
	return 0;

} // end main 

string subword(string word) //define subword function to remove vowels and 
{
	int chPostion = 0; // char postion and get to increase by 1 postion for the loop
	char currentCh; // current char variable
	while (chPostion < word.length()) // while loop will stop if the char postion = to word length since all sring end with \n  
	{
		currentCh = word.at(chPostion); //assin each char to currentCh everytime it loop
		if (vowel(currentCh)) // if the char is a vlowel 
		{
			word =  word.substr(0, chPostion) + word.substr(chPostion + 1); // remove a vowel and shift char to left

		}
		else // or increase postion by 1
		{
			chPostion++;
		}
	}// end while 
	return word; 

}// end of subword

int vowel(char ch) // define vowel function to evaluate each charactars if it is a vowel or not 
{
	ch = toupper(ch); // change all letter to upper cases

	switch (ch) // difine if charctars is a vowel or not 
	{
	case 'A': case 'U': case 'I': case 'O': case 'E':
		return true;
			default:
		
		return false;
	} //end switch 
} // end vowels checker