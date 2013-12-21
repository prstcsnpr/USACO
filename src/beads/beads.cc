/*
ID: prstcsn1
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int determine(int, const string&);

int main() {
  ofstream fout("beads.out");
  ifstream fin("beads.in");
  int N;
  string beads;
  fin >> N;
  fin >> beads;
  int m = 0;
  for (int i = 0; i < beads.size(); ++i) {
    m = max(m, determine(i, beads));
  }
  fout << m << endl;
  return EXIT_SUCCESS;
}

int determine(int point, const string& beads) {
  int result = 2;
  char flag = beads[point];
  for (int i = (point + beads.size() - 1) % beads.size(); result < beads.size(); i = (i + beads.size() - 1) % beads.size()) {
    if (beads[i] == 'w') {
      result++;
    } else {
      if (flag == 'w') {
        flag = beads[i];
        result++;
      } else {
        if (flag == beads[i]) {
          result++;
        } else {
          break;
        }
      }
    }
  }
  flag = beads[(point + 1) % beads.size()];
  for (int i = (point + 2) % beads.size(); result < beads.size(); i = (i + 1) % beads.size()) {
    if (beads[i] == 'w') {
      result++;
    } else {
      if (flag == 'w') {
        flag = beads[i];
        result++;
      } else {
        if (flag == beads[i]) {
          result++;
        } else {
          break;
        }
      }
    }
  }
  return result;
}
