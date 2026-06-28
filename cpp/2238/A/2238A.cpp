#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int n,c;
    cin>>n>>c;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    for(int i=0; i<n; i++) {
        cin>>b[i];
    }
    vector<int> sortedA = a;
    vector<int> sortedB = b;
    sort(sortedA.begin(), sortedA.end());
    sort(sortedB.begin(), sortedB.end());
    for(int i=0; i<n; i++) {
        if(sortedA[i]<sortedB[i]) {
            cout<<"-1\n";
            return;
        }
    }
    int cost = c;
    for(int i=0; i<n; i++) {
        cost += sortedA[i] - sortedB[i];
    }

    int res = INT16_MAX;
    bool flag = false;
    for(int i=0; i<n; i++) {
        if(a[i]<b[i]) {
            flag = true;
            break;
        }
    }
    if(!flag) {
        res = 0;
        for(int i=0; i<n; i++) {
            res+=a[i] - b[i];
        }
    }
    cout<<min(res, cost)<<"\n";
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