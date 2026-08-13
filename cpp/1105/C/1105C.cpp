#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, l, r;
    cin >> n >> l >> r;

    long long cnt[3] = {0, 0, 0};
    int temp = r - l;
    cnt[0] = temp/3;
    cnt[1] = temp/3;
    cnt[2] = temp/3;
    for(int i=l+(temp/3)*3; i<=r; i++) {
        cnt[i%3]++;
    }
    // dp[i][j] = 앞에서 i개를 채웠을 때 합이 mod 3 == j 인 경우의 수
    vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {        // 이전 합의 나머지
            for (int k = 0; k < 3; k++) {    // 새로 더하는 수의 나머지
                dp[i][(j + k) % 3] = (dp[i][(j + k) % 3] + dp[i - 1][j] * cnt[k]) % MOD;
            }
        }
    }

    cout << dp[n][0] << "\n";
}