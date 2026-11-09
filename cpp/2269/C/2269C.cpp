#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n, k;

void solve() {
    cin>>n>>k;  
    vector<int> a;
    for(int i=1; i<=n; i++) {
        int u;
        cin>>u;
        a.push_back(u);
    }
    ll ans = 0;
    while(true) {
        if(a.size()<k) {
            cout<<ans<<"\n";
            return;
        }
        ll first = a[k-1];
        ll second = a[a.size()-k];
        if(first<second) {
            ans+=second;
            a.erase(a.begin()+a.size()-k);
            //cout<<ans<<"\n";
        }else {
            ans+=first;
            a.erase(a.begin()+k-1);
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