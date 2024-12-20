#include <cmath>
#include <iostream>
using namespace std;
// Calculate the rectangle area be diagonal and side.

void readnumber(float &a, float &b) {
  cout << "Calculating the area of an rectangle through diagonal and side.\n\n";
  cout << "Please enter the diagonal length: ";
  cin >> a;
  cout << "Please enter the side length: ";
  cin >> b;
}

float calculatearea(float &a, float &b) {
  return a * sqrt(pow(b, 2) - pow(a, 2));
}

void printresults(float area) {
  cout << "\nThe area of the rectangle is: " << area << endl;
}

int main() {
  float a, b;
  readnumber(a, b);
  printresults(calculatearea(a, b));
  return 0;
}
