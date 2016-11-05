/**
 * Task 2:
 * 
 * You are given 3 integers. Your task is to display +, - or 0 depending on the result of the product of the three numbers. 
 * If the product is a positive number - print +, if it's a negative number - print -, if the product is 0 - print 0. 
 * Solve the task without actually calculating the product of the three integers.
**/

#include <iostream>

using namespace std;

int main() {
	cout << "Write 3 integers:\n";
	int count;
	int number;
	int result = 1;

	for (count = 0; count < 3; count++) {
		cin >> number;
		
		if ( number < 0 ) {
			result *= -1;
		} else if ( number == 0 ) {
			result = 0;
		}
	}
	if ( result != 0 ) {
		cout << "The symbol is: " << ((result > 0) ? "+" : "-") << endl;
	} else {
		cout << "The symbol is: 0\n";
	}

	return 0;
}