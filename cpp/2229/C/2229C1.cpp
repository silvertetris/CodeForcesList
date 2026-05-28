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
        bool flag = false;
        int cnt = 0;
        vector<int> res;
        /*
        양수 나오고 음수 나오면 또 바꿔야함
        양수 양수면 안바꿈
        */
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (!flag && a[i] > 0)
            {
                flag = true;
                res.push_back(i + 1);
                cnt++;
            }
            else if (flag && a[i] > 0)
            {
                continue;
            }
            else if (flag && a[i] < 0)
            {
                res.push_back(i + 1);
                cnt++;
                flag = false;
            }
            else
            {
                continue;
            }
        }
        cout << cnt << "\n";
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}