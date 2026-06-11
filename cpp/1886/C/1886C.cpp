#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    string s;
    ll pos;
    cin>>s>>pos;
    pos--;
    int curLen = s.size();
    vector<char> stack;
    bool flag = pos<curLen;
    s+=' ';

    for(auto c:s) {
        while(!flag && stack.size() >0 && stack.back() > c) {
            pos-=curLen;
            curLen--;
            stack.pop_back();

            if(pos<curLen) {
                flag = true;
            }
        }
        stack.push_back(c);
    }
    cout<<stack[pos];
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