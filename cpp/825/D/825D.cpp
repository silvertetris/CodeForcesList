#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    string s, t;
    cin>>s>>t;
    vector<int> cnts(26, 0);
    int qcnt = 0;
    string res = "";
    for(int i=0; i<s.size(); i++) {
        if(s[i]!='?') {
            cnts[s[i]-'a']++;
            res+=s[i];
        }else {
            qcnt++;
        }
    }
    vector<int> cntt(26, 0);
    for(int i=0; i<t.size(); i++) {
        cnts[t[i]-'a']++;
    }
    for(int i=0; i<26; i++) {
        cntt[t[i]] = max(0, cntt[i]-cnts[i]);//t에 있는 애들을 뺌 남은 t만큼 더함
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}