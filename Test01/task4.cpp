/**
 * Task 4:
 *
 * Напишете функция reduce, която приема кат опараметри масив от числа и число. 
 * Функцията трябва да раздели всеки един член на масива с числото подадено като 
 * параметър. Функцията трябва да принтира променения масив.
**/

#include <iostream>

using namespace std;

const int SIZE = 5;

int getArray( int arr[] ) {

	cout << "Write your array: ";
	for (int i = 0; i < SIZE; i++) {
		cin >> arr[i];
	}

	return arr[SIZE];
}

int printReadyArray( int arr[], int my_num ) {
	for (int i = 0; i < SIZE; i++) {
		cout << arr[i] /  my_num << " ";
	}
}

int main() {
	int arr[SIZE], my_num;

	getArray(arr);

	cout << "Write your number: ";
	cin >> my_num;

	printReadyArray(arr, my_num);	

	cout << endl;

	return 0;
}