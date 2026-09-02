#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n;
vector<ll> odd;
vector<ll> even;
vector<ll> oddPrefix;
vector<ll> evenPrefix;
void solve() {
    cin>>n;
    if(n%2==0) {
        odd.assign(n/2, 0);
        even.assign(n/2, 0);
        oddPrefix.assign(n/2, 0ll);
        evenPrefix.assign(n/2, 0ll);
    } else {
        odd.assign(n/2+1, 0);
        even.assign(n/2, 0);
        oddPrefix.assign(n/2+1, 0ll);
        evenPrefix.assign(n/2, 0ll);
    }
    for(int i=0; i<n; i++) {
        if(i%2==0) {
            cin>>odd[i/2];
        }else {
            cin>>even[i/2];
        }
    }
    oddPrefix[0] = odd[0];
    evenPrefix[0] = even[0];
    for(int i=1; i<oddPrefix.size(); i++) {
        oddPrefix[i] = oddPrefix[i-1] + odd[i];
    }
    for(int i=1; i<evenPrefix.size(); i++) {
        evenPrefix[i] = evenPrefix[i-1] + even[i];
    }

    ll ans = LLONG_MAX;
    ll oddAns = LLONG_MAX, evenAns = LLONG_MAX;

    for(int k=1; k<=n; k++) {
        int oddIdx = (k+1)/2;
        int evenIdx = k/2;

        if(k%2==1) oddAns = min(oddAns, odd[oddIdx-1]);
        else evenAns = min(evenAns, even[evenIdx-1]);

        if(k < 2) continue;

        ll cur = oddPrefix[oddIdx-1] - oddAns + oddAns * (ll)(n - oddIdx + 1)
               + evenPrefix[evenIdx-1] - evenAns + evenAns * (ll)(n - evenIdx + 1);
        ans = min(ans, cur);
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