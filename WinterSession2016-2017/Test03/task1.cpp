/*
 * Задача 1
 * Напишете функция, която проверява дали едно число е степен на двойката.
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
					if(count % 2 != 0) {
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
	if(count % 2 == 0) {
		return 1;
	} 
	return 0;
	
}

int main() {
	int n;
	cout << "Your num: ";
	cin >> n;
	if (checkNum(n) == 1) {
		cout << "Yes";
	} else {
		cout << "No";
	}

	cout << endl;
	return 0;
}