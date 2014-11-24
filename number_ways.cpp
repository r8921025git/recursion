// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <iostream>
#include <random>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::swap;
using std::uniform_int_distribution;
using std::vector;

static int count_3 = 0;
static int count_2 = 0;

// 2014.11.24 also my method
int NumberOfWays_3(int n, int m, vector<vector<int>> & table) {
    count_3++;
  if (n < m) {
 //   swap(n, m);
  }
  if (n==1 || m==1) {
      table[1][1] = 1;
      return 1;
  }
  //int ha = NumberOfWays_3(n,m-1, table) + NumberOfWays_3(n-1,m, table);// - NumberOfWays_2(n-1,m-1);
  int k1 = 0;
  if (table[n][m-1]>0)
    k1 = table[n][m-1];
  else
    k1 = NumberOfWays_3(n,m-1, table);
  
  int k2 = 0;
  if (table[n-1][m]>0)
    k2 = table[n-1][m];
  else
    k2 = NumberOfWays_3(n-1,m, table);

  int ha = k1 + k2;
  table[n][m] = ha;
  return ha;
  
}


// 2014.11.24 my method
int NumberOfWays_2(int n, int m) {
    count_2++;
  if (n < m) {
 //   swap(n, m);
  }
  if (n==1 || m==1)
    return 1;
  int ha = NumberOfWays_2(n,m-1) + NumberOfWays_2(n-1,m);// - NumberOfWays_2(n-1,m-1);
  return ha;
  
}



// @include
int NumberOfWays(int n, int m) {
  if (n < m) {
    swap(n, m);
  }
  vector<int> A(m, 1);
  for (int i = 1; i < n; ++i) {
    int prev_res = 0;
    for (int j = 0; j < m; ++j) {
      A[j] = A[j] + prev_res;
      prev_res = A[j];
    }
  }
  return A[m - 1];
}
// @exclude

int CheckAns(int n, int k) {
  vector<vector<int>> table(n + 1, vector<int>(k + 1));
  // Basic case: C(i, 0) = 1.
  for (int i = 0; i <= n; ++i) {
    table[i][0] = 1;
  }
  // Basic case: C(i, i) = 1.
  for (int i = 1; i <= k; ++i) {
    table[i][i] = 1;
  }
  // C(i, j) = C(i - 1, j) + C(i - 1, j - 1).
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < i && j <= k; ++j) {
      table[i][j] = table[i - 1][j] + table[i - 1][j - 1];
    }
  }
  return table[n][k];
}

int main(int argc, char* argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 1; ++times) {
    int n, m;
    if (argc == 3) {
      n = atoi(argv[1]), m = atoi(argv[2]);
    } else {
      uniform_int_distribution<int> dis(1, 10);
      n = dis(gen);
      m = dis(gen);
    }
    n=10;
    m=7;
    vector<vector<int>> table(n + 1, vector<int>(m + 1, -1));
    cout << "n = " << n << ", m = " << m
         << ", number of ways_3 = " << NumberOfWays_3(n, m, table) << endl;
    cout << "n = " << n << ", m = " << m
         << ", number of ways_2 = " << NumberOfWays_2(n, m) << endl;
    cout << "n = " << n << ", m = " << m
         << ", correct number of ways = " << NumberOfWays(n, m) << endl;

    printf("count_2=%d, count_3=%d\n",count_2,count_3);

    assert(CheckAns(n + m - 2, m - 1) == NumberOfWays_2(n, m));
    if (argc == 3) {
      break;
    }
  }
  return 0;
}
