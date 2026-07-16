#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt = 0;
    int maxx = 0;
    for(int i=0; i<n; i++) {
        if(s[i]=='*') {
            maxx = max(maxx, cnt);
            cnt = 0;
        } else {
            cnt++;
            maxx = max(maxx, cnt);
        }
    }
    maxx++;
    cout<<maxx/2<<"\n";
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