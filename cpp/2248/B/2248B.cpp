#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    for(int i=0; i<m; i++) {
        cin>>b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(n<2*m) {
        cout<<"NO\n";
        return;
    }
    int idx = 0;
    int last = n-1;
    //그니까 m건너띈곳이 아니지 사이즈가 다르니까, n에서 m만큼 뺀거?가 제일 정배 어차피 2*m constraints 있음
    for(int i=0; i<m; i++) {
        int cur = n-m+i;
        if(a[i]>b[i] || a[cur]<b[i]) {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    
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