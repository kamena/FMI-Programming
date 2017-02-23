// Задача 3
// Да се напише рекурсивна функция, която проверява дали четните цифри на дадено
// естествено число образуват строго нарастваща редица (напр. 73524187 - четните цифри
// са 2, 4 и 8, другите не ни интересуват).
// Нерекурсивни решения на задача 3 не се приемат.

#include <iostream>

using namespace std;

int checkArr(int num, int lastDel) {
	int n = num;
	if(n != 0) {
		if ((n % 10) % 2 == 0) {
			if (lastDel < n % 10 && lastDel != -1) {
				return 0;
			}
			lastDel = n % 10;
		}
		n = n / 10;
		return checkArr(n, lastDel);
	} else {
		if(lastDel != -1) {
			return 1;
		} else {
			return 0;
		}
		
	}
	
}

int main() {
	long int num;
	cout << "Enter num: ";
	cin >> num;
	
	if (checkArr(num, -1) == 0) {
		cout << "No";
	} else {
		cout << "Yes";
	}

	cout << endl;
	return 0;
}