#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    /*
    훈련 시키는데 1고블린 코인 -> 계급 높아질수록 더 쌤
    */
    int n, k;
    cin>>n >>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    int res = 0;
    if(n==1) {
        cout<<k-a[0]<<"\n";
        return 0;
    }
    while(a[0]!=k) {
        if(a[0]!=a[1]) {
            a[0]++;
        }
        for(int i=1; i<n; i++) {
            if(i-1==0) {
                continue;
            }
            if(a[i] != a[i-1]) {
                a[i-1]++;
            }
        }
        if(a[n-1]<k) {
            a[n-1]++;
        }
        res++;
    }
    cout<<res<<"\n";
}