#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n;
vector<bool> isPrime(1000001, false);
vector<vector<int>> graph;
vector<int> in, out;
vector<int> depth, order;
void seive() {
    for(auto i=2ll; i*i<=1000000; i++) {
        isPrime[i] = true;
    }
    isPrime[1] = true;
}
/*
p(u, v)는 경로에 있는 모든 정점 값을 다 곱한 값
{u, v, w}가 있을때 조합 3개 했을때 다 곱하면 완전제곱수라면 -> 약수 또한 소수여야함
그렇다면 곱한값 모두가 소수거나 제곱수여야함 (1포함)
제곱수 포함 소수 판정 느낌의 i*i 단위로
어디에서 어디까지의 경로임 -> 결국 모든 애들은 공통 노드 1개를 거침 -> LCA 배운거
근데 지나오면서 다 곱? 소수나 제곱수가 아니더라도 같은수 2개가 나오면? -> 그냥 isPrime에서 정해야함
아니면 수를 작게 할까 -> 제곱수 빼기, 아니 결국에 lca가 아니라 그냥 다되는거 아님?
아니 어떤 경로에 있는 애들을 다 곱하든, 3개를 선택했을때 무족건 good 아니야?-> 아님, 왜냐면, 어떤 수던 직접 곱해보면 같은수를 2번 곱해 무조건. 그니까 결국은, 3개의 공통조상 과, 나머지 하위 2개의 공통조상과 겹치지 않는 노드들은 고려안해도됨.
그니까 하위노드의 lca가 제곱수인지만 보면 된다.
*/
void solve() {
    cin>>n;
    vector<int> a(n+1);
    in.resize(n+1);
    out.resize(n+1);
    graph.resize(n+1);
    depth.resize(n+1);
    order.resize(n+1);
    vector<int> parent(n+1);
    vector<bool> visted(n+1, false);


    for(int i=0; i<n-1; i++) {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    seive();
    while(t--) {
        solve();
    }
}