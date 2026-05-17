#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll inf = 3e17;
ll po[19];

void solve()
{
    ll a;
    int n; 
    cin >> a >> n;

    vector<int> d(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> d[i];
    }

    // 숫자 a를 자릿수 배열 v로 분해
    vector<int> v;
    ll x = a;
    if (a == 0) v.push_back(0);
    while (x > 0)
    {
        v.push_back(x % 10);
        x /= 10;
    }
    int m = v.size();
    v.push_back(0);
    reverse(v.begin(), v.end());

    // DP 테이블 초기화 (m+1 행, 4열)
    vector<vector<ll>> dp(m + 1, vector<ll>(4, inf));
    dp[0][0] = 0;
    dp[0][3] = 0;

    // 자릿수가 하나 더 길어지는 경우 초기화 (szor 대신 직접 곱셈)
    if (m < 18)
    {
        if (d[0] != 0)
        {
            dp[0][1] = po[m] * d[0];
        }
        else if (n > 1) 
        {
            dp[0][1] = po[m] * d[1];
        }
    }

    // 자릿수 DP 진행
    for (int i = 0; i < m; i++)
    {
        for (int all = 0; all < 4; all++)
        {
            ll sz = po[m - i - 1]; // 현재 자릿수의 가치 (10^k)
            int ert = v[i + 1];    // a의 현재 자릿수 숫자
            
            for (int j = 0; j < n; j++)
            {
                int cur_d = d[j];
                if (all == 3 && i == 0) continue;

                ll e = dp[i][all];
                if (e >= inf) continue;

                int uj = all;
                if (all == 0)
                {
                    if (cur_d > ert) uj = 1;
                    else if (cur_d < ert) uj = 2;
                    e += sz * abs(cur_d - ert);
                }
                else if (all == 1)
                {
                    e += sz * (cur_d - ert);
                }
                else if (all == 2)
                {
                    e += sz * (ert - cur_d);
                }
                else if (all == 3)
                {
                    uj = 2;
                    e += sz * (ert - cur_d);
                }

                dp[i + 1][uj] = min(dp[i + 1][uj], e);
            }
            if (all == 3) 
            {
                dp[i + 1][all] = min(dp[i + 1][all], dp[i][all] + (sz * ert));
            }
        }
    }

    // 최종 최솟값 출력
    ll ans = min({dp[m][0], dp[m][1], dp[m][2]});
    cout << ans << "\n";
}

int main()
{
    // 10의 거듭제곱 배열 미리 계산
    po[0] = 1;
    for (int i = 1; i < 19; i++)
    {
        po[i] = po[i - 1] * 10LL;
    }

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}