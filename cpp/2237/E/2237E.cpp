#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

int n;

void solve() {
    cin>>n;
    vector<int> a(n+1);
    vector<int> b(n+1);
    vector<bool> visited(n+1, false);
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }
    for(int i=1; i<=n; i++) {
        cin>>b[i];
        visited[b[i]] = true;
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