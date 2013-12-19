/*
ID: prstcsn1
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int compute(int, int);

bool isLeapYear(int);

int main() {
  ofstream fout("friday.out");
  ifstream fin("friday.in");
  int week[7] = {0};
  int N;
  fin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 1; j <= 12; ++j) {
      week[compute(1900 + i, j) % 7]++;
    }
  }
  fout << week[6] << " " << week[0] << " " << week[1] << " " << week[2] << " " << week[3] << " " << week[4] << " " << week[5] << endl;
  return EXIT_SUCCESS;
}

bool isLeapYear(int year) {
  if (year % 100 == 0) {
    if (year % 400 == 0) {
      return true;
    } else {
      return false;
    }
  } else {
    if (year % 4 == 0) {
      return true;
    } else {
      return false;
    }
  }
}

int compute(int year, int month) {
  int count = 0;
  for (int i = 1900; i < year; ++i) {
    if (isLeapYear(i)) {
      count += 366;
    } else {
      count += 365;
    }
  }
  for (int i = 1; i < month; ++i) {
    if (i == 2) {
      if (isLeapYear(year)) {
        count += 29;
      } else {
        count += 28;
      }
      continue;
    }
    if (i == 4 || i == 6 || i == 9 || i == 11) {
      count += 30;
    } else {
      count += 31;
    }
  }
  return count + 13;
}
