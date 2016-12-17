/**
 * Task 2:
 *
 * Да се напише функция, която приема като аргумент указател към масив и размера на масива и го обръща. 
 * Например, а = {1,2,3,4,5} -> reverse(a,5) -> a : 5,4,3,2,1. 
**/

#include <iostream>

using namespace std;

const int SIZE = 5;

void reverse(int *arr, int size) {
	for(int i = 0; i <= size/2; i++) {
		int temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
	}

	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	cout << "Write array with " << SIZE << " numers:\n";
	int arr[SIZE];
	for(int i = 0; i < SIZE; i++) {
		cin >> arr[i];
	}

	reverse(arr, SIZE);

	cout << endl;

	return 0;
}