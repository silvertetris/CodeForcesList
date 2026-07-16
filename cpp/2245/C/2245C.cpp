#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n, k;

string to_binary(int num)
{
    string s = "";
    while (num > 0)
    {
        if (num % 2 == 1)
            s = "1" + s;
        else
            s = "0" + s;
        num >>= 1;
    }
    return s;
}

int to_int(string s)
{
    int cur = 1;
    int result = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            result += cur;
        }
        cur <<= 1;
    }
    return result;
}

void solve()
{
    cin >> n >> k;
    if (n == 1 && k == 1)
    {
        cout << "YES\n0\n";
        return;
    }
    string kstring = to_binary(k);
    string nstring = to_binary(n);
    if (kstring.size() > nstring.size())
    {
        cout << "NO\n";
        return;
    }
    if (nstring.size() > kstring.size() && count(nstring.begin(), nstring.end(), '1') == 1)
    {
        cout << "NO\n";
        return;
    }
    reverse(kstring.begin(), kstring.end());
    reverse(nstring.begin(), nstring.end());

    // lsb부터
    vector<bool> flag(nstring.size(), false);
    string sample = "";
    for (int i = 0; i < nstring.size(); i++)
    {
        if (kstring.size() > i)
        {
            if (kstring[i] == '1' && nstring[i] != '1')
            {
                flag[i] = true;
            }
            else if (kstring[i] == '1' && nstring[i] == '1')
            {
                continue;
            }
            else if (kstring[i] != '1' && nstring[i] == '1')
            {
                flag[i] = true;
            }
        }
        else
        {
            if (nstring[i] == '1')
            {
                flag[i] = true;
            }
        }
    }
    for (int i = 0; i < nstring.size(); i++)
    {
        if (flag[i])
        {
            sample.push_back('1');
        }
        else
        {
            sample.push_back('0');
        }
    }
    /*
    1. lsb부터 탐색 -> 연속된 1이고 끝나는 지점에서 마지막 1인 숫자부터 넣음 그리고 시작 1지점까지.
    2. 만약 1이 안나오면, 그 2의 몇승 까지의 숫자는 그전 까지 숫자로 채움
    cur-1
    */

    if (to_int(sample) == 0)
    {
        cout << "NO\n";

        return;
    }
    cout << "YES\n";
    int ans = to_int(sample);

    int cur = ans - 1;
    if (n - cur > 2)
    {
        for (int i = cur + 2; i <= n - 2; i++)
        {
            cout << i << " ";
        }
        for (int i = 1; i < cur; i++)
        {
            cout << i << " ";
        }
        cout << 0 << " ";
        cout << cur + 1 << " ";
        cout << n - 1 << " ";
        cout << cur << "\n";
    }else {
        
    }
}

int main()
{
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}