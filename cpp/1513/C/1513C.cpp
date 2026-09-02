#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
string n;
int m;
int INF = 1e9+7;
vector<ll> dp;
void solve() {
    cin>>n>>m;
    ll ans = 0;
    for(int i=0; i<n.size(); i++) {
        ans += dp[n[i]-'0' + m];
        ans%=INF;
    }
    cout<<ans<<"\n";
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);
    /*
    #1. states/subproblems
    dp(i, j) = i반복시 j스타트에서 -> 사이즈
    dp[i] = 1스타트 +m시에 자리수
    */
   //#2. Base Cases

    dp.assign(2e5+10, 1ll);
    dp[10] = 2;
    for(int i=10; i<2e5+10; i++) {
        dp[i] = (dp[i-9]+dp[i-10])%INF;
    }
    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}