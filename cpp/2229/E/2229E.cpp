#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 뒤에서부터의 누적합 (L보다 큰 원소들의 합을 O(1)에 구하기 위함)
    vector<long long> suf(n + 2, 0);
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + a[i];
    }

    // dp[i][p]: 1~i까지 고려, 우측 연산 횟수의 기우성이 p일 때의 최대 합
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = 0;

    for (int i = 1; i <= n; i++) {
        // p = 0 (우측 연산 짝수번)
        long long option0_c0 = dp[i - 1][0] + a[i];   // 현재 연산 X -> 최종 부호 그대로 (+), 왼쪽 상태 p=0
        long long option0_c1 = dp[i - 1][1] - a[i];   // 현재 연산 O -> 최종 부호 반대 (-), 왼쪽 상태 p=1
        dp[i][0] = max(option0_c0, option0_c1);

        // p = 1 (우측 연산 홀수번)
        long long option1_c0 = dp[i - 1][1] - a[i];   // 현재 연산 X -> 최종 부호 반대 (-), 왼쪽 상태 p=1
        long long option1_c1 = dp[i - 1][0] + a[i];   // 현재 연산 O -> 최종 부호 그대로 (+), 왼쪽 상태 p=0
        dp[i][1] = max(option1_c0, option1_c1);
    }

    // 1. 연산을 아예 안 하는 경우 (기본 배열의 합)로 초기화
    long long max_sum = suf[1];
    int best_L = 0;

    // 2. 가장 오른쪽에 올 연산 L을 고르며 최댓값 탐색
    for (int L = 1; L <= n; L++) {
        if (a[L] > 0) { // L번째 원소는 양수여야만 가장 마지막 연산으로 작동 가능
            // L 이후는 연산 X (suf[L+1]), L 자체는 1번 뒤집힘 (-a[L]), 1~L-1은 우측 연산이 1번(L)이므로 dp[L-1][1]
            long long current_sum = dp[L - 1][1] - a[L] + suf[L+1];
            if (current_sum > max_sum) {
                max_sum = current_sum;
                best_L = L;
            }
        }
    }

    // 역추적하여 실제로 집합 S에 포함될 인덱스들을 구함
    vector<bool> in_S(n + 1, false);
    if (best_L > 0) {
        in_S[best_L] = true;
        int p = 1; // L 하나가 오른쪽에 있으므로 기우성은 1(홀수)로 시작
        for (int i = best_L - 1; i >= 1; i--) {
            long long val0 = dp[i - 1][p] + (p == 0 ? a[i] : -a[i]);
            if (dp[i][p] == val0) {
                // c_i = 0 이 최적이었음
            } else {
                // c_i = 1 이 최적이었음
                in_S[i] = true;
                p ^= 1; // 연산을 추가했으므로 왼쪽 입장에서는 기우성이 바뀜
            }
        }
    }

    // 구조적 성질을 이용해 올바른 연산 수행 순서(Schedule) 생성
    // 큰 인덱스부터 보면서, 원래 양수면 맨 앞에 배치, 원래 음수면 첫 번째 연산 바로 뒤에 배치
    list<int> sched;
    for (int i = n; i >= 1; i--) {
        if (in_S[i]) {
            if (sched.empty()) {
                sched.push_back(i);
            } else {
                if (a[i] > 0) {
                    sched.push_front(i);
                } else {
                    auto it = sched.begin();
                    it++;
                    sched.insert(it, i);
                }
            }
        }
    }

    // 정답 출력
    cout << sched.size() << "\n";
    for (int x : sched) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}