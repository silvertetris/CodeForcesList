#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--) { 
        int n;
        cin>>n;
        vector<ll> a(n);
        vector<ll> sufmin(n);
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        ll res =0;
        sufmin[n-1] = a[n-1];
        for(auto i=n-2; i>=0; i--) {
            sufmin[i] = min(sufmin[i+1], a[i]);
            res+=(a[i]-sufmin[i]);
        }

        vector<int> indices (n+1, -1);
        for(int i=0; i<n; i++) {
            if(indices[sufmin[i]] == -1) {
                indices[sufmin[i]] = i;
            }
        }
        ll temp =0;

        for(int i=0; i<n; i++) {
            if(a[i]==sufmin[i]) {
                temp = max(temp, (ll)i-indices[sufmin[i]]);
            }
        }
        res+=temp;
        cout<<res<<"\n";
    }
}