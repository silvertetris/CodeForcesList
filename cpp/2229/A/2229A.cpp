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
        int temp=0;
        vector<int> a(n);
        vector<bool> visited(1001);
        int cnt =0;
        for(int i=0; i<n; i++) {
            cin>>a[i];
            if(!visited[a[i]]) {
                cnt++;
                temp+=a[i];
                visited[a[i]]=true;
            }
        }
        sort(a.begin(), a.end());
        cout<<(a[n-1]-a[0]+1)/2<<"\n";
    }
}