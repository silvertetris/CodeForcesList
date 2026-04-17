#include <bits/stdc++.h>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, x, y;
        cin >> n >> x >> y;
        
        vector<int> p(n);
        vector<int> B; // 포털 x와 y 사이의 원소들
        vector<int> S; // 포털 바깥쪽 원소들 (A + C)
        
        for(int i = 0; i < n; i++) {
            cin >> p[i];
            
            // 1. 배열을 B(포털 내부)와 S(포털 외부)로 정확히 분리합니다.
            if (i >= x && i < y) {
                B.push_back(p[i]);
            } else {
                S.push_back(p[i]);
            }
        }
        
        vector<int> B_min;
        // 2. B 구간에서 가장 작은 값을 찾아, 그 값을 시작으로 하는 최소 사전순 배열을 만듭니다.
        // 모든 원소가 고유하므로(순열), 최솟값에서 시작하도록 회전시키기만 하면 됩니다.
        if (!B.empty()) {
            auto min_it = min_element(B.begin(), B.end());
            B_min.insert(B_min.end(), min_it, B.end());
            B_min.insert(B_min.end(), B.begin(), min_it);
        }
        
        vector<int> ans;
        int split_idx = 0;
        
        // 3. S(포털 외부 원소) 사이에 B_min을 넣을 최적의 위치를 찾습니다.
        // S의 원소가 B_min의 첫 번째 원소보다 작을 때까지만 S를 먼저 배치합니다.
        if (!B_min.empty()) {
            while (split_idx < S.size() && S[split_idx] < B_min[0]) {
                ans.push_back(S[split_idx]);
                split_idx++;
            }
            
            // S의 원소가 더 커지는 순간, B_min 전체를 통째로 삽입합니다.
            ans.insert(ans.end(), B_min.begin(), B_min.end());
        }
        
        // 4. B_min 삽입이 끝난 후, S의 남은 뒷부분 원소들을 마저 넣어줍니다.
        while (split_idx < S.size()) {
            ans.push_back(S[split_idx]);
            split_idx++;
        }
        
        // 결과 출력
        for(int i = 0; i < n; i++) {
            cout << ans[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
    
    return 0;
}