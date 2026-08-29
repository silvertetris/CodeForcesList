#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n, m;
vector<int> a;
void solve() {
    cin>>n>>m;
    a.assign(n, 0);
    vector<ll> visited(m+1, 0);
    for(int i=0; i<n; i++) {
        cin>>a[i];
        visited[a[i]]++;
    }
    vector<ll> prefix(m+1, 0);
    for(int i=1; i<=m; i++) {
        prefix[i] = prefix[i-1] + visited[i];
    }
    
    ll temp = 0;
    for(int i=1; i<=m; i++) {
        int mul = 2*i;
        if(mul<=m) {
            temp = max(prefix[m] - prefix[i-1]+visited[mul], temp);
        }
    }
    cout<<max(temp, (ll)n)<<"\n";
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