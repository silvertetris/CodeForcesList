#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    string x;
    cin>>x;
    int temp = x.size();
    string y ="1";
    for(int i=0; i<temp-1; i++) {
        y+='0';
    }
    y+='1';
    cout<<y<<"\n";
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