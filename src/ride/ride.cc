/*
ID: prstcsn1
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int converte(const string&);

int main() {
  ofstream fout("ride.out");
  ifstream fin("ride.in");
  string group, comet;
  fin >> group >> comet;
  if (converte(group) == converte(comet)) {
    cout << "GO" << endl;
  } else {
    cout << "STAY" << endl;
  }
}

int converte(const string& s) {
  int result = 1;
  for (string::const_iterator i = s.begin(); i != s.end(); ++i) {
    result *= (*i - 'A' + 1);
  }
  return result % 47;
}
