#include <iostream>
using namespace std;

int main() {

  int first_num, second_num, result;
  char symbol;

  cout << "Enter <number> <operation> <number>: \n";
  cin >> first_num >> symbol >> second_num;

  switch(symbol) {
      case '+' : cout << first_num + second_num;
                    break;
      case '-' : cout << first_num - second_num;;
                    break;
      case '*' : cout << first_num * second_num;;
                    break;
      case '/' : cout << first_num / second_num;;
                    break;
      case '%': cout << first_num % second_num;;
                   break;
      default:     cout << "Sorry! The operation is not valid.";
                   break;
  }

  cout << endl;

  return 0;
}