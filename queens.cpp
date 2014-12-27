// this version works correctly

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
using std::string;
using std::stoi;
using std::uniform_int_distribution;
using std::vector;

vector<string> CreateOutput(const vector<int>& col_placement);
bool IsFeasible(const vector<int>& col_placement, int row);
void Helper(int n, int row, vector<int> & col_place, vector<vector<string>> &result);

// @include
vector<vector<string>> NQueens(int n) {
  vector<vector<string>> result;
  vector<int> col_place(n);
  Helper(n, 0, col_place, result);
  return result;
}

// try from row 1 to row n
void Helper(int n, int row, vector<int> & col_place, vector<vector<string>> &result) {
    //vector<int> col_place;
    if (row==n) {
        vector<string> vs = CreateOutput(col_place);
        result.push_back(vs);
    }
    //cout<<"row="<<row<<endl;
    for (int k=0;k<n;++k) { // when at "row", try all possible columns
        col_place[row] = k;
        if (IsFeasible(col_place, row)) {
            Helper(n, row+1, col_place, result);
        }
    }
}


vector<string> CreateOutput(const vector<int>& col_placement) {
  vector<string> sol;
  for (int row : col_placement) {
    string line(col_placement.size(), '.');
    line[row] = 'Q';
    sol.emplace_back(line);
  }
  return sol;
}

bool IsFeasible(const vector<int>& col_placement, int row) {
  for (int i = 0; i < row; ++i) {
    int diff = abs(col_placement[i] - col_placement[row]);
    if (diff == 0 || diff == row - i) {
      return false;
    }
  }
  //cout<<"feasible"<<endl;
  return true;
}
// @exclude

int main(int argc, char** argv) {
  default_random_engine gen((random_device())());
  int n;
  if (argc == 2) {
    n = stoi(argv[1]);
  } else {
    uniform_int_distribution<int> dis(1, 15);
    //n = dis(gen);
    
    n = 8;
  }
  cout << "n = " << n << endl;
  auto result = NQueens(n);
  int numresult = result.size();
  for (const auto& vec : result) {
    for (const string& s : vec) {
      cout << s << endl;
    }
    cout << endl;
  }
  printf("\n\n  numresult = %d\n\n", numresult);
  printf("\n\n  numresult should be 92 for n=8\n\n");
  return 0;
}
