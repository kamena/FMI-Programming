/**
 * Task 5:
 *
 * Да се напише ф-ция, която приема като аргумент символен низ и премахва от него всички малки гласни букви. 
 * Приемаме, че низъв завършва с терминираща нула ('\0').

 * a, e, i, o, u 
 **/

#include <iostream>
#include <string.h> // strlen()
#include <algorithm> // for remove()

using namespace std;

const int COLUMNS = 4;

void removeVowels(string &text) {

	char chars[] = "aeiou";

	for (unsigned int i = 0; i < strlen(chars); ++i) {
		text.erase( remove( text.begin(), text.end(), chars[i] ), text.end() );
	}

	cout << text << endl;
}

int main() {
	string sentence = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin ultrices.";

	cout << sentence << endl;

	removeVowels(sentence);

	cout << endl;

	return 0;
}