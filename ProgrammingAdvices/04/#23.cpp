#include <cmath>
#include <iostream>
#include <ostream>
using namespace std;
//Calculate the area of the circle described around an arbitrary triangle.
void readnumbers(float &a, float &b, float &c) {
  cout << "Calculating the area of the circle described around an arbitrary "
          "triangle.\n\n";
  cout << "Please enter A: ";
  cin >> a;
  cout << "Please enter B: ";
  cin >> b;
  cout << "Please enter C: ";
  cin >> c;
}

float calculatearea(float a, float b, float c) {
  const float PI = 3.141592653589793238;
  float p = (a + b + c) / 2;
  float t = (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
  float area = PI * pow(t, 2);
  return area;
}

void printresults(float area) {
  cout << "The area of the circle is: " << area << endl;
}

int main() {
  float a, b, c;
  readnumbers(a, b, c);
  printresults(calculatearea(a, b, c));
  return 0;
}
