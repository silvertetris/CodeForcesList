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
        vector<ll> a(n);

        for( int i=0; i<n; i++) {
            cin>>a[i];
        }
        int res =0;
        for(int i=n-1; i>=0; i--) {
            if(a[i]>0) {
                if(i+1<=n-1 && a[i]+a[i+1]>a[i]) {
                    a[i] += a[i+1];
                }
                res++;
            }
            else {
                if(i+1<=n-1 && a[i]+a[i+1]>0) {
                    a[i] +=a[i+1];
                    res++;
                }
            }
        }
        cout<<res<<"\n";
    }
}