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
        vector<int> a(n);
        for(auto i=0; i<n; i++) {
            int input;
            cin>>input;
            a.push_back(input);
        }
        vector<int> b = a;
        sort(b.begin(), b.end());
        if(a==b) {
            cout<<n<<"\n";
        } else {
            cout<<1<<"\n";
        }
    }
}