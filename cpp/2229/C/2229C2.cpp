#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
/*
prefix sum으로 일단 다 더해놓고
만약에 그 이후에 나온수가? 더 크다? 그럼 안바꿈

-1 -3 6 이런식이면 안바꿈
근데 -1 -3 4 여도 안바꿀듯
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        vector<ll> suffix(n, 0);
        vector<ll> prefix(n, 0);
        prefix[0] = abs(a[0]);
        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1]+ abs(a[i]);
        }
        suffix[n-1] = a[n-1];
        for(int i=n-2; i>=0; i--) {
            suffix[i] = suffix[i+1]+a[i];
        }

        ll sumsuf = suffix[0];
        int idx = -1;
        for(int i=1; i<n; i++) {
            if(a[i]>0 && i<n-1) {
                ll temp = prefix[i-1] + suffix[i+1] - a[i];
                if(sumsuf<temp) {
                    idx = i;
                    sumsuf = temp;
                }
            }
            else if(a[i]>0 && i==n-1) {
                ll temp = prefix[i-1] -a[i];
                if(sumsuf<temp) {
                    idx = i;
                    sumsuf = temp;
                }
            }
        }
        if(idx==-1) {
            cout<<0<<"\n";
            cout<<"\n";
            continue;
        }
        vector<int> res;
        bool flag = false;
        for (int i = idx - 1; i >= 0; i--)
        {
            if (!flag && a[i] > 0)
            {
                flag = true;
                res.push_back(i + 1);
            }
            else if (flag && a[i] > 0)
            {
                continue;
            }
            else if (flag && a[i] < 0)
            {
                res.push_back(i + 1);
                flag = false;
            }
            else
            {
                continue;
            }
        }
        res.push_back(idx+1);
        cout<<res.size()<<"\n";
        for(int i=0; i<res.size(); i++) {
            cout<<res[i]<<" ";
        }
        cout<<"\n";
    }
}
