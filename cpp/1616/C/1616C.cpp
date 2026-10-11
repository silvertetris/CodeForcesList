#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n;
vector<float> a;
void solve() {
    cin>>n;
    a.assign(n, 0);
    for(int i=0 ; i<n;i ++) {
        cin>>a[i];
    }
    if(n<=2) {
        cout<<"0\n";
        return;
    }

    int ans = INT32_MAX;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            int temp = 0;
            for(int k=0; k<n; k++) {
                //(a[j] - a[i]) / (j-i) == (a[k] - a[i])/(k-i)
                if((a[j]-a[i]) * (k-i) != (a[k]-a[i])*(j-i)) {
                    temp++;
                }
            }
            ans = min(ans, temp);
        }
    }
    cout<<ans<<"\n";
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