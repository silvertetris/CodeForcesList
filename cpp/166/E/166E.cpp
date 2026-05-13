#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int MOD = 1e9+7;
    int n;
    cin>>n;
    int dp[n+1][4] ={0,}; 
    dp[0][3] = 1;
    for(int i=1; i<=n; i++) {
        dp[i][0] = ((dp[i-1][1] + dp[i-1][2])%MOD + dp[i-1][3])%MOD;
        dp[i][1] = ((dp[i-1][0] + dp[i-1][2])%MOD + dp[i-1][3])%MOD;
        dp[i][2] = ((dp[i-1][0] + dp[i-1][1])%MOD + dp[i-1][3])%MOD;
        dp[i][3] = ((dp[i-1][0] + dp[i-1][1])%MOD + dp[i-1][2])%MOD;
    }
    cout<<dp[n][3]<<endl;
}