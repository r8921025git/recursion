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
vector<vector<int>> GeneratePowerSet(const vector<int>& S) {
    // remove last elem
    vector<int> subset = S;
    if (subset.empty()) {
        vector<vector<int>> nset;
        return nset;
    }
    int b = subset.back();
    subset.pop_back();
    // recurse
    vector<vector<int>> pset = GeneratePowerSet(subset);
    // append
    vector<vector<int>> nset = pset;
    if (pset.empty()) {
        vector<int> tmp;
        nset.push_back(tmp);
        vector<int> tmp2 = {b};
        nset.push_back(tmp2);
    }
    
    for (auto i : pset)      {
        vector<int> tmp = i;
        tmp.push_back(b);
        nset.push_back(tmp);
    }
    return nset;
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


// 2014/12/2, my version
void GeneratePowerSetHelper2(const vector<int>& S, int m,
                            vector<int>* subset) {

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
  vector<vector<int>> pset = GeneratePowerSet(S);
  for (auto i : pset)      {
      PrintIt(i);
  }
  printf("Final count = %d\n", count);
  return 0;
}
