#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n;
void solve() {
    cin>>n;
    if(n%2==0) {
        for(int i=2; i<=n; i++) {
            cout<<i<<" ";
        }
        cout<<1<<"\n";
    }else {
        for(int i=1; i<=n; i+=2) {
            cout<<i+1<<" ";
            cout<<i<<" ";
        }
        cout<<"\n";
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