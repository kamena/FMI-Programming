#include <iostream>
#include <algorithm>

using namespace std;

int bulls, cows;

int generate_rand( int arr[] ) {
	
	random_shuffle(&arr[0], &arr[10]);

	return arr[10];
}

int check_for_num( int num, int rand_mum[], int num_possition ) {
	for (int i = 0; i < 4; ++i) {
		if ( num == rand_mum[i] ) {
			if ( i == num_possition ) {
				bulls++;
			} else {
				cows++;
			}
		}
	}

	return bulls, cows;
}

int main() {
	int suggested_num;
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int rand_mum[4];
	int num1, num2, num3, num4;

	srand(time(0));
	generate_rand(arr);

	cout << "What is your suggestion?\n";
	int count_tries = 0;

	while ( bulls < 4 ) {
	
		bulls = 0;
		cows = 0;

		cin >> suggested_num;

		if ( suggested_num > 9999 ) {
			cout << "Sorry! " << suggested_num << " is not valid!\n";
		} else {
			if ( !suggested_num ) { 
				cout << "Are you trying to break me? You should enter 4 digit NUMBER!!!\n"; 
				return 0; 
			}
			num1 = suggested_num / 1000;
			suggested_num %= 1000;
			num2 = suggested_num / 100;
			suggested_num %= 100;
			num3 = suggested_num / 10;
			num4 = suggested_num % 10;
			
			check_for_num(num1, arr, 0);
			check_for_num(num2, arr, 1);
			check_for_num(num3, arr, 2);
			check_for_num(num4, arr, 3);
			
			cout << "You have " << bulls << " bulls and " << cows << " cows." << endl;

			count_tries++;
		}
	}

	cout << "Congrats! You win after " << count_tries << " tries!\n";
	return 0;
}