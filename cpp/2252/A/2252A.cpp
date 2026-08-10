#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> cnt(1001, 0);
    for(int i=0; i<n; i++) {
        int input;
        cin>>input;
        a[i] = input;
        cnt[input]++;
    }
    int maxx = 0;
    int cost = 0;
    for(int i=0; i<=1000; i++) {
        if(maxx<cnt[i]) {
            cost = i;
            maxx = cnt[i];
        }
    }
    int temp = n- maxx;
    int res = 0;
    if(maxx>temp+2) {
        for(int i=0; i<n; i++) {
            if(a[i]==cost) {
                continue;
            } else {
                res+=a[i];
            }
        }
        res+=cost *(temp+2);
    }
    else {
        for(int i=0; i<n; i++) {
            res+=a[i];
        }
    }
    cout<<res<<"\n";
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