/*
ID: prstcsn1
PROG: namenum
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int words[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0};

long long transform(const string& word) {
  long long result = 0;
  for (int i = 0; i < word.size(); ++i) {
    if (word[i] == 'Q' || word[i] == 'Z') {
      return 0;
    }
    result = result * 10 + words[word[i] - 'A'];
  }
  return result;
}

int main() {
  ifstream f("dict.txt");
  vector<string> list;
  while (f.good()) {
    string word;
    f >> word;
    list.push_back(word);
  }
  ofstream fout("namenum.out");
  ifstream fin("namenum.in");
  long long number;
  fin >> number;
  vector<string> results;
  for (vector<string>::iterator i = list.begin(); i != list.end(); ++i) {
    if (transform(*i) == number) {
      results.push_back(*i);
    }
  }
  if (results.size() == 0) {
    fout << "NONE" << endl;
  } else {
    for (vector<string>::iterator i = results.begin(); i != results.end(); ++i) {
      fout << *i << endl;
    }
  }
  return EXIT_SUCCESS;
}

