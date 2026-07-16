#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int n, c;
    cin>>n>>c;
    deque<int> a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    ll ans=0;
    bool flag = false;
    sort(a.begin(), a.end());
    while(!a.empty()) {
        if(a.size()==1) {
            ans+=a.back();
            a.pop_back();
            ans-=c;
            break;
        }
        if(a.back()<=c) {
            flag = true;
        }
        if(flag) {
            a.pop_front();
            ans+=a.back();
            a.pop_back();
            ans-=c;
        } else {
            if(a.front()<c) {
                a.pop_front();
                ans+=a.back();
                a.pop_back();
                ans-=c;
            } else {
                ans+=a.back();
                a.pop_back();
                ans-=c;
            }
        }
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