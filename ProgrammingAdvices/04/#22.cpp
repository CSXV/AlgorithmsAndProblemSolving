#include <cmath>
#include <iostream>
using namespace std;
// Calculate the area of the circle inscribed in an Isosceles triangle.

void readnumbers(float &a, float &b) {
  cout << "Calculating the area of the circle inscribed in an Isosceles "
          "triangle.\n\n";
  cout << "Please enter the base: ";
  cin >> a;
  cout << "Please enter the height: ";
  cin >> b;
}

float calculatearea(float a, float b) {
  const float PI = 3.141592653589793238;
  float area = PI * (pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b));
  return area;
}

void printresults(float area) {
  cout << "The area of the circle is: " << area << endl;
}

int main() {
  float a, b;
  readnumbers(a, b);
  printresults(calculatearea(a, b));
  return 0;
}
