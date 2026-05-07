#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    vector<bool> visited(26, false); // 이미 한번 더했는지
    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - 'A']++;
        visited[s[i] - 'A'] = true;
    }
    int guard = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = s[i] - 'A';
        if (visited[cur])
        {
            guard++;
            visited[cur] = false;
        }
        if (guard > k)
        {
            cout << "YES\n";
            return 0;
        }
        if(--cnt[cur]<=0) {
            --guard;
        }
    }
    cout << "NO\n";
}