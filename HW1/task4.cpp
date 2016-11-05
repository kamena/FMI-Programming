/**
 * Task 4:
 * 
 * Write a program which takes two numbers from the user. 
 * Create a third variable which takes the value of the bigger one of the two numbers that you just inputted. 
 * If the result number is a negative number, then make it positive by multiplying it by (-1). 
 * Finally, print the result to the screen.
**/

#include <iostream>

using namespace std;

int main() {
	cout << "Write 2 integers:\n";

	int number1;
	int number2;
	cin >> number1 >> number2;
	int bigger_num = (( number1 > number2 ) ? number1 : number2);

	cout << "The result is: " << ( ( bigger_num < 0 ) ? ( bigger_num * (-1) ) : bigger_num ) << endl;

	return 0;
}