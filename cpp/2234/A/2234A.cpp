#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        vector<int> b(n);
        for(int i=0; i<n; i++) {
            cin>>b[i];
        }
        sort(b.begin(), b.end(), greater<int>());
        bool flag = true;
        for(int i=2; i<n; i++) {
            int x = b[i-2];
            int y = b[i-1];
            int k = b[i];
            if(x%y!=k) {
                flag = false;
                break;
            }
        }

        if(flag) {
            cout<<b[0]<<" "<<b[1]<<"\n";
        }
        else {
            cout<<-1<<"\n";
        }
    }
}