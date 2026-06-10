#include <bits/stdc++.h>

#define ll long long
#define ld long double

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
        int n, k;
        cin >> n >> k;
        string s = "";
        cin >> s;
        int minval =0;
        int pos=0;
        int curval = 0;
        for(int i=0; i<n; i++) {
            if(s[i]=='(') {
                curval++;
            }else {
                curval--;
            }
            if(curval<minval) {
                pos = i;
                minval = curval;
            }
        }
        vector<int> res(n, 0);
        for(int i=0; i<pos; i++) {
            if(k>0 &&s[i] =='(') {
                k--;
                res[i] = 1;
            }
        }
        for(int i=n-1; i>=pos; i--) {
            if(k>0 && s[i] ==')') {
                k--;
                res[i] =1;
            }
        }
        for(int i=0; i<n; i++) {
            cout<<res[i];
        }
        cout<<"\n";
    }
}