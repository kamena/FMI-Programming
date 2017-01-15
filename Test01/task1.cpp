/**
 * Task 1:
 *
 * Да се напише функция, която приема като параметър масив от числа и извежда в конзолата преобразуаният масив. 
 * Преобразуването на масива трябва да изпълнява следните правила:
 *	-ако едно число се дели на 3, да се изведе fizz 
 *	-ако едно число се дели на 5, да се изведе buzz
 * 	-ако едно число се дели на 3 и на 5, да се изведе fizz buzz
 * Ако не изпълни нито едно от горните условия, да се изведе числото.
**/

#include <iostream>

using namespace std;

const int SIZE = 5;

int getArray( int arr[] ) {

	cout << "Write your array (size = 5): ";
	for (int i = 0; i < SIZE; i++) {
		cin >> arr[i];
	}

	return arr[SIZE];
}

int main() {
	int arr[SIZE];

	getArray(arr);

	for (int i = 0; i < SIZE; i++) {
		if ( arr[i] % 3 == 0 ) {
			cout << "fizz";
		} 
		if ( arr[i] % 5 == 0 ) {
			cout << "buzz";
		} 
		if ( arr[i] % 3 != 0  && arr[i] % 5 != 0 ) {
			cout << arr[i];
		}
		cout << endl;
	}

	return 0;
}