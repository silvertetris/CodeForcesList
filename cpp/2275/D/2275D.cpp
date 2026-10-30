#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int n;
    ll k;
    cin>>n>>k;
    vector<ll> a(n, 0);
    vector<ll> b(n, 0);
    vector<ll> c(n, 0);
    for(int i=0; i<n; i++) {
        cin>>a[i]>>b[i]>>c[i];
    }
    ll l = LLONG_MIN/2;
    ll r = LLONG_MAX/2;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll remain = k;
        bool flag = false;
        for(int i=0; i<n; i++) {

            ll summ = a[i]+b[i]+c[i];
            if(summ>=mid) continue;
            else {
                ll val = min({c[i]-b[i], b[i]-a[i], c[i]-a[i]});
                if(a[i] == b[i] && c[i] == b[i]) {
                    flag = true;
                    break;
                }
                if(val<0) {
                    remain-=mid-summ;
                } else {
                    remain-= mid-(summ-(val+1))+(val+1);
                }
            }
            if(remain<0) {
                flag = true;
                break;
            }
        }
        if(flag) {
            r = mid-1;
        }else {
            l = mid+1;
        }

    }
    cout<<l-1<<"\n";
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