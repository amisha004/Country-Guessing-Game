#include <iostream>
#include <cstdlib>
#include <ctime>			//string representing local time
#include <string>
using namespace std;

const int tries=5;

int fill(char, string, string&);

int main()
{
	string name;
	char letter;
	int guess=0;
	string word;
	string words[]=
	{
		"india",
		"canada",
		"germany",
		"colombia",
		"france",
		"belgium",
		"argentina",
		"bangladesh",
		"china",
		"afghanistan",
		"america"
	};
	
	srand(time(NULL));
	int n=rand()%10;
	word=words[n];
	
	string unknown (word.length(), '*');
	
	cout << "\n\nWelcome to guess game" << endl;
	cout << "Guess a county name" << endl;

	cout << "\n\nINSTRUCTIONS:" << endl;
	cout << "Each letter is represented by *" << endl;
	cout << "You have to type only one letter in one try" << endl;
	cout << "You have " << tries << " tries to try and guess the word";
	
	while (guess< tries)
	{
		cout << "\n\n\n" << unknown << endl;
		cout << "Guess a letter: " ;
		cin >> letter;
		
		if (fill(letter, word, unknown) == 0)
		{
			cout << "\n\nOpps! That letter isn't in there." << endl;
			guess++;
		}
		else
		{
			cout << "\n\nYou found a letter!" << endl;
		}
		cout << "You have " << tries-guess << " guess left!" << endl;
		
		if (word==unknown)
		{
			cout << word << endl;
			cout << "Yeahhhh! You got it!!!";
			break;
		}
	}
	
	if (guess==tries)
	{
		cout << "\n\nSorry! You lose..." << endl;
		cout << "The word was: " << word << endl;
	}
	cin.ignore(); 		//clear one or more character from input buffer
	cin.get();
	return 0;
}

int fill(char guess, string secretWord, string &guessword)
{
	int i;
	int matches=0;
	int len= secretWord.length();
	for (i=0; i<len; i++)
	{
		if (guess == guessword[i])
		{
			return 0;
		}
		if (guess == secretWord[i])
		{
			guessword[i] =guess;
			matches++;
		}
	}
	return matches;
}
