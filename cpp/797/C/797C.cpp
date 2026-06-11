#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve()
{
    string s;
    cin >> s;
    string t = "";
    string u = "";

    vector<int> cnt(26, 0);
    for (char c : s)
    {
        cnt[c - 'a']++;
    }

    int idx = 0;
    for (char c : s)
    {
        t.push_back(c);
        cnt[c - 'a']--;
        while (idx < 26 && cnt[idx] == 0)//현재 s에 남은 가장 작은 알파벳
        {
            idx++;
        }

        while (!t.empty() && (t.back() - 'a') <= idx)//u에다가, s에서 남은 제일 작은거랑 같거나 작은 애가 있으면 넣음
        {
            u.push_back(t.back());
            t.pop_back();
        }
    }
    
    cout<<u<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}