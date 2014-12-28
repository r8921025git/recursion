#include <iostream>
#include <vector>
using namespace std;
using std::vector;

int cnt = 0;
void sumN(int sum, int c, int n){
    if(sum >= n){
        if(sum == n) ++cnt;
        return;
    }
    else{
        if(c >= 25)
            sumN(sum+25, 25, n);
        if(c >= 10)
            sumN(sum+10, 10, n);
        if(c >= 5)
            sumN(sum+5, 5, n);
        if(c >= 1)
            sumN(sum+1, 1, n);
    }
}
int sum_n(int sum, int c, int n){
    int ways = 0;
    if(sum <= n){
        if(sum == n) return 1;
        if(c >= 25)
            ways += sum_n(sum+25, 25, n);
        if(c >= 10)
            ways += sum_n(sum+10, 10, n);
        if(c >= 5)
            ways += sum_n(sum+5, 5, n);
        if(c >= 1)
            ways += sum_n(sum+1, 1, n);
    }
    return ways;
}
int make_change(int n, int denom){
    int next_denom = 0;
    switch(denom){
    case 25:
        next_denom = 10;
        break;
    case 10:
        next_denom = 5;
        break;
    case 5:
        next_denom = 1;
        break;
    case 1:
        return 1;
    }
    int ways = 0;
    for(int i=0; i*denom<=n; ++i)
        ways += make_change(n-i*denom, next_denom);
    return ways;
}

int dada(int n,vector<int> coins) {
    const int N = coins.size();
    if (n==0)
        return 1;
    
    if (N==0)
        return 0;

    int coin_value = coins[N-1];
    vector<int> subset_coins=coins;
    subset_coins.pop_back();
    int result = dada(n, subset_coins);
    
    int i=1;
    while(n-i*coin_value >=0) {
        result += dada(n - i*coin_value, subset_coins);
        i++;
    }
    return result;
}

int main(){
    vector<int> coins={1,5,10,25};
    int n = 16;
    sumN(0, 25, n);
    cout<<cnt<<endl;
    cout<<make_change(n, 25)<<endl;
    cout<<sum_n(0, 25, n)<<endl;
    cout<<"my method: "<<dada(n, coins)<<endl;
    return 0;
}
