#include <iostream>
#include <ostream>
using namespace std;

// Calculate the area of triangle.

void readnumbers(float &a, float &b) {
  cout << "Calculating the area of triangle.\n\n";

  cout << "Please enter the base: ";
  cin >> a;

  cout << "Please enter the heigth: ";
  cin >> b;
}

float calculatearea(float &a, float &b) { return (a / 2) * b; }

void printresults(float area) {
  cout << "\nThe area of the triangle is: " << area << endl;
}

int main() {
  float a, b;

  readnumbers(a, b);
  printresults(calculatearea(a, b));

  return 0;
}
