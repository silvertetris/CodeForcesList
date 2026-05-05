#include <bits/stdc++.h>

#define ll long long

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
        if(n%2==0) {
            cout<<-1<<"\n";
        }
        else {
            for(int i=1; i<=n; i+=2) {
                cout<<i<<" ";
            }
            for(int i=2; i<=n; i+=2) {
                cout<<i<<" ";
            }
            cout<<"\n";
        }
    }
}