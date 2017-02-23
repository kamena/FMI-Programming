#include <iostream>
#include <math.h>
using namespace std;

int main() {

  int operation;
  double x;

  cout << "x = ";
  cin >> x;

  cout << "Operation(1,2,3,4): ";
  cin >> operation;

  switch(operation) {
      case 1 : cout << x - 5;
                    break;
      case 2 : cout << sin(x);;
                    break;
      case 3 : cout << cos(x);
                    break;
      case 4 : cout << exp(x);
                    break;
      default:     cout << "Sorry! The operation is not valid.";
                   break;
  }

  cout << endl;

  return 0;
}