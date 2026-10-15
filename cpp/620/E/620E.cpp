#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> arr;
vector<ll> tree;
vector<ll> lazy;
vector<int> in_time;
vector<int> out_time;
int timer = 0;
vector<int> arr;
vector<int> c;
vector<vector<int>> adj;

void dfs(int cur, int parent) {
    in_time[cur] = ++timer;
    arr[timer] = c[cur];

    for(int next: adj[cur]) {
        if(next!=parent) {
            dfs(next, cur);
        }
    }
    out_time[cur] = timer;
}

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

// 2. 지연된 값 전파 (Lazy Propagation)
void propagate(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

// 3. 구간 업데이트 (Range Update - 지연 세그트리 방식)
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
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

// 4. 점 업데이트 (Point Update - 일반 세그트리 베이스 + propagate 추가)
void update_point(int node, int start, int end, int idx, ll diff) {
    // ★ 핵심: 일반 세그트리 로직이지만, 지연값 충돌을 막기 위해 반드시 propagate를 먼저 호출
    propagate(node, start, end);
    
    if (idx < start || idx > end) return;
    
    if (start == end) {
        tree[node] += diff;
        return;
    }
    
    int mid = (start + end) / 2;
    update_point(node * 2, start, mid, idx, diff);
    update_point(node * 2 + 1, mid + 1, end, idx, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

// 5. 구간 쿼리 (Range Query)
ll query(int node, int start, int end, int left, int right) {
    propagate(node, start, end);
    
    if (left > end || right < start) return 0;
    
    if (left <= start && end <= right) return tree[node];
    
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

void solve() {
    int n, m;
    cin>>n>>m;
    c.assign(n+1, 0);
    adj.assign(n+1, vector<int>());
    in_time.assign(n+1, 0);
    out_time.assign(n+1, 0);
    arr.assign(n+1, 0);
    tree.assign(4*n+1, 0);
    lazy.assign(4*n+1, 0);
    for(int i=1; i<=n; i++) {
        cin>>c[i];
    }
    for(int i=0; i<n-1; i++) {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    while(m--) {
        int t;
        cin>>t;
        int v;
        cin>>v;
        if(t==1) {
            int c;
            cin>>c;
        }else {

        }
    }

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}