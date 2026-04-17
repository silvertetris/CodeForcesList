#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=0;
    cin>>t;
    while(t--) {
        int n=0;
        cin>>n;
        vector<int> a;
        for(int i=0; i<n; i++) {
            int input =0;
            cin>>input;
            a.push_back(input);
        }
        sort(a.begin(), a.end());
        int cnt=1;
        for(int i=n-2; i>=0; i--) {
            if(a[i]==a[i+1]) {
                cnt++;
            } else {
                break;
            }
        }
        cout<<cnt<<"\n";
    }
}