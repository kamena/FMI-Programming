/* Homework 2
 * by
 * Kamena Dacheva, 71672
 *
 * Decrypting enctrypted text files.
 *
 * AABC -> AABC
 * А\\BC -> A\BC
 * R2(AB)3(Z) -> RABABZZZ
 * R2(A\2B)3(Z) -> RA2BA2BZZZ
 * AB12(X)2(B3(A)) -> ABXXXXXXXXXXXXBAAABAAA
 * 
 * OS used: Linux
 */

#include <iostream>
#include "Stack.cpp"
#include "Decrypt.h"

using namespace std;

int main(int argc, char** argv) {
	if(argc != 3) {
		cerr << "You should enter two file names as arguments";
		return 0;
	}

	Decrypt file(argv[1], argv[2]);
	
	return 0;
}