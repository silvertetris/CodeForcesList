#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n;
vector<ll> a;
void solve() {
    cin>>n;
    a.assign(n+1, 0);
    for(auto i=1; i<=n; i++) {
        cin>>a[i];
    }
    /*
    i=1 부터 1234 순으로 가야함
    */
    for(auto i=1; i<n; i++) {
        if(a[i]<i) {
            cout<<"NO\n";
            return;
        }
        ll temp = a[i]-i;
        a[i+1] += temp;
        a[i] -= temp;
        if(a[i+1]<=a[i]) {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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