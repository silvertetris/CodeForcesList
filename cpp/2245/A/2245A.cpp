#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n / 2 < k)
    {
        cout << "-1\n";
        return;
    }
    else
    {
        int l = 0;
        int r = 0;
        int ans = 0;
        for (int i = n-1; i >= 0; i--)
        {
            if (s[i] == 'L')
            {
                l++;
            }else {
                l++;
                ans++;
            }
            if (l == k)
            {
                break;
            }
        }
        for(int i=0; i<n; i++) {
            if(s[i]=='R') {
                r++;
            }else {
                r++;
                ans++;
            }
            if(r==k) {
                break;
            }
        }
        cout<<ans<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}