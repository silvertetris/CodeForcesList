#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<char> stk;
    bool flag = false;
    //101 0000 1000001 101101 -> 1
    int cnt = 0;
    for(int i=1; i<n; i++) {
        if(s[i-1]!=s[i]) {
            flag = true;
            cnt++;
        }
    }

    if(flag&& cnt==1) {
        cout<<"2\n";
    }else {
        cout<<"1\n";
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