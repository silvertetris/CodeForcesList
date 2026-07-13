#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n;
int INF = 1e9 +7;
vector<int> a;
void solve() {
    cin>>n;
    a.assign(n+1, 0);
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }
    vector<vector<ll>> dp (n+1, vector<ll> (3, 0));\
    /*
    #1. states/subproblems
    dp[i][j] = i번째 인덱스에서, j state에 대한 경우의 수
    0: 통합
    1: 홀수로 선택할때
    2: 짝수로 선택할때
    */
   //#2. Base Cases
    dp[0][0] = 1;
    //#3. transitions
    for(int i=1; i<=n ;i++) {
        dp[i][0] = dp[i-1][0];

    }
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}