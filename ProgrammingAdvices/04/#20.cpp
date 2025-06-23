#include <cmath>
#include <iostream>
#include <ostream>
using namespace std;

// Calculate the area of circle inscribed in a square.

float readnumber() {
  float a;

  cout << "Calculating the area of cirlce inscribed in a square.\n\n";

  cout << "Please enter the lenght: ";
  cin >> a;

  return a;
}

float calculatearea(float a) {
  const float PI = 3.141592653589793238;
  float area = (PI * pow(a, 2)) / 4;

  return area;
}

void printresults(float area) {
  cout << "The area of the cricle is: " << area << endl;
}

int main() {
  printresults(calculatearea(readnumber()));

  return 0;
}
