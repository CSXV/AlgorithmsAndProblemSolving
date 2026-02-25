#include <iomanip>
#include <iostream>
using namespace std;

// Print Multiplication table from to 01 to 10.
// 2026-02-25

// -------------------------------------------------------------------------------------------------
void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

// -------------------------------------------------------------------------------------------------
struct stPips {
  string startTop = "┏";
  string endTop = "┓";

  string startBottom = "┗";
  string endBottom = "┛";

  string middle = "┃";
  string dash = "━";

  string middleTop = "┳";
  string middleBottom = "┻";

  string narrowMiddle = middle + " ";
  string wideMiddle = "  " + middle + "  ";
};

const stPips Pip;

// -------------------------------------------------------------------------------------------------
string makeIndent(short n) {
  string s = "";

  for (short i = 0; i < n; i++) {
    s += " ";
  }

  return s;
}

// -------------------------------------------------------------------------------------------------
void printDivider(short n, bool type = 0) { // 0 top, 1 bottom
  // first count will be 1
  // change it to 0 and see the differece
  short counter = 1;

  cout << ((type == 0) ? Pip.startTop : Pip.startBottom);

  for (short i = 0; i < n; i++) {
    counter++;

    if (counter == 8) {
      // count after the first is 0
      counter = 0;

      cout << ((type == 0) ? Pip.middleTop : Pip.middleBottom);
    } else
      cout << Pip.dash;
  }

  cout << ((type == 0) ? Pip.endTop : Pip.endBottom) << "\n";
}

// -------------------------------------------------------------------------------------------------
void printHeadText(string message, short indent = 4) {
  cout << "\t\t   " << Pip.startTop;

  for (short i = 0; i < message.length() + indent; i++) {
    cout << Pip.dash;
  }

  cout << Pip.endTop << "\n";

  // ----------------------------------------
  cout << "\t\t   " << Pip.middle << makeIndent(indent / 2) << message
       << makeIndent(indent / 2) << Pip.middle << "\n";

  // ----------------------------------------
  cout << "\t\t   " << Pip.startBottom;

  for (short i = 0; i < message.length() + indent; i++) {
    cout << Pip.dash;
  }

  cout << Pip.endBottom << "\n";
}

// -------------------------------------------------------------------------------------------------
void printHeadRow() {
  cout << Pip.narrowMiddle;

  for (short i = 1; i < 11; i++) {
    cout << setw(3) << i << Pip.wideMiddle;
  }

  cout << endl;
}

// -------------------------------------------------------------------------------------------------
void printRow() {
  for (short i = 1; i < 11; i++) {
    cout << Pip.narrowMiddle;

    for (short j = 1; j < 11; j++) {
      cout << setw(3) << i * j << Pip.wideMiddle;
    }

    cout << endl;
  }
}

// -------------------------------------------------------------------------------------------------
void printHeader() {
  printHeadText("Multiplication table from 00 to 10");
  printDivider(78);

  printHeadRow();
  printDivider(78, 1);
}

// -------------------------------------------------------------------------------------------------
void printTable() {
  printHeader();
  printDivider(78);

  printRow();
  printDivider(78, 1);
}

// -------------------------------------------------------------------------------------------------
int main() {
  printTable();

  signature();
  return 0;
}

// -------------------------------------------------------------------------------------------------
