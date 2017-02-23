/*
 * Задача 1
 * а) Да се напише функция, която проверява дали дадено цяло число е точен куб.
 * б) Да се напише функция, която по дадена квадратна целочислена матрица с 4 реда и 4
 * стълба връща масив, съдържащ всички числа от матрицата, които се намират под
 * главния диагонал и са точни кубове.
*/

#include <iostream>

using namespace std;

int checkNum(int num) {
	int changedNum = num, check, first = 0, count = 0;

	while(changedNum > 1) {
		for(int i = 2; i <= num; i++) {

			if (changedNum % i == 0) {
				if(first == 0) {
					check = i;
				}
				if(i != check) {
					if(count % 3 != 0) {
						return 0;
					} else {
						count=0;
					}
					
				} else {
					count++;
				}
				changedNum/=i;
				first = 1;
				break;
			}

		}
	}
	if(count % 3 == 0) {
		return 1;
	} 
	return 0;
	
}

int matirxNum(int arr[4][4], int NumsToReturn[6]) {
	int pos = 0, numToCheck;
	for(int i = 1; i < 4; i++) {
		for (int j = 0; j < i; j++) {
			numToCheck = arr[i][j];

			if(checkNum(numToCheck) == 1) {
				NumsToReturn[pos] = arr[i][j];
				pos++;
			}
		}
	}
	if (pos == 0) {
		return 0;
	}
	return pos;
	
}

int main() {
	int n;
	cout << "Your num: ";
	cin >> n;
	if (checkNum(n) == 1) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	int arr[4][4];
	cout << "arr[4][4]: " << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << "arr[" << i <<"][" << j << "]: ";
			cin >> arr[i][j];
		}
	}
	int newArr[6]; 
	int count = matirxNum(arr, newArr);

	for (int i = 0; i < count; i++) {
		cout << newArr[i] << " ";
	}

	cout << endl;
	return 0;
}