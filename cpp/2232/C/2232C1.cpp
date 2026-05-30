#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
/*
x테이블이 있고, s자리들이 있음

I: 빈 테이블에 앉아야함
E: 비지 않은 테이블에 앉아야함
A: 아무곳이나 ㄱㄴ

초기 자리는 다 비어있음
각 라인에 앉히거나 쫓아내거나
각 사람은 다음사람 할당전에 앉음
가능한한 많은 사람
최대 자리에 앉은 사람 수

빈테이블 수 + 이미 차지한 테이블 수

dp[i] = 한명이라도 차지한 테이블 개수
dp[i] = 

*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int INF = INT32_MIN;
    int t;
    cin >> t;
    while (t--) {
        int n, x, s;
        string u;
        cin >> n >> x >> s >> u;
        /*
        #1. states/problems
        dp[i] = E가능 테이블 개수 i일때 앉은 사람 최대 수


        dp[i][j] : i indices, 남은 확장된 테이블 수

        1. I고 빈자리 있으면
        새테이블 파거나 못파거나 -> x 제한보다 미만이여야함
        2. E고 
        기존 있는곳 앉거나 안앉거나 -> 수용가능한 애들까지 x*s
        A가 문제인데
        얘는 새테이블을 파거나 안파거나
        그냥 기존에 있는놈곳에 앉거나 안앉거나
        그냥 I, E인 경우 2개 섞어야함

        현재까지 확장된 테이블 x*s
        */
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, INF));
        //#2. 
        dp[0][0] = 0; 
        for (int i = 0; i < n; i++) {
            char cur = u[i];

            for (int j = 0; j <= x; j++) {
                if (dp[i][j] == INF) continue;
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

                if (cur == 'I') {
                    if (j < x) {
                        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
                    }
                } 
                else if (cur == 'E') {
                    if (j > 0 && dp[i][j] < j * s) {
                        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
                    }
                } 
                else if (cur == 'A') {
                    if (j > 0 && dp[i][j] < j * s) {
                        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
                    }
                    if (j < x) {
                        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
                    }
                }
            }
        }

        int ans = *max_element(dp[n].begin(), dp[n].end());
        cout << ans << "\n";
    }
}