#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve()
{
    int n;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        char a = s[i];
        char b = s[n - 1 - i];
        if (a != b) {
            if (a == c || b == c) ans += 1;
            else ans += 2;
        }
    }
    cout << ans << "\n";
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