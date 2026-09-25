#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n;
vector<int> a;
void solve() {
    cin>>n;
    a.assign(n, 0);
    vector<int> cnt(101, 0);
    for(int i=0; i<n; i++) {
        cin>>a[i];
        cnt[a[i]]++;
    }
    int ans = n;
    while(ans--) {
        for(int i=100; i>=1; i--) {
            if(cnt[i]>0) {
                cout<<i<<" ";
                cnt[i]--;
            }
        }
    }
    cout<<"\n";
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