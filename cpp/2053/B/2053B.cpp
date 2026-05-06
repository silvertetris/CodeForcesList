#include <bits/stdc++.h>

#define ll long long
using namespace std;
/*
n조각의 감상평들
w_i로 기억
근데 l_i <= w_i <= r_i 들만 기억
숫자가 1개로 고정된 애들이 중요함
1개로 고정된 애들을 저장하고
그 애들이 구간안에 모두 포함 되면 끝
*/

void update(vector<int> &seg, int node, int l, int r, int idx) {
    if(l>idx || r<idx) {
        return;
    }
    else if(l == r) {
        seg[node] = 1;
    }
    else {
        int mid = (l+r)/2;
        update(seg, 2*node, l, mid, idx);
        update(seg, 2*node+1, mid+1, r, idx);
        seg[node] = seg[2*node] & seg[2*node+1];
    }
}
bool query(vector<int> &seg, int node, int start, int end, int l, int r) {
    if(start>r || end<l) {
        return 1;
    }
    else if(l<=start && end<=r) {
        return seg[node];
    }
    else {
        int mid = (start+end)/2;
        return query(seg, 2*node, start, mid, l, r) & query(seg, 2*node+1, mid+1, end, l, r);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> l(n);
        vector<int> r(n);
        vector<int> cnt(2*n+1, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> l[i] >> r[i];
            if(l[i] == r[i]) {
                cnt[l[i]]++;
            }
        }

        vector<int> seg(8 * n + 1, 0);
        for(int i=0; i<2*n+1; i++) {
            if(cnt[i]) {
                update(seg, 1, 0, 2*n, i);
            }
        }
        for(int i=0; i<n; i++) {
            if(l[i] == r[i]) {
                if(cnt[l[i]]<=1) {
                    cout<<"1";
                }else {
                    cout<<"0";
                }
            }else {
                bool temp = query(seg, 1, 0, 2*n, l[i], r[i]);
                if(temp) {
                    cout<<"0";
                }else cout<<"1";
            }
        }
        cout<<"\n";
    }
}