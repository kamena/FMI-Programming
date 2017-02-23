/*
 * Напишете функция, която приема символен низ и проверява дали думата "izdislav" се
 * съдържа в него. Ако се съдържа, нека бъде върнат индекса на първия символ, където се
 * среща, а в противен случай да се връща -1.
*/

#include <iostream>
#include <cstring>

using namespace std;
int i = 0;
int where_is_izdislav(char* str, char* izdislav) {
	int strsize = strlen(str);
	int sizeIzdislav = strlen(izdislav) - 1;
	int pos = 0;
	cout << "sizeIzdislav= " << sizeIzdislav << endl;
	for ( int i = 0; i < strsize; i++ ) {
		if (pos == sizeIzdislav) {
			return i - pos;
		} 
		if( str[i] == izdislav[pos] ) {
			cout << "str[" << i << "]= " << str[i] << endl;
			cout << "izdislav[" << pos << "]= " << izdislav[pos] << endl;
			pos++;
		} else {
			pos	= 0;
		}
	}
	return -1;
}

int main() {
	char str[1024] = "Coming closer once you tell me ... izdislav ?(x2) You are the only thing I see when I close my eyes... Is this love? (x3) You are the reason that I breathe.. Is this love? (x2)";

	char izdislav[225] = "izdislav";
	
	cout << "Found on: " << where_is_izdislav(str, izdislav);

	cout << endl;
	return 0;
}