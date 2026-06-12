#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve()
{//30*30
    int a, b, x;
    cin >> a >> b >> x;
    int ans = INT_MAX;
    int dividea = 0;
    int tempa = a;
    while (tempa>=0)
    {
        int divideb = 0;
        int tempb = b;
        while(tempb>=0) {

            int ops = dividea+divideb + abs(tempa-tempb);
            ans = min(ans, ops);

            if(tempb==0) {
                break;
            }
            tempb/=x;
            divideb++;
        }
        if(tempa==0) {
            break;
        }
        tempa/=x;
        dividea++;
    }
    cout<<ans<<"\n";
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