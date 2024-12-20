#include <cstdlib>
#include <iostream>
using namespace std;
// Read an number, then print arrays of windows registry Keys of it.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

int ReadPNumber(string message) {
  int N;
  do {
    cout << message;
    cin >> N;
  } while (N <= 0);
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

void ArrayOfKeys(int NumberOfKeys, string arr[100]) {
  for (int i = 0; i < NumberOfKeys; i++) {
    arr[i] = GenerateKey();
  }
}

void PrintArray(string arr[100], int arrLength) {
  cout << "\nArray 01 elements: ";
  for (int i = 0; i < arrLength; i++) {
    cout << "\nArray [" << i << "] : " << arr[i];
  }
}

int main() {
  srand((unsigned)time(NULL));

  string arr[100];
  int arrLength = ReadPNumber("Please enter a possitive number: ");

  ArrayOfKeys(arrLength, arr);

  PrintArray(arr, arrLength);

  signature();
  return 0;
}
