#include <bits/stdc++.h>

#define ll long long
using namespace std;
/*
n사이즈 a배열, 정수 k번 연산

각 a_i를 a_i를 제외한 모든 수의 mex값으로 대체
-> 새로운 배열로 만듦 -> 동시에함
이 짓을 k번 후에, 배열의 합


*/
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }
        sort(a.begin(), a.end());
        vector<ll> next(n);
        bool two = false;
        if (a[0] != 0)
        {
            fill(next.begin(), next.end(), 0);
            if (k % 2 == 0)
            {
                cout << n << "\n";
                continue;
            }
            else
            {
                cout << 0 << "\n";
                continue;
            }
        }
        else
        {
            if (a[1] == 0)
            {
                two = true;
            }
            int mex = 0;
            for (int i = 0; i <= n; i++)
            {
                if (!cnt[i])
                {
                    mex = i;
                    break;
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (a[i] > mex)
                {
                    next[i] = mex;
                }
                else if (cnt[a[i]] > 1)
                {
                    next[i] = mex;
                }
                else if (cnt[a[i]] == 1)
                {
                    next[i] = a[i];
                }
            }
        }
        if (two)
        {
            if (k % 2 == 0)
            {
                cout << 0 << "\n";
            }
            else
            {
                if (k == 1)
                {
                    cout << accumulate(next.begin(), next.end(), 0ll) << "\n";
                }
                else
                {
                    cout << n << "\n";
                }
            }
        }
        else
        { // 0이 하나일때
            if (k == 1)
            {
                cout << accumulate(next.begin(), next.end(), 0ll) << "\n";
            }
            else
            {
                vector<ll> temp(n, 0);
                sort(next.begin(), next.end());
                fill(cnt.begin(), cnt.end(), 0);
                int mex = 0;
                for (int i = 0; i < n; i++)
                {
                    cnt[next[i]]++;
                }
                for (int i = 0; i <= n; i++)
                {
                    if (!cnt[i])
                    {
                        mex = i;
                        break;
                    }
                }
                for (int i = 0; i < n; i++)
                {
                    if (next[i] > mex)
                    {
                        temp[i] = mex;
                    }
                    else if (cnt[next[i]] > 1)
                    {
                        temp[i] = mex;
                    }
                    else if (cnt[next[i]] == 1)
                    {
                        temp[i] = next[i];
                    }
                }

                /*
                0 1 1 2
                0 3 3 2
                0 1 1 1
                0 2 2 2
                0 1 1 1
                */
                if (k == 1)
                {
                    cout << accumulate(next.begin(), next.end(), 0ll) << "\n";
                }
                else if (k % 2 == 0)
                {
                    cout << accumulate(temp.begin(), temp.end(), 0ll) << "\n";
                }
                else
                {
                    vector<ll> final(n, 0);
                    sort(temp.begin(), temp.end());
                    fill(cnt.begin(), cnt.end(), 0);
                    int mex = 0;
                    for (int i = 0; i < n; i++)
                    {
                        cnt[temp[i]]++;
                    }
                    for (int i = 0; i <= n; i++)
                    {
                        if (!cnt[i])
                        {
                            mex = i;
                            break;
                        }
                    }
                    for (int i = 0; i < n; i++)
                    {
                        if (temp[i] > mex)
                        {
                            final[i] = mex;
                        }
                        else if (cnt[temp[i]] > 1)
                        {
                            final[i] = mex;
                        }
                        else if (cnt[temp[i]] == 1)
                        {
                            final[i] = temp[i];
                        }
                    }
                    cout<<accumulate(final.begin(), final.end(), 0ll)<<"\n";
                }
            }
        }
    }
}