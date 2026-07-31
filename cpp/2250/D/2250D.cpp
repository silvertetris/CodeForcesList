#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
ll INF = 998244353;
int n;
vector<int> a;
vector<bool> visited;
vector<int> pre;
vector<int> suf;
void solve() {
    cin>>n;
    a.assign(n-1, 0);
    visited.assign(n-1, false);
    int ones = 0;
    for(int i=0; i<n-1; i++) {
        cin>>a[i];
        if(a[i] == n) {
            cout<<0<<"\n";
            return;
        }
        if(a[i]==1) {
            ones++;
        }
        if(i>0 && i<n-1 && a[i]==1) {
            cout<<0<<"\n";
            return;
        }
    }
    if(ones>1) {
        cout<<0<<"\n";
        return;
    }
    int ans = 1;
    int remain = n;

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