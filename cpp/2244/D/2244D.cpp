#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n, m;
vector<int> a;
vector<int> b;
vector<vector<ll>> dp;
/*
배열 a, 길이 n
짧은 영상보면 음수, 일하면 양수
총합이 생산성
m 포스트, b_j 가 임펙트
j번찌 읽으면, 생산성이 처음부터 b_j까지 부호 바뀜
최대 생산성 수
포스트는 한번만 읽을 수 있는듯.
0이면 어쩔건데?
dp 다 이거 메모리삑 256mb
*/
vector<ll> prefix;
ll INF = LLONG_MIN+INT32_MAX;
void solve() {
    cin>>n>>m;
    prefix.assign(n+2, 0);
    /*
    #1. states/subproblems
    dp[i]= i번째 책을 읽었을때, 최대 값
    0: 음수 구간
    1: 양수 구간
    */
    dp.assign(m+1, vector<ll>(2, INF));
    //#2. baseCases
    dp[0][0] = 0;
    a.assign(n+2, 0);
    b.assign(m+1, 0);
    for(int i=1; i<=n; i++) {
        int x;
        cin>>x;
        prefix[i] = prefix[i-1] + x;
    }
    for(int i=1; i<=m; i++) {
        cin>>b[i];
    }
    b[0] = n;
    sort(b.begin()+1, b.end(), greater<int>());
    
    //#3. transitions
    for(int i=1; i<=m; i++) {
        ll cur = prefix[b[i-1]]-prefix[b[i]];
        dp[i][0] = max(dp[i-1][0] + cur, dp[i-1][1] -cur);
        dp[i][1] = max(dp[i-1][1]-cur,  dp[i-1][0] + cur);
    }
    ll last = prefix[b[m]];
    cout<< max(dp[m][0] + last, dp[m][1]-last)<<"\n";
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