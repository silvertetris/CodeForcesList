#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll inf = 3e17;
ll po[19]; // 자리수용 1, 10, 100, 1000... 를 저장함 최대 10^18까지

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
    vector<int> v; // 자리수 배열
    ll x = a;
    if (a == 0)
        v.push_back(0);
    while (x > 0)
    {
        v.push_back(x % 10);
        x /= 10;
    }
    int m = v.size();
    v.push_back(0);
    reverse(v.begin(), v.end()); // 원래 수 배열로 만듦 , msb -> lsb

    /*
    #1. states/subproblems
    dp[i][j] = msb 에서 lsb까지 (i), 만든 둘의 차이 최솟값
    dp[i][0] = b의 prefix == a의 prefix
    dp[i][1] = b>a로 확장
    dp[i][2] = b<a로 확장
    dp[i][3] = leading zero 자리에 머무를 때 (b의 자리수가 a보다 길어질 가능성 보유) -> 그니까 숫자가 00000000 이상태로 가다가 뭐 마지막에 123 이 나올 수 있는거임
    */
    vector<vector<ll>> dp(m + 1, vector<ll>(4, inf));
    dp[0][0] = 0; // leading zero -> 0
    dp[0][3] = 0; // leading zero -> 0

    // #2. Base Cases
    if (m < 18)
    {
        if (d[0] != 0) // 0이 아니면 제일 작으니까 1에 넣기 -> 자리수 확장이니까 b>a는 자명함
        {
            dp[0][1] = po[m] * d[0];
        }
        else if (n > 1) // 0이 아닌놈 b>a에 대한 base cases
        {
            dp[0][1] = po[m] * d[1];
        }
    }

    // #3. transitions
    for (int i = 0; i < m; i++)
    {
        for (int all = 0; all < 4; all++)
        {
            ll sz = po[m - i - 1];//자리 승

            for (int j = 0; j < n; j++)
            {
                int cur_d = d[j];
                if (all == 3 && i == 0)
                    continue;

                ll e = dp[i][all];
                if (e >= inf)
                    continue;

                int uj = all;
                if (all == 0)//어디로든 전파 가능
                {
                    if (cur_d > v[i + 1])//d[j]가 더 크면 현재 자리수보다 , b>a로 확장
                        uj = 1;
                    else if (cur_d < v[i + 1])
                        uj = 2;
                    e += sz * abs(cur_d - v[i + 1]);
                }
                else if (all == 1)
                {
                    e += sz * (cur_d - v[i + 1]);
                }
                else if (all == 2)
                {
                    e += sz * (v[i + 1] - cur_d);
                }
                else if (all == 3)//만약 leading zero 자리수에 계속 잔존하면, 무조건 b<a로 새로만드는애가 작음
                {
                    uj = 2;
                    e += sz * (v[i + 1] - cur_d);
                }

                dp[i + 1][uj] = min(dp[i + 1][uj], e);
            }
            if (all == 3)
            {
                dp[i + 1][all] = min(dp[i + 1][all], dp[i][all] + (sz * v[i + 1]));//그냥 leading zero로 이어온 잔존 값 전이
            }
        }
    }

    //#4. final answer
    ll ans = min({dp[m][0], dp[m][1], dp[m][2]});
    cout << ans << "\n";
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    po[0] = 1;
    for (int i = 1; i < 19; i++)
    {
        po[i] = po[i - 1] * 10LL;
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}