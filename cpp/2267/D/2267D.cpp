#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n;
vector<int> a;

void solve() {
    cin>>n;
    a.assign(n, 0);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    vector<int> cnt(n+1, 0);
    for(int i=0; i<n; i++) {
        if(i%2==0) {
            cnt[a[i]] = 1; //홀
        }
        else {
            cnt[a[i]] = 2; //짝
        }
    }
    if(n%2==1 && cnt[1]==2) {
        cout<<"NO\n";
        return;
    }
    bool flag = true;

    int start= 0;
    if(n%2==0) {
        start = 2;
    }
    else {
        start = 3;
    }
    for(int i=start; i<=n; i+=2) {
        if(cnt[i]==cnt[i-1]) {
            flag = false;
            break;
        }
    }
    if(flag) {
        cout<<"YES\n";
    }
    else {
        cout<<"NO\n";
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