#include <bits/stdc++.h>
#define ld long double
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        vector<int> r(m);
        vector<int> p(m);
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        for(int i=0; i<m; i++) {
            cin>>r[i]>>p[i];
        }
        
    }
}