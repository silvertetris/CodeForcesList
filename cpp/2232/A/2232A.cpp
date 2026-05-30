#include <bits/stdc++.h>

#define ll long long
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        if (n % 2 == 0)
        {
            int mid1 = a[n / 2 - 1];
            int mid2 = a[n / 2];
            int cnt1 = 0;
            int cnt2 = 0;
            int res = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == mid1)
                {
                    cnt1++;
                }
                if (a[i] == mid2)
                {
                    cnt2++;
                }
            }
            if (cnt1 > cnt2)
            {
                int u = 0;
                int v = 0;
                for (int i = 0; i < n; i++)
                {
                    if (a[i] != mid1)
                    {
                        u++;
                    }
                    else
                    {
                        break;
                    }
                }
                for (int i = n - 1; i >= 0; i--)
                {
                    if (a[i] != mid1)
                    {
                        v++;
                    }
                    else
                    {
                        break;
                    }
                }
                res = max(u, v);
            }
            else
            {
                int u = 0;
                int v = 0;
                for (int i = 0; i < n; i++)
                {
                    if (a[i] != mid2)
                    {
                        u++;
                    }
                    else
                    {
                        break;
                    }
                }
                for (int i = n - 1; i >= 0; i--)
                {
                    if (a[i] != mid2)
                    {
                        v++;
                    }
                    else
                        break;
                }
                res = max(u, v);
            }
            cout << res << "\n";
        }
        else
        {
            int mid = a[n / 2];
            int res = 0;
            int u = 0;
            int v = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] != mid)
                {
                    u++;
                }
                else
                {
                    break;
                }
            }
            for (int i = n - 1; i >= 0; i--)
            {
                if (a[i] != mid)
                {
                    v++;
                }
                else
                {
                    break;
                }
            }
            res = max(u, v);
            cout << res << "\n";
        }
    }
}