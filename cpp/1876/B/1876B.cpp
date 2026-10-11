#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
ll INF = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            arr[i] = max(arr[i], a[j]);
        }
    } 
    sort(arr.begin() + 1, arr.end(), greater<int>());
    vector<ll> power(n + 1, 0);
    power[n] = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        power[i] = (power[i + 1] * 2) % INF;
    }
    for (int i = 1; i <= n; i++)
    {
        ans += (power[i] * arr[i]) % INF;
        ans %= INF;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--)
    {
        solve();
    }
}