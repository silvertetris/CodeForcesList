#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int x, y;
    ll k;
    cin>>x>>y>>k;
    ll ans =0;
    ll pos = 0;
    while(true){
        ans+= (y+pos) %(x+pos);
        pos++;
        if(pos>=k) break;
        if((y+pos)/(x+pos)<=1) break;
    }
    if(pos<k) {
        ans+=(k-pos) * (y-x);
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