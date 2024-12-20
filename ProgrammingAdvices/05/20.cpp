#include <cstdlib>
#include <iostream>
using namespace std;
// Print a random: Small letter, Capital letter, special character and a digit.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}
enum enRandomGen {
  SmallLetter = 1,
  CapitalLetter = 2,
  SpecialChar = 3,
  Digit = 4
};

int RandomNumber(int from, int to) {
  int randNum = rand() % (to - from + 1) + from;
  return randNum;
}

char RandomChar(enRandomGen chartype) {
  switch (chartype) {
  case enRandomGen::SmallLetter: {
    return char(RandomNumber(97, 122));
    break;
  }
  case enRandomGen::CapitalLetter: {
    return char(RandomNumber(65, 90));
    break;
  }
  case enRandomGen::SpecialChar: {
    return char(RandomNumber(33, 47));
    break;
  }
  case enRandomGen::Digit: {
    return RandomNumber(48, 57);
    break;
  }
  }
}

int main() {
  srand((unsigned)time(NULL));
  cout << RandomChar(enRandomGen::SmallLetter) << endl;
  cout << RandomChar(enRandomGen::CapitalLetter) << endl;
  cout << RandomChar(enRandomGen::SpecialChar) << endl;
  cout << RandomChar(enRandomGen::Digit) << endl;
  signature();
  return 0;
}
