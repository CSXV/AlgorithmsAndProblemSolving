#include <cstdlib>
#include <iostream>
using namespace std;
// Enter an number, then print window registry key times it.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

int ReadNumber(string message) {
  int N;
  cout << message;
  cin >> N;
  return N;
}

int RandomNumber(int from, int to) {
  int Random = rand() % (to - from + 1) + from;
  return Random;
}

void RandomKey(int N) {
  for (int k = 1; k <= N; k++) {
    cout << "Key [" << k << "] : ";
    for (int j = 0; j < 4; j++) {
      for (int i = 0; i < 4; i++) {
        cout << char(RandomNumber(65, 90));
      }
      if (j < 3)
        cout << "-";
    }
    cout << endl;
  }
}
int main() {
  srand((unsigned)time(NULL));
  RandomKey(
      ReadNumber("Please enter an number to generate a random Window Key: "));
  signature();
  return 0;
}
