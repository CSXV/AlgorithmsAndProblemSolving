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
  do {
    cout << message;
    cin >> N;
  } while (N < 0);
  return N;
}

enum enCharType {
  SamallLetter = 1,
  CapitalLetter = 2,
  SpecialCharacter = 3,
  Digit = 4
};

int RandomNumber(int from, int to) {
  int Random = rand() % (to - from + 1) + from;
  return Random;
}

char GetRandomCharacter(enCharType CharType) {
  switch (CharType) {
  case enCharType::SamallLetter: {
    return char(RandomNumber(97, 122));
    break;
  }
  case enCharType::CapitalLetter: {
    return char(RandomNumber(65, 90));
    break;
  }
  case enCharType::SpecialCharacter: {
    return char(RandomNumber(33, 47));
    break;
  }
  case enCharType::Digit: {
    return char(RandomNumber(48, 57));
    break;
  }
  }
}

string GenerateWord(enCharType CharType, short Length) {
  string Word;
  for (int i = 1; i <= Length; i++) {
    Word = Word + GetRandomCharacter(CharType);
  }
  return Word;
}

string GenerateKey() {
  string Key = "";
  Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
  Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
  Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
  Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
  return Key;
}

void GenerateKeys(short NumberOfKeys) {
  for (int i = 1; i <= NumberOfKeys; i++) {
    cout << "Key [" << i << "] : ";
    cout << GenerateKey() << endl;
  }
}

int main() {
  srand((unsigned)time(NULL));
  GenerateKeys(ReadNumber("Pleaes enter how many keys to generate: "));
  signature();
  return 0;
}
