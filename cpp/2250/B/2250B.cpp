#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int n, k;
    cin>>n>>k;
    if(n-1 == k) {
        cout<<"-1\n";
        return;
    }
    string result = "";
    if(k%2==0) {
        for(int i=0; i<k/2+1; i++) {
            result+='0';
        }
        for(int i=0; i<k/2+1; i++) {
            result+='1';
        }
        bool flag = false; //0
        for(int i=result.size(); i<n; i++) {
            if(!flag) {
                result+='0';
            }else {
                result+='1';
            }
            flag = !flag;
        }
        cout<<result<<"\n";
    } else {
        for(int i=0; i<k/2+1; i++) {
            result+='0';
        }
        for(int i=0; i<k/2+2; i++) {
            result+='1';
        }
        bool flag = false; //0
        for(int i=result.size(); i<n; i++) {
            if(!flag) {
                result+='0';
            }else {
                result+='1';
            }
            flag = !flag;
        }
        cout<<result<<"\n";
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