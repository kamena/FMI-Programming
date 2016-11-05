/**
 * Task 1:
 *
 * You are given 5 real numbers and the task is to print to the screen the biggest one of them. 
 * You can use a maximum of 5 if statements in your solution.
**/

#include <iostream>

using namespace std;

int main() {
	cout << "Write 5 real numbers:\n";
	int count;
	float numbers[5];
	float biggest_num;
	float num;
	cin >> numbers[0];
	biggest_num = numbers[0];

	for (count = 1; count < 5; count++) {
		cin >> numbers[count];
		
		if ( biggest_num < numbers[count] ) {
			biggest_num = numbers[count];
		}
	}

	cout << "The biggest number is: " << biggest_num << endl;;

	return 0;
}