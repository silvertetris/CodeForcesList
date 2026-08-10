#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int one = 0;
    int zero = 0;
    int adup = 0;
    int bdup = 0;
    int neg = 1;
    for(int i=0; i<n; i++) {
        if(s[i]=='1') {
            one++;
        }else zero++;
    }
    if(abs(one-zero)>=3) {
        cout<<-1<<"\n";
        return;
    }

    for (int i = 1; i < n; i++)
    {
        if(s[i] != s[i-1]) {
            neg++;
        }
        else {
            if(s[i]=='0') {
                adup++;
            }else {
                bdup++;
            }
        }
    }
    if(abs(adup-bdup)<=1) {
        cout<<n-neg<<"\n";
    }else if(abs(adup-bdup)<=2) {
        cout<<n-neg+1<<"\n";
    } else  {
        cout<<n-neg+2<<"\n";
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