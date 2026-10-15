#include <bits/stdc++.h>
using namespace std;

// 26개의 알파벳 각각에 대해 트리와 레이지 배열을 벡터로 선언
vector<vector<int>> tree;
vector<vector<int>> lazy;

// 1. 트리 초기화 (O(N)만에 26개 트리를 한 번에 구축)
void init(int node, int start, int end, const string& s) {
    if (start == end) {
        int char_idx = s[start] - 'a';
        tree[char_idx][node] = 1; // 해당 알파벳 트리에만 1을 표시
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid, s);
    init(node * 2 + 1, mid + 1, end, s);
    
    // 자식 노드들을 다 세팅하고 올라오면서 26개 트리의 합을 모두 갱신
    for (int i = 0; i < 26; i++) {
        tree[i][node] = tree[i][node * 2] + tree[i][node * 2 + 1];
    }
}

// 트리에 덮어씌우기 작업 전파
void propagate(int id, int node, int start, int end) {
    if (lazy[id][node] != -1) {
        tree[id][node] = lazy[id][node] * (end - start + 1);
        if (start != end) {
            lazy[id][node * 2] = lazy[id][node];
            lazy[id][node * 2 + 1] = lazy[id][node];
        }
        lazy[id][node] = -1;
    }
}

// 구간 덮어씌우기 (val은 0 또는 1)
void update_range(int id, int node, int start, int end, int left, int right, int val) {
    propagate(id, node, start, end);
    if (left > end || right < start) return;
    if (left <= start && end <= right) {
        lazy[id][node] = val;
        propagate(id, node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update_range(id, node * 2, start, mid, left, right, val);
    update_range(id, node * 2 + 1, mid + 1, end, left, right, val);
    tree[id][node] = tree[id][node * 2] + tree[id][node * 2 + 1];
}

// 구간 내 특정 알파벳 개수 구하기
int query(int id, int node, int start, int end, int left, int right) {
    propagate(id, node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[id][node];
    int mid = (start + end) / 2;
    return query(id, node * 2, start, mid, left, right) + query(id, node * 2 + 1, mid + 1, end, left, right);
}

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;
    
    string s;
    cin >> s;

    // n 크기에 맞춰서 트리의 적절한 크기(4*n)를 구함
    int tree_size = 4 * n;

    // 26개의 알파벳에 대해 트리와 lazy 배열을 할당 및 초기화
    // tree는 0으로, lazy는 -1(밀린 작업 없음)로 초기화
    tree.assign(26, vector<int>(tree_size, 0));
    lazy.assign(26, vector<int>(tree_size, -1));

    // N번의 update_range 대신 단 1번의 init 호출로 초기화 끝
    init(1, 0, n - 1, s);

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--; // 0-based 인덱스 변환

        // 1. 해당 구간의 각 알파벳 개수 세기
        int cnt[26] = {0};
        for (int i = 0; i < 26; i++) {
            cnt[i] = query(i, 1, 0, n - 1, l, r);
        }

        // 2. 해당 구간의 모든 알파벳 지우기 (0으로 덮어씌움)
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                update_range(i, 1, 0, n - 1, l, r, 0);
            }
        }

        // 3. 개수만큼 정렬 방향에 맞게 다시 칠하기 (1로 덮어씌움)
        int curr = l;
        if (k == 1) { 
            // 오름차순: 'a'부터 'z'까지
            for (int i = 0; i < 26; i++) {
                if (cnt[i] > 0) {
                    update_range(i, 1, 0, n - 1, curr, curr + cnt[i] - 1, 1);
                    curr += cnt[i];
                }
            }
        } else { 
            // 내림차순: 'z'부터 'a'까지
            for (int i = 25; i >= 0; i--) {
                if (cnt[i] > 0) {
                    update_range(i, 1, 0, n - 1, curr, curr + cnt[i] - 1, 1);
                    curr += cnt[i];
                }
            }
        }
    }

    // 4. 최종 문자열 출력하기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (query(j, 1, 0, n - 1, i, i) == 1) {
                cout << (char)('a' + j);
                break;
            }
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}