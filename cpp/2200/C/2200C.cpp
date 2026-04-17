#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        /*
        1. 모든 char의 개수가 짝수여야함
        2. 지워야하는 대상 사이에 연속된 것이 없으면 안됨
        */
       stack <char> a;
       for(auto i=0; i<n; i++) {
        if(a.size()==0) {
            a.push(s[i]);
        } else if(a.top() == s[i]) {
            a.pop();
        } else {
            a.push(s[i]);
        }
       }
       if(a.size()!=0) {
        cout<<"NO\n";
       } else {
        cout<<"YES\n";
       }
    }

}