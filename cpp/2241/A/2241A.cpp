#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int x, y;
    cin>>x>>y;
    if(x%y==0) {
        cout<<"YES\n";
    }else cout<<"NO\n";
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