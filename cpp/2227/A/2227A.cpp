#include <bits/stdc++.h>

using namespace std;

#define long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--) {
        int x, y;
        cin>>x>>y;
        if(x%2!=0 && y%2!=0) {
            cout<<"NO\n";
        } else {
            cout<<"YES\n";
        }
    }
}