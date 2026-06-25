#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    string s, t;
    cin>>s>>t;
    vector<int> cnt(26, 0);
    for(int i=0; i<t.size(); i++) {
        cnt[t[i]-'a']++;

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}