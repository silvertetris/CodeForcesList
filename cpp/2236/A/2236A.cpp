#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i=0;i<n;i++) {
        cin>>h[i];
    }
    sort(h.begin(), h.end());
    int ans = h.back()+1 - h[0];
    cout<<ans<<endl;
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