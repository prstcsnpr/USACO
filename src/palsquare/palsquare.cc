/*
ID: prstcsn1
PROG: palsquare
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

char letters[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};

string encode(int number, int base) {
  stringstream result;
  while (number > 0) {
    result << letters[number % base];
    number /= base;
  }
  string s = result.str();
  reverse(s.begin(), s.end());
  return s;
}

bool palindrome(const string& str) {
  string result = str;
  reverse(result.begin(), result.end());
  return result == str;
}

int main() {
  ofstream fout("palsquare.out");
  ifstream fin("palsquare.in");
  int B;
  fin >> B;
  for (int i = 1; i <= 300; ++i) {
    string code = encode(i * i, B);
    if (palindrome(code)) {
      fout << encode(i, B) << " " << code << endl;
    }
  }
  return EXIT_SUCCESS;
}

