// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::stoi;
using std::uniform_int_distribution;
using std::vector;


void CombinationsHelper(int start, int n, int k, vector<int> &r, vector<vector<int>> &ans) {
  if (r.size()==k) {
    ans.push_back(r);        
    return;
  }                       
  for (int i=start; i<=n; ++i) {
    r.push_back(i);                         
    CombinationsHelper(i+1, n, k, r, ans);
    r.pop_back();
  }
}


vector<vector<int>> Combinations(int n, int k) {
  vector<int> r;
  vector<vector<int>> ans;
  CombinationsHelper(1, n, k, r, ans);
  return ans;
}



int main(int argc, char** argv) {
  default_random_engine gen((random_device())());
  int n, k;
  if (argc == 3) {
    n = stoi(argv[1]), k = stoi(argv[2]);
  } else {
    uniform_int_distribution<int> n_dis(1, 10);
    n = n_dis(gen);
    uniform_int_distribution<int> k_dis(0, n);
    k = k_dis(gen);
  }
  auto result = Combinations(n, k);
  cout << "n = " << n << ", k = " << k << endl;
  for (const auto& vec : result) {
    for (int a : vec) {
      cout << a << " ";
    }
    cout << endl;
  }
  return 0;
}
