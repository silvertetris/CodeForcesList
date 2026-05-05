#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc = 0;
    cin>>tc;
    while(tc--) {
        int n, l, t;
        ll p;
        cin>>n>>p>>l>>t;//날, 자격요건, 출석, 임무수행
        int left = 0;
        int right = n;
        while(left<=right) {
            ll mid = (left+right)/2;
            ll value = mid*l + min((ll)(n-1)/7+1, 2*mid)*t;
            if(value<p) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        cout<<n-left<<"\n";
    }
}