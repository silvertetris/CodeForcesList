#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> arr;
vector<int> tree;
vector<bool> lazy;
vector<int> t;
vector<int> in_time;
vector<int> out_time;
vector<vector<int>> p;
int timer = 0;

void dfs(int i, int j) {
    in_time[i] = ++timer;
    arr[timer] = t[i];


    for(int u: p[i]) {
        if(u!=j) {
            dfs(u, i);
        }
    }
    out_time[i] = timer;
}
// 1. 트리 초기화
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
        //커버해야할 원소 개수가 정배
        //tree[node] += (end - start + 1) * lazy[node];
        tree[node] = (end-start+1) - tree[node];
        if (start != end) {
            lazy[node * 2] = !lazy[node*2];
            lazy[node * 2 + 1] = !lazy[node*2+1];
        }
        lazy[node] = 0;
    }
}

// 3. 구간 업데이트 (Range Update - 지연 세그트리 방식)
void update_range(int node, int start, int end, int left, int right) {
    propagate(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && end <= right) {
        lazy[node] = !lazy[node];
        propagate(node, start, end);
        return;
    }
    
    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, left, right);
    update_range(node * 2 + 1, mid + 1, end, left, right);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int start, int end, int left, int right) {
    propagate(node, start, end);
    
    if (left > end || right < start) return 0;
    
    if (left <= start && end <= right) return tree[node];
    
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}
void solve() {
    int n;
    cin>>n;
    t.assign(n+1, 0);
    p.assign(n+1, vector<int>());
    tree.assign(4*n+1, 0);
    lazy.assign(4*n+1, false);
    arr.assign(n+1, 0);
    in_time.assign(n+1, 0);
    out_time.assign(n+1, 0);
    for(int i=2; i<=n; i++) {
        int u;
        cin>>u;
        p[u].push_back(i);
    }
    for(int i=1; i<=n; i++) {
        cin>>t[i];
    }
    dfs(1, 0);
    init(1, 1, n);
    int q;
    cin>>q;
    while(q--) {
        string r;
        int op;
        cin>>r>>op;
        int left = in_time[op];
        int right = out_time[op];
        if(r=="get") {
            cout<<query(1, 1, n, left, right)<<"\n";
        }
        else {
            update_range(1, 1, n, left, right);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}