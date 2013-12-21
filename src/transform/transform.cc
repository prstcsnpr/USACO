/*
ID: prstcsn1
PROG: transform
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> rotate(const vector<string>& before) {
  vector<string> result = before;
  for (int i = 0; i < before.size(); ++i) {
    for (int j = 0; j < before[i].size(); ++j) {
      result[i][j] = before[before.size() - j - 1][i];
    }
  }
  return result;
}

vector<string> reflecte(const vector<string>& before) {
  vector<string> result = before;
  for (int i = 0; i < before.size(); ++i) {
    reverse(result[i].begin(), result[i].end());
  }
  return result;
}

bool compare(const vector<string>& a, const vector<string>& b) {
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  ofstream fout("transform.out");
  ifstream fin("transform.in");
  int N;
  fin >> N;
  vector<string> before;
  vector<string> after;
  for (int i = 0; i < N; ++i) {
    string line;
    fin >> line;
    before.push_back(line);
  }
  for (int i = 0; i < N; ++i) {
    string line;
    fin >> line;
    after.push_back(line);
  }
  before = rotate(before);
  if (compare(before, after)) {
    fout << 1 << endl;
    return EXIT_SUCCESS;
  }
  before = rotate(before);
  if (compare(before, after)) {
    fout << 2 << endl;
    return EXIT_SUCCESS;
  }
  before = rotate(before);
  if (compare(before, after)) {
    fout << 3 << endl;
    return EXIT_SUCCESS;
  }
  before = rotate(before);
  if (compare(before, after)) {
    fout << 6 << endl;
    return EXIT_SUCCESS;
  }
  before = reflecte(before);
  if (compare(before, after)) {
    fout << 4 << endl;
    return EXIT_SUCCESS;
  }
  before = rotate(before);
  if (compare(before, after)) {
    fout << 5 << endl;
    return EXIT_SUCCESS;
  }
  before = rotate(before);
  if (compare(before, after)) {
    fout << 5 << endl;
    return EXIT_SUCCESS;
  }
  before = rotate(before);
  if (compare(before, after)) {
    fout << 5 << endl;
    return EXIT_SUCCESS;
  }
  fout << 7 << endl;
  return EXIT_SUCCESS;
}
