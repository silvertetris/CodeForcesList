#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int w, h, n; //x, y, trial
    cin>>w>>h>>n;
    vector<bool> height(h+1, false);
    vector<bool> weight(w+1, false);
    for(int i=0; i<n; i++) {
        char op;
        cin>>op;
        int num;
        cin>>num;
        if(op=='H') {
            height[num] = true;
        } else {
            weight[num] = true;
        }
        
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t=1;

    while(t--) {
        solve();
    }
}