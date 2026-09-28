#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (auto &i : b)
    {
        cin >> i;
    }
    // pair(분자, 분모), ans
    map<pair<int, int>, int> arr;
    int extra =0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            if(b[i]==0) {
                extra++;
                continue;
            }
            continue;
        }
        int nom = 0;
        int denom = 0;
        int p = gcd(abs(a[i]), abs(b[i]));
        a[i] /= p;
        b[i] /= p;
        if ((a[i] > 0 && b[i] > 0) || (a[i] < 0 && b[i] < 0))
        {
            a[i] = abs(a[i]);
            a[i] *= -1;
            b[i] = abs(b[i]);
        } else {
            a[i] = abs(a[i]);
            b[i] = abs(b[i]);
        }
        if (arr.find({a[i], b[i]}) == arr.end())
        {
            arr.insert({{a[i], b[i]}, 1});
        }
        else
        {
            int temp = arr[{a[i], b[i]}];
            temp+=1;
            arr.erase({a[i], b[i]});
            arr.insert({{a[i], b[i]}, temp});
        }
    }
    for(auto &i: arr) {
        ans = max(ans, i.second);
    }
    cout<<ans+extra<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t=1;

    while (t--)
    {
        solve();
    }
}