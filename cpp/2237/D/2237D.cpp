#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n;
void solve() {
    cin>>n;
    string s;
    cin>>s;
    /*
    안되는놈 세기
    모든 구간 개수 -> n(n+1)/2
    1. 3개 000, 010, 101 세기
    2. 2개짜리 서로 다른거 근데 001, 110 포함된거 있음 -> 2개짜리 기준 2로 나눠야함
    00, 01
    11, 10

    000?
    
    */
    int type=0;
    vector<ll> dp(3, 0);//000, 010, 101
    bool flag = false;
    ll ans = ((ll)n*(ll)(n+1))/2;
    for(int i=0; i<n; i++) {
        int temp;

        if(s[i]=='0') {
            temp = 1;
        }else {
            temp = 2;
        }


        if(!flag) {
            flag= true;
            dp[type]++;
        }
        type=(type+temp)%3;
        ans -= dp[type];
        dp[type]++;
    }

    type = 0;//001, 110
    for(int i=1; i<n; i++) {
        if(s[i]!=s[i-1]) {
            type++;
        } else {
            type = 0;
        }
        ans-=type/2;
    }
    cout<<ans<<"\n";
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