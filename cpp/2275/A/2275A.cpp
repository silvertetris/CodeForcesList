#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int x, y, r;
    cin>>x>>y>>r;
    r *=r;
    for(int i=-50; i<=50; i++) {
        for(int j=-50; j<=50; j++) {
            int cur = (x-i)*(x-i) + (y-j) * (y-j);
            if(cur==r) {
                cout<<i<<" "<<j<<"\n";
                return;
            }
        }
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