#include <iostream>
#include <ostream>
using namespace std;
//Check if have driving license, have recommendation, and a valid age.
struct StInfo {
  int Age;
  bool DrLi;
  bool Rec;
};

StInfo ReadInfo() {
  StInfo Driver;
  cout << "Please enter you age: ";
  cin >> Driver.Age;
  cout << "Do you have a driving license?\n(0) No, (1) Yes: ";
  cin >> Driver.DrLi;
  cout << "Do you Have Recommendation?\n(0) No, (1) Yes: ";
  cin >> Driver.Rec;

  return Driver;
}

bool CheckDr(StInfo Driver) {
  if (Driver.Rec) {
    return true;
  } else {
    return (Driver.Age > 21 && Driver.DrLi == 1);
  }
}

void PrintResult(StInfo Driver) {
  if (CheckDr(Driver))
    cout << "\n******************\n* You are Hired :)\n******************\n";
  else
    cout << "\n******************\n* You are Rejected :(\n******************\n";
}

int main() {
  PrintResult(ReadInfo());
  return 0;
}
