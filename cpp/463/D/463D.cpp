#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;//길이, 행 수
    cin >> n >> k;
    vector<vector<int> > arr(k, vector<int>(n, 0));
    vector<vector<int> > pos(k, vector<int>(n+1, 0));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            pos[i][arr[i][j]] = j; //i줄에서 1..n까지 값들이 j 인덱스에 있다
        }
    }
    /*
     #1. states/ subproblems
     dp[i] = the last element in the common subsequence -> 결국 마지막 공통 요소가 최대 LCS임
     */

    //#2. Base Cases -> 자기 자신의 길이는 1
    vector<int> dp(n, 1);
    int ans = 1;
    //#3. transition
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            bool flag = true;
            for (int p = 0; p < k; p++) {
                if (pos[p][arr[0][j]] > pos[p][arr[0][i]]) { //인덱스들이 당연 인덱스가 앞에 있어야함 (2차원 인덱스에 값 고정) -> 모든 동일 값들이 제일큰 i인덱스보다 앞에 있어야함
                    //하나라도 있다면 그건 공통이 아님으로 false
                    flag = false;
                }
            }
            if (flag) { //만약 조건이 일치하다면 길이 하나 증가 or 그 동안 dp[i]
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        //#4. final answer
        ans = max(dp[i], ans);
    }
    cout<<ans;
}
