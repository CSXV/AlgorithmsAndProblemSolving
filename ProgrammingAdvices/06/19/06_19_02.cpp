#include <iostream>
using namespace std;
// Print An number to the power of another on, using recursion loop.

void signature() {
  cout << "\n*************" << "\nNEVER SETTLE." << "\n*************" << endl;
}

int MyPower(int Base, int Power) {
  if (Power == 0) {
    return 1;
  } else {
    return (Base * MyPower(Base, Power - 1));
  }
}

int main() {
  cout << MyPower(1, 4) << endl;

  signature();
  return 0;
}
