#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 300005;

// 정답을 저장할 배열
int ans[MAXN];
// 세그먼트 트리: 해당 구간의 모든 기사가 패배했는지 여부를 저장
bool tree[MAXN * 4];

// 세그먼트 트리 업데이트 함수
void update(int node, int start, int end, int l, int r, int winner) {
    if (tree[node]) return;
    if (start > r || end < l) return;
    
    // 3. 리프 노드(기사 1명)에 도달한 경우
    if (start == end) {
        ans[start] = winner; // 승자 기록
        tree[node] = true;   // 패배 처리
        return;
    }
    
    int mid = (start + end) / 2;
    // 왼쪽 자식과 오른쪽 자식 탐색
    update(node * 2, start, mid, l, r, winner);
    update(node * 2 + 1, mid + 1, end, l, r, winner);
    
    // 자식 노드들이 모두 패배 처리되었다면 부모 노드도 패배 처리
    tree[node] = tree[node * 2] && tree[node * 2 + 1];
}

int main() {
    // 빠른 입출력을 위한 설정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    for (int i = 0; i < m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;

        // 승자인 x를 제외하고 왼쪽 구간과 오른쪽 구간을 각각 업데이트
        update(1, 1, n, l, x - 1, x);
        update(1, 1, n, x + 1, r, x);
    }
    
    // 결과 출력
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << "\n";
    
    return 0;
}