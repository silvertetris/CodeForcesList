#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n;
void solve()
{
    cin >> n;
    int vert, dist = 0;
    for (int i = 2; i <= n; i++)
    {
        cout << "? " << 1 << " " << i << " " << dist << "\n";
        cout.flush();
        int res;
        cin >> res;
        if (res == 0)
        {
            continue;
        }
        else
        {
            vert = i;
            dist++;
            for (int j = dist; j<= n; j++)
            {
                cout << "? " << 1 << " " << vert << " " << dist << "\n";
                cout.flush();
                cin >> res;
                if (res == 1)
                {
                    dist++;
                }
                else
                    break;
            }
        }
        if(dist==n) {
            break;
        }
    }
    int ans = 1;
    for(int i=2; i<=n; i++) {
        if(i==vert)continue;
        if(dist == n) break;

        cout<<"? "<<vert<< " "<<i<<" "<<dist<<"\n";
        cout.flush();
        int res;
        cin>>res;
        if(res==0) continue;
        else {
            ans = i;
            dist++;
            for (int j = dist; j <= n; j++)
            {
                cout << "? " << ans << " " << vert << " " << dist << "\n";
                cout.flush();
                cin >> res;
                if (res == 1)
                {
                    dist++;
                }
                else
                    break;
            }
        }
    }
    cout<<"! "<<ans<<" "<<vert<<" "<<dist-1<<"\n";
    cout.flush();
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