#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, l, r;
    cin >> n >> l >> r;

    // cnt[j] = [l, r] 안에서 x % 3 == j 인 x의 개수
    long long cnt[3] = {0, 0, 0};
    for (int j = 0; j < 3; j++) {
        // l 이상이면서 나머지가 j인 첫 번째 수 찾기
        long long first = l + ((j - l % 3) + 3) % 3;
        if (first <= r) {
            cnt[j] = (r - first) / 3 + 1;
        }
    }

    // dp[i][j] = 앞에서 i개를 채웠을 때 합이 mod 3 == j 인 경우의 수
    vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));
    dp[0][0] = 1;  // 0개 선택했을 때 합은 0

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {        // 이전 합의 나머지
            for (int k = 0; k < 3; k++) {    // 새로 더하는 수의 나머지
                dp[i][(j + k) % 3] = (dp[i][(j + k) % 3] + dp[i - 1][j] * cnt[k]) % MOD;
            }
        }
    }

    cout << dp[n][0] << "\n";
    return 0;
}