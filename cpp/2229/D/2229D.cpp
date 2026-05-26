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
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        /*
        max(min(a1, b1)) -> 최소것들의 최대 -> 이분탐색
        최대화 시키는 것 -> diff = one - zero
        diff 최대화 방법: 1의 개수가 최대화 -> 탐색하는 4개가 다 1이여야함.
        */
        int l = 0;
        int r = 1e6 * 2;
        while (l <= r)
        {
            int mid = (l + r) / 2; // m
            int prev = -1;
            int zero = 0;
            int one = 0;
            // 경우는 3개, --, ++, -+ 0, 2, 1
            for (int i = 0; i < n; i++)
            {
                int type = 0;
                if (a[i] >= mid)
                {
                    type++;
                }
                if (b[i] >= mid)
                {
                    type++;
                }

                if (type == 0)
                { // 남는게 --
                    if (prev != 0)
                    {
                        zero++;
                        prev = 0;
                    }
                }
                else if (type == 1)
                { // 남는게 -+
                    continue;
                }
                else
                { // 남는게 ++
                    one++;
                    prev = 1;
                }
            }
            if (one > zero)
            { // 1이 더많아야하니까, m값을 내려야함
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << l-1 << "\n";
    }
}