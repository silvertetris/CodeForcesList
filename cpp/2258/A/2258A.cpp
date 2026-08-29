#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n;
vector<int> a;
void solve() {
    cin>>n;
    a.assign(n+1, 0);
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }
    int temp = gcd(a[1], a[n]);
    cout<<temp<<"\n";
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