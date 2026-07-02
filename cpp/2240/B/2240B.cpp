#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
ll INF = 998244353;
ll power(ll x, ll exp, ll m) {
    ll result = 1;
    x %= m;
    while(exp>0) {
        if(exp%2==1) {
            result = (result * x)%m;
        }
        exp/=2;
        x= (x*x)%m;
    }
    return result;
}
void solve() {
    ll n, m, r, c;
    cin>>n>>m>>r>>c;
    ll f = (c-1)*(1-r)%(INF-1);
    ll d = m*(r-1) + n*(c-1);
    f=d%(INF-1);
    f%=(INF-1);
    
    f+=d;
    ll result = power(2,  f, INF);
    cout<<result<<"\n";
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