#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int result;
bool flag;
int dfs(vector<vector<int>> &graph, int x, vector<bool> &visited)
{
    int subNode = 1;
    visited[x] = true;
    for (auto &nei : graph[x])
    {
        if (!visited[nei])
        {
            int temp = dfs(graph, nei, visited);
            if(temp%2==0) {
                result++;
            }
            subNode+=temp;
        }
    }
    return subNode;
}
void solve()
{
    int n;
    cin >> n;

    flag = false;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if (n % 2)
    {
        cout << "-1\n";
        return;
    }
    vector<bool> visited(n + 1, false);
    result = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(graph, i, visited);
        }
    }
    cout << result << "\n";
}

int main()
{
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    solve();
}