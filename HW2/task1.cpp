/**
 * Task 1:
 *
 * Да се напише функция, която приема като аргумент две цели числа и разменя стойностите им.
**/

#include <iostream>

using namespace std;

void swap(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;

	cout << *num1 << " " << *num2;
}

int main() {
	cout << "Write 2 numbers:\n";
	int num1, num2;
	cin >> num1 >> num2;

	swap(&num1, &num2);

	cout << endl;

	return 0;
}