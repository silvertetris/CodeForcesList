#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        vector<int> temp;
        for(int i=1; i<=n; i++) {
            temp.push_back(i);
            cout<<i<<" ";
        }   
        for(int i=n-1; i>=0; i--) {
            cout<<temp[i]<<" ";
        }
        for(int i=1; i<n; i++) {
            cout<<temp[i]<<" ";
        }
        cout<<1<<" 1 ";
        for(int i=n-1; i>=1; i--) {
            cout<<temp[i]<<" ";
        }
        cout<<"\n";
    }
}