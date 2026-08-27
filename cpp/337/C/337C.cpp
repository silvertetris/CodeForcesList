#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

int INF = 1e9+9;
ll power (ll base, ll exp) {
    ll result = 1;
    base%=INF;

    while(exp>0) {
        if(exp%2!=0) {
            result = result * base %INF;
        }
        base = base*base %INF;
        exp/=2;
    }
    return result;
}
void solve() {
    int n, m, k;//문제수, 맞춘거, 이만큼 연속으로 맞추면 2배
    cin>>n>>m>>k;
    int x;
    x = max(0, (m-n+n/k));
    ll ans = ((2*k)%INF *(power(2, x)-1)%INF)%INF +m%INF - x%INF*k%INF;
    ans%=INF;
    cout<<ans<<"\n";
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t=1;

    while(t--) {
        solve();
    }
}