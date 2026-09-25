#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

int n, q;
vector<int> a;
void solve() {
    cin>>n>>q;
    a.assign(n, 0);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    vector<int> ans;
    ans.push_back(a[n-1] - a[0]);

    while(true) {
        vector<int> excluded;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                excluded.push_back(a[i]^a[j]);
            }
        }
        sort(excluded.begin(), excluded.end());

        vector<int> temp(excluded.begin(), excluded.begin()+n);
        if(temp==a) {
            break;
        }
        a=temp;
        ans.push_back(a[n-1] - a[0]);
    }

    for(int i=0; i<q; i++) {
        int x;
        cin>>x;
        if(x>=ans.size()) {
            cout<<ans[ans.size()-1]<<"\n";
        }else {
            cout<<ans[x]<<"\n";
        }
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