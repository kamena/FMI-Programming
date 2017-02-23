/**
 * Task 5:
 * 
 * Write a program which takes an integer from the user.
 * 
 *  If the number is between 1 and 3, print to the console that same number multiplied by 10.
 *  If the number is between 4 and 6, print to the console that same number multiplied by 100.
 *  If the number is between 7 and 9, print to the console that same number multiplied by 1000.
 *  If the number is less than or equal to 0 or more than or equal to 10, then print to the screen "Invalid input."
 * 
**/

#include <iostream>

using namespace std;

int main() {
	cout << "Write an integer:\n";

	int number;
	cin >> number;
	
	switch (number){
		case 1 ... 3 : cout << number * 10; break;
		case 4 ... 6 : cout << number * 100; break;
		case 7 ... 9 : cout << number * 1000; break;
		default:
			cout << "Invalid input.";
			break;
 	}

 	cout << endl;

	return 0;
}