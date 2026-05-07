#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> res(2 * n);
    int cnt = 1;
    if (n % 2 == 0)
    {
        cout << "NO\n";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            res[i] = cnt++;
            res[i + n] = cnt++;
        }
        else
        {
            res[i + n] = cnt++;
            res[i] = cnt++;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < 2 * n; i++)
    {
        cout << res[i] << " ";
    }
    cout << "\n";
}