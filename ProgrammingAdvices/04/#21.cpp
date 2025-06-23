#include <cmath>
#include <iostream>
using namespace std;

// Calculate the area of the circle along the circumference.

float readnumber() {
  float a;

  cout << "Calculating the area of the circle along the circumference.\n\n";

  cout << "Please enter the circumference: ";
  cin >> a;

  return a;
}

float calculatearea(float a) {
  const float PI = 3.141592653589793238;
  float area = pow(a, 2) / (4 * PI);

  return area;
}

void printresults(float area) {
  cout << "The area of the circle is: " << area << endl;
}

int main() {
  printresults(calculatearea(readnumber()));

  return 0;
}
