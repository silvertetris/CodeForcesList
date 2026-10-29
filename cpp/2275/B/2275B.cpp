#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<int> st;
    set<int> ans;
    for(int i=0; i<n; i++) {
        if(s[i]-'0'==3) {
            continue;
        }
        if(s[i]-'0' == 1) {
            st.push(i+1);
        }
        if(s[i]-'0'==2) {
            if(st.empty()) {
                continue;
            }else {
                st.pop();
                ans.emplace(i+1);
            }
        }
    }
    int idx = st.size();
    for(int i=0; i<idx; i++) {
        ans.emplace(st.top());
        st.pop();
    }
    cout<<ans.size()<<"\n";
    for(auto &i : ans) {
        cout<<i<<" ";
    }
    cout<<"\n";
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