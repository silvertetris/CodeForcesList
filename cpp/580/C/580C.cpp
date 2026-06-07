#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &a, int x, int cnt, int &res, int m)
{

    visited[x] = true;
    if (cnt > m)
    {
        return;
    }
    if (graph[x].size() <= 1 && visited[graph[x][0]])
    {
            res++;
    }
    for (int i : graph[x])
    {
        if (!visited[i])
        {
            if (!a[i])
            {
                dfs(graph, visited, a, i, 0, res, m);
            }
            else
            {
                dfs(graph, visited, a, i, cnt + 1, res, m);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> graph(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> visited(n + 1, false);
    int res = 0;
    dfs(graph, visited, a, 1, a[1], res, m);
    cout << res << "\n";
}