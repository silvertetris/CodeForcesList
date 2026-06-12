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
    vector<int> cnt(k, 0);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            cnt[i % k]++;
        }
    }

    for (int i = 0; i < k; i++)
    {
        if (cnt[i] % 2 != 0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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