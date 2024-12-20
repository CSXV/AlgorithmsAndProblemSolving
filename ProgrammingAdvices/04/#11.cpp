#include <iostream>
#include <ostream>
using namespace std;
// Calculate the average of three numbers, then print if pass or fail based
// on 50.
enum PassFail { Pass = 1, Fail = 2 };

void readnumbers(int &num1, int &num2, int &num3) {
  cout << "calculate the average of three numbers, then print if pass or fail "
          "based on 50."
       << endl;
  cout << "Please enter the first number: ";
  cin >> num1;
  cout << "Please enter the second number: ";
  cin >> num2;
  cout << "Please enter the third number: ";
  cin >> num3;
}

int sumofnumbers(int &num1, int &num2, int &num3) { return num1 + num2 + num3; }

float averageofnumbers(int &num1, int &num2, int &num3) {
  return (float)sumofnumbers(num1, num2, num3) / 3;
}

PassFail checkaverage(float average) {
  if (average >= 50)
    return PassFail::Pass;
  else
    return PassFail::Fail;
}

void printinfo(float average) {
  cout << "\nYour average is: " << average << endl;
  if (checkaverage(average) == PassFail::Pass)
    cout << "You Passed :)";
  else
    cout << "You Failed :(";
}

int main() {
  int num1, num2, num3;
  readnumbers(num1, num2, num3);
  printinfo(averageofnumbers(num1, num2, num3));
  return 0;
}
