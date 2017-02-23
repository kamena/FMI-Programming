/**
 * Task 3:
 *
 * Напишете функция, която извежда на конзолата матрица по следния начин:
 * 1 5 9  13
 * 2 6 10 14
 * 3 7 11 15
 * 4 8 12 16
**/

#include <iostream>

using namespace std;

int size = 0;

int printReadyArray( int size ) {

	const int contst_size = size;

	int arr[contst_size][contst_size];

	long int number = 1;
	for (int j = 0; j < contst_size; j++) {
		for (int i = 0; i < contst_size; i++) {
			arr[i][j] = number++;
		}
	}

	for (int i = 0; i < contst_size; i++) {
		for (int j = 0; j < contst_size; j++) {
			cout << arr[i][j] << " \t";
		}
		cout << endl;
	}
}

int main() {
	cout << "What is the size of your array? ";
	cin >> size;

	printReadyArray(size);	

	cout << endl;

	return 0;
}