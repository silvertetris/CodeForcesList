#include <bits/stdc++.h>

#define ll long long
#define ld long double

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
        vector<int> w(n);
        for(int i=0; i<n; i++) {
            cin>>w[i];
        }
        int cnt =0;
        int one =0;
        int two =0;
        for(int i=0; i<n; i++) {
            if(w[i] == 0 || w[i] == 3) {
                cnt++;
                continue;
            }
            if(w[i]==1) {
                one++;
            }
            if(w[i]==2) {
                two++;
            }
        }
        if(one>=two) {
            cnt+=two;
            one-=two;
            cnt+=one/3;
        }else {
            cnt+=one;
            two-=one;
            cnt+=two/3;
        }
        cout<<cnt<<"\n";
    }
}