// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::endl;
//using std::ostream_iterator;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

void GeneratePowerSetHelper(const vector<int>& S, int m, vector<int>* subset);
void GeneratePowerSetHelper2(const vector<int>& S, int m, vector<int>* subset);

static int count = 0;

// @include
void GeneratePowerSet(const vector<int>& S) {
  vector<int> subset;
  //GeneratePowerSetHelper(S, 0, &subset);
  GeneratePowerSetHelper2(S, 0, &subset);
}

void PrintIt(const vector<int> & subset) {
  count++;
  if (!subset.empty()) {
    // Print the subset.
    cout << subset.front();
    for (int i = 1; i < subset.size(); ++i) {
      cout << "," << (subset)[i];
    }
  }
  cout << endl;  
}


// 2014/11/24, my version
void GeneratePowerSetHelper2(const vector<int>& S, int m,
                            vector<int>* subset) {

  //without m
  GeneratePowerSetHelper(S, m + 1, subset);
  PrintIt(*subset);
  //with m
  subset->emplace_back(S[m]);
  GeneratePowerSetHelper(S, m + 1, subset);
  PrintIt(*subset);
}

// original code
void GeneratePowerSetHelper(const vector<int>& S, int m,
                            vector<int>* subset) {

  for (int i = m; i < S.size(); ++i) {
    //cout <<"-push_back\n";
    subset->emplace_back(S[i]);
    //cout << "-func()\n";
    PrintIt(*subset);
    GeneratePowerSetHelper(S, i + 1, subset);
    //cout<< "-pop\n";
    subset->pop_back();
  }
}
// @exclude

int main(int argc, char* argv[]) {
  vector<int> S;
  if (argc >= 2) {
    for (int i = 1; i < argc; ++i) {
      S.emplace_back(atoi(argv[i]));
    }
  } else {
    default_random_engine gen((random_device())());
    uniform_int_distribution<int> dis(1, 10);
    //S.resize(dis(gen));
    S.resize(3);
    for (int i = 0; i < S.size(); ++i) {
      S[i] = i;
    }
  }
  GeneratePowerSet(S);
  printf("\n\n\n  Final count = %d\n", count);
  return 0;
}
