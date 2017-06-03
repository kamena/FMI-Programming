#include <iostream>
#include <cstring>
using namespace std;

#include "String.cpp"

int main(int argc, char* argv[]) {
     String str1(argv[1]), str2(argv[2]);

     cout << "string 1: <" << str1 << ">" << endl;
     cout << "string 2: <" << str2 << ">" << endl;

     cout << "string 1 length: " << str1.size() << endl;
     cout << "string 2 length: " << str2.size() << endl;

     if (str1 > str2) cout << "<" << str1 << "> is greater than <" << str2 << ">" << endl;
     else cout << "<" << str2 << "> is greater than <" << str1 << ">" << endl;

     cout << "string 1: <" << str1 << ">" << endl;
     cout << "string 2: <" << str2 << ">" << endl;

     cout << "concatenation1: <" << str1 + str2 << ">" << endl;

     cout << "concatenation2: <" << str2 + str1 << ">" << endl;

     cout << "string 1: <" << str1 << ">" << endl;
     cout << "string 2: <" << str2 << ">" << endl;

     str2 += str1;
     cout << "concatenation3: <" << str2 << ">" << endl;
     cout << "concatenation3 length: " << str2.size() << endl;

     cin >> str1;
     cout << str1 << endl;
     
     return 0;
}