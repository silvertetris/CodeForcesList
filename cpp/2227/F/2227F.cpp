#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> sufmin(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll res = 0;
        int idx = n - 1;
        sufmin[n - 1] = a[n - 1];
        for (auto i = n - 2; i >= 0; i--)
        {
            sufmin[i] = min(sufmin[i + 1], a[i]);
            if (sufmin[i + 1] > sufmin[i])
            {
                idx = i;
                continue;
            }

            else
            {
                res += (idx - i) * (a[i] - sufmin[i]);
            }
        }
        vector<int> indices(n + 1, -1);
        for (int i = 0; i < n; i++)
        {
            if (indices[sufmin[i]] == -1)
            {
                indices[sufmin[i]] = i;
            }
        }
        ll temp = 0;
        vector<int> prefixSum (n);
        prefixSum[0] = sufmin[0];
        for(int i=1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1] + sufmin[i];
        }

        for (int i = 1; i < n; i++)
        {
                temp = max(temp, (ll)(prefixSum[i-1] - ((i-indices[sufmin[i]])*(sufmin[i]-1))));
        }
        res += temp;
        cout << res << "\n";
    }
}