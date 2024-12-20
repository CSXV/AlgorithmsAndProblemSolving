#include <iostream>
#include <string>
#include <vector>
using namespace std;
// read a date string, then print it with formatting.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

enum enCompare { Before = -1, Equal = 0, After = 1 };

struct stDate {
  short Day;
  short Month;
  short Year;
};

struct stPeriod {
  stDate Start;
  stDate End;
};

short ReadNumber(string message, short N, short D) {
  short S;

  do {
    cout << message;
    cin >> S;
  } while (S < N || S > D);

  return S;
}

string ReadString(string message) {
  string S;

  cout << message;
  getline(cin >> ws, S);

  return S;
}

stDate ReadFullDate() {
  stDate Date;

  Date.Day = ReadNumber("Please enter a Day  : ", 1, 31);
  Date.Month = ReadNumber("Please enter a Month: ", 1, 12);
  Date.Year = ReadNumber("Please enter a year : ", 1900, 3000);

  return Date;
}

stPeriod ReadPeroid() {
  stPeriod Period;

  cout << "Enter Start Date:\n\n";
  Period.Start = ReadFullDate();
  cout << "\nEnter End Date:\n";
  Period.End = ReadFullDate();

  return Period;
}

stDate GetSystemDate() {
  stDate Date;

  time_t TIME = time(0);
  tm *GMT = localtime(&TIME);

  Date.Year = GMT->tm_year + 1900;
  Date.Month = GMT->tm_mon + 1;
  Date.Day = GMT->tm_mday;

  return Date;
}

bool isLeapYear(short Y) {
  return ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0);
}

short ReturnDaysOfMonth(short Y, short M) {
  if (M < 1 || M > 12) {
    return 0;
  }

  int NumOfDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  return (M == 2) ? (isLeapYear(Y) ? 29 : 28) : NumOfDays[M];
}

short DayOrderInWeek(stDate Date) {
  short a, y, m;

  a = ((14 - Date.Month) / 12);
  y = Date.Year - a;
  m = Date.Month + 12 * a - 2;

  return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

short NumberOfDaysFromTheBeginningOfTheYear(short Y, short M, short D) {
  short counter = 0;

  for (short i = 1; i <= M - 1; i++) {
    counter += ReturnDaysOfMonth(Y, i);
  }

  counter += D;

  return counter;
}

bool IsLastDayInMonth(stDate Date) {
  return Date.Day == ReturnDaysOfMonth(Date.Year, Date.Month);
}

bool IsLastMonthInYear(short Month) { return Month == 12; }

stDate IncreaseDateByOneDay(stDate Date) {
  if (IsLastDayInMonth(Date)) {
    if (IsLastMonthInYear(Date.Month)) {
      Date.Month = 1;
      Date.Day = 1;
      Date.Year++;
    } else {
      Date.Day = 1;
      Date.Month++;
    }
  } else {
    Date.Day++;
  }
  return Date;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
  return (Date1.Year < Date2.Year)
             ? true
             : ((Date1.Year == Date2.Year)
                    ? (Date1.Month < Date2.Month
                           ? true
                           : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day
                                                         : false))
                    : false);
}

bool IsDate1EqualDate2(stDate Date, stDate Date2) {
  return (Date.Year == Date2.Year)
             ? ((Date.Month == Date2.Month)
                    ? ((Date.Day == Date2.Day) ? true : false)
                    : false)
             : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
  return (!IsDate1BeforeDate2(Date1, Date2) &&
          !IsDate1EqualDate2(Date1, Date2));
}

enCompare CompareDates(stDate Date, stDate Date2) {
  if (IsDate1BeforeDate2(Date, Date2)) {
    return enCompare::Before;
  }
  if (IsDate1EqualDate2(Date, Date2)) {
    return enCompare::Equal;
  }
  return enCompare::After;
}

int GetDifferenceInDays(stDate Date1, stDate Date2,
                        bool IncludeEndDay = false) {
  int Days = 0;

  while (IsDate1BeforeDate2(Date1, Date2)) {
    Days++;
    Date1 = IncreaseDateByOneDay(Date1);
  }

  return IncludeEndDay ? ++Days : Days;
}

bool IsDateWithinPeroid(stPeriod Period, stDate Date) {
  return !(CompareDates(Date, Period.Start) == enCompare::Before ||
           CompareDates(Date, Period.End) == enCompare::After);
}

