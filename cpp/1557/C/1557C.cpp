#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
ll INF = 1e9+7;
ll power(ll base, ll exp) {
    base%=INF;
    ll r = 1;
    while(exp) {
        if(exp%2==1) {
            r = r*base %INF;
        }
        base = base*base%INF;
        exp/=2;
    }
    return r;
}
void solve() {
    int n, k;
    cin>>n>>k;
    if(n%2==1) {
        //(2^(n-1) +1)^k
        cout<<power(power(2, n-1)+1, k)<<"\n";

    } else {
        //(2^(n-1)-1)^k + for k -> (2^(n-1)-1)^(i-1) * (2^n) ^(k-i)
        ll a = power(2, n);
        ll b = (power(2, n-1) -1 + INF) %INF;

        ll ans = power(b, k);
        for(ll i =1; i<=k; i++) {
            ans = (ans + power(b, i-1) * power(a, k-i))%INF;
        }
        cout<<ans<<"\n";
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