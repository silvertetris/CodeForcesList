#include <bits/stdc++.h>

using namespace std;

string add(string a, string b)
{
    string res;

    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';

        res += char('0' + sum % 10);
        carry = sum / 10;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l;
    string n = "";
    cin >> l >> n;
    /*두 파트로 나눠서 합이 최소가 되는 수
    결국 0인 애들이 중요함
    0이 없으면 경우의 수가 2가지가 나오는데, 거기서 합이 제일 작은애 찾으면됨
    근데 만약에 0이 있으면
    1. 좌측으로는 0이 아닌숫자 이후에 다른 숫자 1개가 더 있어야함
    2. 우측으로는 0이 딱 끝나고 0이 아닌 숫자가 1개 시작하는 지점
    */

    int mid = (l + 1) / 2;

    string ans = "";

    int j = mid;
    while (j < l && n[j] == '0')
    {
        j++;
    }

    if (j < l)
    {
        string a = n.substr(0, j);
        string b = n.substr(j);

        ans = add(a, b);
    }

    int k = mid - 1;
    while (k > 0 && n[k] == '0')
    {
        k--;
    }

    if (k > 0)
    {
        string c = n.substr(0, k);
        string d = n.substr(k);

        string cur = add(c, d);

        if (ans.empty() ||
            cur.size() < ans.size() ||
            (cur.size() == ans.size() && cur < ans))
        {
            ans = cur;
        }
    }

    cout << ans << '\n';
}