#include <iostream>
#include <ostream>
using namespace std;
//Read three numbers and then print the average of them.
void readnumbers(int &num1, int &num2, int &num3) {
  cout << "Please enter the first number: ";
  cin >> num1;
  cout << "Please enter the second number: ";
  cin >> num2;
  cout << "Please enter the third number: ";
  cin >> num3;
}

int sumofnumbers(int &num1, int &num2, int &num3) {
  return (num1 + num2 + num3);
}

float averageofnumbers(int &num1, int &num2, int &num3) {
  return (float)sumofnumbers(num1, num2, num3) / 3;
}

void printnumbers(float average) {
  cout << "\nThe average of all numbers is: " << average << endl;
}

int main() {
  int num1, num2, num3;
  readnumbers(num1, num2, num3);
  printnumbers(averageofnumbers(num1, num2, num3));

  return 0;
}
