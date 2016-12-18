/**
 * Task 6:
 *
 * Да се напише ф-ция, която по даден масив от цели числа (и неговия размер) 
 * и цяло число, търси(по възможност двоично) числото в масива и ако го намери, 
 * връща указател към първото му срещане, в противен случай връща NULL.
 **/

#include <iostream>

using namespace std;

int* removeN(int *arr, int size, int n) {

	int temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-1; j++) {
			temp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = temp;
		}
	}

	int left = 0, right = size-1, middle_num;

	while(left < right) {

		middle_num = (left + right) / 2;
		if ( arr[middle_num] > n ) {
			right = middle_num - 1;
		} else if( arr[middle_num] < n ) {
			left = middle_num + 1;
		} else if ( arr[middle_num] == n ) {
			return &arr[middle_num];
		}
		
	}

	return NULL;
}

int main() {
	int arr[10] = {5, 4, 10, 6, 4, 1, 8, 12, 4}; 
	int n = 4;

	cout << removeN(arr, 10, n);

	cout << endl;

	return 0;
}
