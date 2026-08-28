#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
string n;
int m;
int INF = 1e9+7;

void solve() {
    cin>>n>>m;

}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);
    /*
    #1. states/subproblems
    dp(i, j) = i반복시 j스타트에서 -> 사이즈
    */
   //#2. Base Cases
    vector<vector<ll>> dp(2*100001, vector<ll> (10, 1));
    //#3. transitions
    for(int i=1; i<=2e5; i++) {
        for(int j=0; j<10; j++) {
            if(j<9) {
                dp[i][j] = dp[i-1][j+1];
            }
            else {
                dp[i][j] = 
            }
        }
    }

    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}