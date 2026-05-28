#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        string l, r;
        cin>>l>>r;
        int cnt =0;
        bool flag = false; //작은거 숫자 하나 만족하면 근데 abs1이 계속 만족되면 안됨
        /*
        12200
        12199
        */
        for(int i=0; i<l.size(); i++) {
            if(!flag && l[i]==r[i]) {
                cnt+=2;
            }else if(!flag && r[i]-l[i]==1) {
                cnt++;
                flag = true;
            } else if(flag && l[i]=='9' && r[i]=='0') {
                cnt++;
            } else {
                break;
            }

        }
        cout<<cnt<<'\n';
    }
}