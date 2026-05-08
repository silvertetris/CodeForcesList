#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        ll mex = 0; // 최대 mex
        ll res =0;
        for (int i = 0; i < n; i++)
        {
            if (mex == a[i])
            {
                mex++;
            }
            else if (mex < a[i])
            {
                break;
            }
        }
        ll maximum = a.back();
        if(maximum==0) {
            int temp=0;
            for(int i=1; i<=n; i++) {
                if(i>mex) {
                    res+= maximum + mex;
                } else {
                    res+= i+i-1;
                }
            }
        }
        else {
            for(int i=0; i<n; i++) {
                res+=maximum;

                res+=min((ll)i, mex);
            }
            if(maximum<=mex) {
                res++;
            }
        }

        cout << res << "\n";
    }
}