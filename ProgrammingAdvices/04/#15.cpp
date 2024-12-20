#include <iostream>
using namespace std;
// Calculate the area of rectangle.

void readnumbers(float &a, float &b) {
  cout << "Calculating the area of an rectangle.\n\n";
  cout << "Please enter the lenght: ";
  cin >> a;
  cout << "Please enter the width: ";
  cin >> b;
}

float calculatearea(float &a, float &b) { return a * b; }

void printresults(float area) {
  cout << "\nThe area of rectangle is: " << area;
}

int main() {
  float a, b;
  readnumbers(a, b);
  printresults(calculatearea(a, b));
  return 0;
}
