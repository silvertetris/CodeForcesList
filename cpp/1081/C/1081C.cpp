#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
ll INF = 998244353;
vector<ll> fac;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> dp (n+1, vector<ll> (k+1, 0));
    dp[1][0] = m;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i-1][j-1] * (m-1)) % INF;
        }
    }
    cout << dp[n][k] << "\n";
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);
    fac.assign(2001, 0ll);
    fac[0] = 1;
    for(auto i=1 ;i<=2000; i++) {
        fac[i] = fac[i-1]*i;
        fac[i]%= INF;
    }
    solve();
}