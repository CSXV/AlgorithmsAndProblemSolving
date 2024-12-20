#include <iostream>
#include <vector>
using namespace std;
// Read an number, then add it to vector, do this until the user stops, then
// print all vector elements.

void signature() {
  cout << "\n\n*************" << "\nNEVER SETTLE." << "\n*************" << endl;
}

int readnumber(string message) {
  int N;
  cout << message;
  cin >> N;
  return N;
}

void fillvector(vector<int> &vNumbers) {
  char q = 'y';
  while (q == 'Y' || q == 'Y') {
    int n = readnumber("Please enter an number: ");
    vNumbers.push_back(n);
    cout << "Do you want to add more numbers? (y/n): ";
    cin >> q;
  }
}

void Printvector(vector<int> &vNumbers) {
  cout << "\nNumbers in vector: ";
  for (int Number : vNumbers) {
    cout << Number << " ";
  }
}

int main() {
  vector<int> vNumbers;
  fillvector(vNumbers);
  Printvector(vNumbers);

  signature();
  return 0;
}
