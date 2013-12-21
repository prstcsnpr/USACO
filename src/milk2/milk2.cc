/*
ID: prstcsn1
PROG: milk2
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Farmer {
public:
  Farmer() : begin_time_(0), end_time_(0), merged_(false) {}
  Farmer(int begin_time, int end_time) : begin_time_(begin_time), end_time_(end_time), merged_(false) {}
  Farmer(const Farmer& farmer) : begin_time_(farmer.begin_time_), end_time_(farmer.end_time_), merged_(farmer.merged_) {}
  int begin_time() const {return begin_time_;}
  int end_time() const {return end_time_;}
  bool merged() const {return merged_;}
  void set_merged(bool flag) {merged_ = flag;}
  void merge(Farmer& farmer) {
    if(farmer.begin_time() <= end_time_) {
      begin_time_ = min(begin_time_, farmer.begin_time());
      end_time_ = max(end_time_, farmer.end_time());
      farmer.set_merged(true);
    }
  }
private:
  int begin_time_;
  int end_time_;
  bool merged_;
};

bool cmp(const Farmer& a, const Farmer& b) {
  return a.begin_time() < b.begin_time();
}

int main() {
  ofstream fout("milk2.out");
  ifstream fin("milk2.in");
  int N;
  int begin;
  int end;;
  vector<Farmer> farmers;
  fin >> N;
  for (int i = 0; i < N; ++i) {
    fin >> begin >> end;
    farmers.push_back(Farmer(begin, end));
  }
  sort(farmers.begin(), farmers.end(), cmp);
  for (int i = 0; i < farmers.size(); ++i) {
    if (farmers[i].merged()) {
      continue;
    }
    for (int j = i + 1; j < farmers.size(); ++j) {
      farmers[i].merge(farmers[j]);
    }
  }
  int working_time = 0;
  int idle_time = 0;
  Farmer last_farmer;
  for (int i = 0; i < farmers.size(); ++i) {
    if (farmers[i].merged()) {
      continue;
    }
    
    working_time = max(working_time, farmers[i].end_time() - farmers[i].begin_time());
    if (i > 0) {
      idle_time = max(idle_time, farmers[i].begin_time() - last_farmer.end_time());
    }
    last_farmer = farmers[i];
  }
  fout << working_time << " " << idle_time << endl;
  return EXIT_SUCCESS;
}