bool ComparePeroids(stPeriod Period1, stPeriod Period2) {
  if (CompareDates(Period2.End, Period1.Start) == enCompare::Before ||
      CompareDates(Period1.End, Period2.Start) == enCompare::After)
    return false;
  else
    return true;
}

int PeroidLengthInDays(stPeriod Period, bool WithLastDay = false) {
  return GetDifferenceInDays(Period.Start, Period.End, WithLastDay);
}
bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2) {
  if (CompareDates(Period2.End, Period1.Start) == enCompare::Before ||
      CompareDates(Period2.Start, Period1.End) == enCompare::After)
    return false;
  else
    return true;
}

short OverlapDaysCountInPeriod(stPeriod Period1, stPeriod Period2) {
  int Period1Length = PeroidLengthInDays(Period1, true);
  int Period2Length = PeroidLengthInDays(Period2, true);
  int OverlapDays = 0;

  if (!IsOverlapPeriods(Period1, Period2))
    return 0;

  if (Period1Length < Period2Length) {
    while (IsDate1BeforeDate2(Period1.Start, Period1.End)) {
      if (IsDateWithinPeroid(Period2, Period1.Start))
        OverlapDays++;
      Period1.Start = IncreaseDateByOneDay(Period1.Start);
    }
  } else {
    while (IsDate1BeforeDate2(Period2.Start, Period2.End)) {
      if (IsDateWithinPeroid(Period1, Period2.Start))
        OverlapDays++;
      Period2.Start = IncreaseDateByOneDay(Period2.Start);
    }
  }

  return OverlapDays;
}

// bool ValidateDate(stDate date) {
//   return (date.Day <= ReturnDaysOfMonth(date.Year, date.Month))
//              ? ((date.Month <= 12) ? true : false)
//              : false;
// }

bool ValidateDate(stDate date) {
  if (date.Day < 1 || date.Day > 31)
    return false;
  if (date.Month < 1 || date.Month > 12)
    return false;
  if (date.Month == 2) {
    if (isLeapYear(date.Year)) {
      if (date.Day > 29)
        return false;
      else {
        if (date.Day > 28)
          ;
        return false;
      }
    }
  }

  short DaysInMonth = ReturnDaysOfMonth(date.Year, date.Month);

  if (date.Day > DaysInMonth)
    return false;

  return true;
}

vector<string> SplitString(string S1, string Delim) {
  vector<string> vString;
  short pos = 0;
  string sWord; // define a string variable  // use find() function to get the
                // position of the delimiters
  while ((pos = S1.find(Delim)) != std::string::npos) {
    sWord = S1.substr(0, pos); // store the word
    if (sWord != "") {
      vString.push_back(sWord);
    }
    S1.erase(0, pos + Delim.length());
  }
  if (S1 != "") {
    vString.push_back(S1); // it adds last word of the string.
  }
  return vString;
}

stDate StringToDate(string D) {
  stDate date;
  vector<string> vString = SplitString(D, "/");

  date.Day = stoi(vString[0]);
  date.Month = stoi(vString[1]);
  date.Year = stoi(vString[2]);

  return date;
}

string DateToString(stDate date) {
  return to_string(date.Day) + "/" + to_string(date.Month) + "/" +
         to_string(date.Year);
}

string ReplaceWordInString(string S1, string StringToReplace,
                           string sRepalceTo) {
  short pos = S1.find(StringToReplace);

  while (pos != std::string::npos) {
    S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
    pos = S1.find(StringToReplace); // find next
  }

  return S1;
}

string PrintResults(stDate date, string format = "dd/mm/yyyy") {
  string FormattedDateString = "";

  FormattedDateString = ReplaceWordInString(format, "dd", to_string(date.Day));

  FormattedDateString =
      ReplaceWordInString(FormattedDateString, "mm", to_string(date.Month));

  FormattedDateString =
      ReplaceWordInString(FormattedDateString, "yyyy", to_string(date.Year));

  return FormattedDateString;
}

int main() {
  string S = ReadString("Please enter date (DD/MM/YYY): ");
  stDate date = StringToDate(S);

  cout << PrintResults(date) << "\n";
  cout << PrintResults(date, "yyyy/dd/mm") << "\n";
  cout << PrintResults(date, "mm/dd/yyyy") << "\n";
  cout << PrintResults(date, "mm-dd-yyyy") << "\n";
  cout << PrintResults(date, "dd-mm-yyyy") << "\n\n";
  cout << PrintResults(date, "Day:dd, Month:mm, Year:yyyy") << "\n";

  signature();
  return 0;
}
