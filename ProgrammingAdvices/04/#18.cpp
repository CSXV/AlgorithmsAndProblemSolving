#include <cmath>
#include <iostream>
using namespace std;

// Calculate the area of the circle by radious.

float readnumber() {
  float a;

  cout << "Calculating the area of the circle.\n\n";

  cout << "Please enter the radious: ";
  cin >> a;

  return a;
}

float calculatearea(float a) {
  const float PI = 3.1415926535589;

  float area = PI * pow(a, 2);

  return area;
}

void printresults(float area) {
  cout << "The area of the circle: " << area << endl;
}

int main() {
  printresults(calculatearea(readnumber()));

  return 0;
}
