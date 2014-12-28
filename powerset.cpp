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


int count = 0;


void Func(vector<int> S, vector<int> cur, vector<vector<int>> &result) {
    
    
    // Either include the last item, Or exclude the last item
    
    
    const int N = S.size();
    if (N==0) {
        result.push_back(cur);
        return;
    }
    
    int last_item = S[N-1];
    S.pop_back();

    // exclude the last item
    Func(S, cur, result);
    // include the last item
    cur.push_back(last_item);
    Func(S, cur, result);
    
}


vector<vector<int>> GeneratePowerSet(vector<int> S) {
    vector<int> cur;
    vector<vector<int>> result;
    Func(S, cur, result);
    return result;
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



int main(int argc, char* argv[]) {
  vector<int> S;

    default_random_engine gen((random_device())());
    uniform_int_distribution<int> dis(1, 10);
    //S.resize(dis(gen));
    S.resize(4);
    for (int i = 0; i < S.size(); ++i) {
      S[i] = i;
    }

  vector<vector<int>> pset = GeneratePowerSet(S);
  for (auto i : pset)      {
      PrintIt(i);
  }
  printf("Final count = %d\n", count);
  return 0;
}
