#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int n;
    cin>>n ;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    int minnum = a[0];
    ll res = a[0];
    for(int i=1; i<n; i++) {
        if(a[i]>=minnum) {
            res+=minnum;
        }else {
            minnum=a[i];
            res+=minnum;
        }
    }
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