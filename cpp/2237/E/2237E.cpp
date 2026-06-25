#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

int n;

void solve() {
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    vector<bool> visited(n+1, false);
    for(int i=0; i<n; i++) {
        cin>>a[i];
        a[i]--;
    }
    for(int i=0; i<n;i++) {
        cin>>b[i];
        if(b[i]!=-1) {
            b[i]--;
        }
    }
    for(int i=0; i<n; i++) {
        if(b[i]!=-1 && !visited[i]) {
            int j=i;
            while(!visited[j]) {
                visited[j] = true;
                if(b[a[j]] == -1) {
                    b[a[j]] =a[b[j]];
                } else if(b[a[j]]!=a[b[j]]) {
                    cout<<"NO\n";
                    return;
                }
                j = a[j];
            }
        }
    }
    vector<int> cnt(n);
    for(int i=0; i<n;i++) {
        if(b[i]!=-1) {
            cnt[b[i]]++;
        }
    }

    for(int i=0; i<n; i++) {
        if(cnt[i]>1) {
            cout<<"NO\n";
            return;
        }
    }

    vector<bool> visited1(n), visited2(n);
    vector<vector<int>> cycle1(n+1), cycle2(n+1);
    for(int i=0; i<n; i++) {
        if(b[i]==-1 && !visited1[i]) {
            int j=i, len = 0;
            while(!visited1[j]) {
                visited1[j] =true;
                len++;
                j = a[j];
            }
            cycle1[len].push_back(i);
        }
    }
    for(int i=0; i<n; i++) {
        if(cnt[i]==0 && !visited2[i]) {
            int j=i, len = 0;
            while(!visited2[j]) {
                visited2[j] = true;
                len++;
                j = a[j];
            }
            cycle2[len].push_back(i);
        }
    }
    for(int len = 1; len <=n; len++) {
        for(int i=0; i<cycle1[len].size(); i++) {
            int x = cycle1[len][i], y = cycle2[len][i];
            while(b[x]== -1) {
                b[x] = y;
                x = a[x];
                y = a[y];
            }
        }
    }
    cout<<"YES\n";
    for(int i=0; i<n; i++) {
        cout<<b[i]+1<<" ";
    }
    cout<<"\n";
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