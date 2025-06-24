#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<vector<int> > arr(k, vector<int>(n, 0));
    vector<vector<int> > pos(k, vector<int>(n+1, 0));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            pos[i][arr[i][j]] = j;
        }
    }
    /*
     #1. states/ subproblems
     dp[i] = the last element in the common subsequence
     */

    //#2. Base Cases -> 자기 자신의 길이는 1
    vector<int> dp(n, 1);
    int ans = 1;
    //#3. transition
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            bool flag = true;
            for (int p = 0; p < k; p++) {
                if (pos[p][arr[0][j]] > pos[p][arr[0][i]]) {
                    flag = false;
                }
            }
            if (flag) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        //#4. final answer
        ans = max(dp[i], ans);
    }
    cout<<ans;
}
