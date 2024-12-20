#include <cstdlib> // Random numbe library
#include <iostream>
using namespace std;
// Print random number three times.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

int RandomNumber(int from, int to) {
  int randNum = rand() % (to - from + 1) + from;
  return randNum;
}

int main() {
  srand((unsigned)time(NULL)); // this makes the random function start from an
                               // anumber, this line must have for once in main.

  // cout << rand() << endl; // random number function.

  cout << RandomNumber(1, 10) << endl;
  cout << RandomNumber(1, 10) << endl;
  cout << RandomNumber(1, 10) << endl;
  signature();
  return 0;
}
