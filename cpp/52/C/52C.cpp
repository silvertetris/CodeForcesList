#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18; // 최솟값을 구하기 위한 무한대 값 설정

vector<ll> arr;
vector<ll> tree;
vector<ll> lazy;

// 1. 트리 초기화 (덧셈 -> min으로 변경)
void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]); 
}

// 2. 지연된 값 전파 (구간의 길이 곱하기 제거)
void propagate(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += lazy[node]; // 최솟값은 전체에 V를 더하면 최솟값도 V만큼만 증가함
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

// 3. 구간 업데이트 (덧셈 -> min으로 변경)
void update_range(int node, int start, int end, int left, int right, ll diff) {
    propagate(node, start, end);
    
    if (left > end || right < start) return;
    
    if (left <= start && end <= right) {
        lazy[node] += diff;
        propagate(node, start, end);
        return;
    }
    
    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, left, right, diff);
    update_range(node * 2 + 1, mid + 1, end, left, right, diff);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

// 4. 점 업데이트 (이 문제에선 안 쓰지만, RMQ 템플릿 구색을 위해 min으로 수정)
void update_point(int node, int start, int end, int idx, ll diff) {
    propagate(node, start, end);
    
    if (idx < start || idx > end) return;
    
    if (start == end) {
        tree[node] += diff;
        return;
    }
    
    int mid = (start + end) / 2;
    update_point(node * 2, start, mid, idx, diff);
    update_point(node * 2 + 1, mid + 1, end, idx, diff);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

// 5. 구간 최솟값 쿼리 (반환값 INF 및 자식들 간의 min 적용)
ll query(int node, int start, int end, int left, int right) {
    propagate(node, start, end);
    
    // 범위를 벗어나면 결과에 영향을 주지 않는 매우 큰 값(INF) 반환
    if (left > end || right < start) return INF; 
    
    if (left <= start && end <= right) return tree[node];
    
    int mid = (start + end) / 2;
    return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int tree_size = 4 * n;
    tree.assign(tree_size, 0);
    lazy.assign(tree_size, 0);

    init(1, 0, n - 1);

    int m;
    cin >> m;

    string line;
    getline(cin, line);

    while (m--) {
        getline(cin, line);
        stringstream ss(line);

        int lf, rg;
        ll v;

        ss >> lf >> rg;

        if (ss >> v) {
            if (lf > rg) {
                update_range(1, 0, n - 1, lf, n - 1, v);
                update_range(1, 0, n - 1, 0, rg, v);
            } else {
                update_range(1, 0, n - 1, lf, rg, v);
            }
        } else {
            if (lf > rg) {
                ll r1 = query(1, 0, n - 1, lf, n - 1);
                ll r2 = query(1, 0, n - 1, 0, rg);
                cout << min(r1, r2) << "\n";
            } else {
                cout << query(1, 0, n - 1, lf, rg) << "\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}