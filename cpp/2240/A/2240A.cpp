#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k; // sum의 최대, 배열 개수
    if (k >= n)
    {
        cout << n << "\n";
        return;
    }
    else
    {
        int temp = n / k; // 목표
        int b = 0;
        while (true)
        {
            if (pow(2, b)-1 > temp)
            {
                b--;
                break;
            }
            else
            {
                b++;
            }
        }
        ll ans = (ll)b * k;
        // 그리고 남은걸 전체에서 빼야함
        ll c = n - (pow(2, b)-1) * k;
        ans += c / (pow(2, b));
        cout << ans << "\n";
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