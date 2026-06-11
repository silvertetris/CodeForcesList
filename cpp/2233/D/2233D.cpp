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
        auto b = a;

        vector<vector<int>> blocks(n);

        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        for (int i = 0; i < n; i++)
        {
            a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        }

        vector<int> cntb(n);

        for (int i = 0; i < n;)
        {
            int j = i;
            while (i < n && a[i] == a[j])
            {
                i++;
            }
            blocks[a[j]].push_back(j - 1);
            blocks[a[j]].push_back(j);
            blocks[a[j]].push_back(i);
            blocks[a[j]].push_back(i - 1);
            cntb[a[j]]++;
        }

        auto check = [&](int x, int y)
        {
            if (x < 0 || x >= n || y < 0 || y >= n)
            {
                return 0;
            }
            swap(a[x], a[y]);
            vector<int> cnt(n);
            for (int i = 0; i < n;)
            {
                int j = i;
                while (i < n && a[i] == a[j])
                {
                    i++;
                }
                cnt[a[j]]++;
            }
            swap(a[x], a[y]);
            for (int i = 0; i < n; i++)
            {
                if (cnt[i] > 1)
                {
                    return 0;
                }
            }
            return 1;
        };
        bool flag = true; // 기본 상태를 true로 시작
        for (int i = 0; i < n; i++)
        {
            if (cntb[i] > 1)
            {
                if (cntb[i] > 3)
                {
                    flag = false; // 불가능하므로 false 처리
                    break;
                }
                blocks[i].erase(unique(blocks[i].begin(), blocks[i].end()), blocks[i].end());
                bool can_swap = false;
                for (int x : blocks[i])
                {
                    for (int y : blocks[i])
                    {
                        if (x < y)
                        {
                            if (check(x, y))
                            {
                                can_swap = true;
                                break;
                            }
                        }
                    }
                    if (can_swap)
                    {
                        break;
                    }
                }
                if (!can_swap)
                { // 이번 i에서 swap을 못 찾았다면 전체 실패
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}