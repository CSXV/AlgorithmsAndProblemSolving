#include <cmath>
#include <iostream>
using namespace std;

// Calculate the area of the circle through dimeter.

float readnumbers() {
  float a;

  cout << "Calculating the area of the circle through the diameter.\n\n";

  cout << "Please enter the diameter: ";
  cin >> a;

  return a;
}

float calculatearea(float a) {
  const float PI = 3.141492653589793238;
  float area = (PI * pow(a, 2)) / 4;

  return area;
}

void printresults(float area) {
  cout << "The area of the circle is: " << area << endl;
}

int main() {
  printresults(calculatearea(readnumbers()));

  return 0;
}
