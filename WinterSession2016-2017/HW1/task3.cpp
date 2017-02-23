/**
 * Task 3:
 * 
 * Write a program which takes two integers from the user. 
 * If the sum of the two is an even number, then print to the screen the sum multiplied by 2. 
 * If the sum of the two is an odd number, then print to the screen the sum divided by 2.
**/

#include <iostream>

using namespace std;

int main() {
	cout << "Write 2 integers:\n";

	int number1;
	int number2;
	cin >> number1 >> number2;
	int sum = number1 + number2;

	cout << "The result is: " << (( sum%2 == 0 ) ? sum * 2 : (float)sum/2) << endl;

	return 0;
}