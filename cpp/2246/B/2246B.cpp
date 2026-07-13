#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n;
vector<ll> pres;
void solve() {
    cin>>n;
    if(n==2) {
        cout<<"-1\n";
    } else {
        for(int i=0; i<n; i++) {
            cout<<pres[i]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);
    pres.assign(50, 0);
    pres[0] = 1;
    pres[1] = 2;
    pres[2] = 3;

    for(int i=3; i<50; i++) {
        pres[i] = pres[i-1]*2;
    }
    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}