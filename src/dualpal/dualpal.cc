/*
ID: prstcsn1
PROG: dualpal
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

char letters[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

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
  ofstream fout("dualpal.out");
  ifstream fin("dualpal.in");
  int N, S;
  fin >> N >> S;
  while (N > 0) {
    ++S;
    int count = 0;
    for (int i = 2; i <= 10; ++i) {
      if (palindrome(encode(S, i))) {
        count++;
      }
      if (count >= 2) {
        fout << S << endl;
        --N;
        break;
      }
    }
  }
  return EXIT_SUCCESS;
}

