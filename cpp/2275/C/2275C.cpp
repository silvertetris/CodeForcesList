#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n, 0);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    vector<int> cnt(100000, 0);
    vector<int> temp(100000, 0);
    for(int i=0; i<n-4; i++) {
        int cur = (a[i]+a[i+2] - a[i+4])+50000;
        cnt[cur]++;
        if(i-2>=0) {
            if(cur == a[i-2]+a[i]-a[i+2]+50000) {
                temp[cur]++;
            }
        }
        if(i-4>=0) {
            if(cur==a[i-4]+a[i-2]-a[i]+50000) {
                temp[cur]++;
            }
        }
    }
    ll ans = 0;
    for(int i=0; i<100000; i++) {
        ans+= ((ll)cnt[i]* (cnt[i]-1)/2) -temp[i];
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