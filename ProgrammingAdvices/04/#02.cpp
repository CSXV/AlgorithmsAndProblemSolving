#include <iostream>
#include <ostream>
using namespace std;
//Print basic name.
string ReadName() {
  string Name;
  cout << "Enter your name: ";
  getline(cin, Name);
  return Name;
}

void PrintName(string Name) { cout << "Your Name is: " << Name << endl; }

int main() {
  PrintName(ReadName());
  return 0;
}
