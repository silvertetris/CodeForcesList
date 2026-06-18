#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    ll res = 0;
    for(int i=1; i<n; i++) {
        if(a[i-1]>a[i]) {
            swap(a[i-1], a[i]);
            a[i]+=a[i-1];
        }
    }
    res = a[n-1];
    cout<<res<<"\n";
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