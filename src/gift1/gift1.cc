/*
ID: prstcsn1
PROG: gift1
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Person {
private:
  string name_;
  int initial_money_;
  int final_money_;
public:
  Person() : name_(""), initial_money_(0), final_money_(0) {}
  Person(const string& name) : name_(name), initial_money_(0), final_money_(0) {}
  Person(const Person& person) : name_(person.name_), initial_money_(person.initial_money_), final_money_(person.final_money_) {}
  void set_initial_money(int initial_money) {initial_money_ = initial_money;}
  void add_final_money(int money) {final_money_ += money;}
  int get_left_money() {return final_money_ - initial_money_;}
};

int main() {
  ofstream fout("gift1.out");
  ifstream fin("gift1.in");
  int NP;
  fin >> NP;
  map<string, Person> people;
  vector<string> names;
  for (int i = 0; i < NP; ++i) {
    string name;
    fin >> name;
    names.push_back(name);
    people.insert(make_pair<string, Person>(name, Person(name)));
  }
  for (int i = 0; i < NP; ++i) {
    string name;
    fin >> name;
    int initial_money, count;
    fin >> initial_money >> count;
    people[name].set_initial_money(initial_money);
    if (0 == count) {
      people[name].add_final_money(initial_money);
    } else {
      people[name].add_final_money(initial_money % count);
    }
    for (int j = 0; j < count; ++j) {
      fin >> name;
      people[name].add_final_money(initial_money / count);
    }
  }
  for (vector<string>::iterator i = names.begin(); i != names.end(); ++i) {
    fout << *i << ' ' << people[*i].get_left_money() << endl;
  }
}

