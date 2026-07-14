#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n, q;
vector<int> seg;


void init(vector<int> &seg, int node, int l, int r) {
    if(l==r) {
        seg[l] = 0;
        return;
    }
    else {
        int mid = (l+r)/2;
        init(seg, 2*node, l, mid);
        init(seg, 2*node+1, mid+1, r);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

int segSum(vector<int> &seg, int node, int start, int end, int l, int r) {
    if(l>=start || end>=r) {
        return 0;
    }else if(start == end) {
        return seg[start];
    }else {
        int mid = (start+end)/2;
        return segSum(seg, 2*node, start, mid, l, r) + segSum(seg, 2*node+1,mid+1, end, l, r);
    }
}


void solve() {
    cin>>n>>q;
    string s;
    cin>>s;
    seg.assign(4*n+1, 0);
    for(int i=0; i<q; i++) {
        int l, r, k;
        cin>>l>>r>>k;
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