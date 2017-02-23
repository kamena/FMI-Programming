/**
 * Task 4:
 *
 * Да се напише ф-ция, която по дадени указатели към двумерни масиви от цели числа и техните размери, 
 * записва във втория матрицата, която се получава при транспонирането на матрицата, представена от първия масив.
 **/

#include <iostream>

using namespace std;

const int COLUMNS = 4;

void transSwap(int (*arr1)[COLUMNS], int size1, int (*arr2)[COLUMNS], int size2) {
	for (int j = 0; j < size1; j++) {
		for (int i = 0; i < size1; i++) {
			arr2[i][j] = arr1[j][i];
		}
	}
	for (int i = 0; i < size2; i++) {
		for (int j = 0; j < size2; j++) {
			cout << arr2[i][j] << " \t";
		}
		cout << endl;
	}
}

int main() {
	int arr1[4][4] = { { 1, 2, 3, 4 }, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
	int arr2[4][4] = {{ 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0}};

	transSwap(arr1, 4, arr2, 4);

	cout << endl;

	return 0;
}