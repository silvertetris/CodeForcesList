#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n, x, y;
vector<int> p;
/*
기본 자리에서 원래 자리 차이를
x, y의 합과 차로 만들 수 있는가?

*/
bool check(int x, int y, int p) {
    if(x==0 || y==0) {
        return true;
    }
    int gcdd = gcd(x, y);
    return (p%gcdd==0);
}
void solve() {
    cin>>n>>x>>y;
    p.assign(n+1, 0);
    for(int i=1; i<=n; i++) {
        cin>>p[i];
    }
    int sub = y-x;
    for(int i=1; i<=n; i++) {
        int idx = i;
        int valu = p[i];
        int calc = abs(p[i]-i);
        if(!check(x, y, calc)) {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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