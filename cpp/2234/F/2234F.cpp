#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void init(vector<ll> &seg, vector<int>& h, int n) {
    for(int i=0; i<2*n; i++) {
        seg[2*n+i] = h[i%n];
    }
    for(int i=2*n-1; i>=1; i--) {
        if(seg[2*i]>=seg[2*i+1]) {
            seg[i] = seg[2*i];
        }else {
            seg[i] = seg[2*i+1];
        }
    }
}
ll query(vector<ll> &seg, int l, int r, int n) {
    ll res = -1;
    l = l+2*n;
    r = r+2*n+1;

    while(l<r) {
        if(l%2 == 1) {
            res = max(res, seg[l]);
            l++;
        }

        if(r%2==1) {
            r--;
            res = max(res, seg[r]);
        }
        l = l/2;
        r = r/2;
    }
    return res;
}
/*
1. 원형이고
2. 각 인덱스+1이랑 연결된 통로 주어지고
3. 그거 비었을때, 높이가 같음 -> 통로때매
*/
int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        vector<int> h(n);
        for(int i=0; i<n; i++) {
            cin>>h[i];
        }

        vector<ll> seg(4*n, 0);
        /*
        segtree = h[i]가 구간에서 높은놈
        
        */
        init(seg, h, n);
        for(int i=0; i<n; i++) {
            ll res =0;
            for(int j=1; j<n; j++) {
                ll u = query(seg, i, i+j-1, n);
                ll v = query(seg, i+j, i+n-1, n);
                res += min(u, v);
            }
            cout <<res<<" ";
        }
        cout<<"\n";
    }
}