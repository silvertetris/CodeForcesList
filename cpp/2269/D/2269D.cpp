#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n, q;
vector<int> a;
void solve() {
    cin>>n>>q;
    a.assign(n, 0);
    int cur = 0;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        if(popcount((unsigned int)a[i])%2==0) {
            cur++;
        }
    }
    cout<<cur<<" ";
    /*
    0, 3, 6, 9, 10 이 주위에 있으면 변환 가능
    0, 3, 6, 9, 12, 15 -> 원래 divisible by 3
    10 예외, 0, 3, 10, 12, 15
    그니까 5하고 10이고, 앞이나 뒤에 15를 제외한 3의 배수가 있으면 됨.
    */
    while(q--) {
        int p, x;
        cin>>p>>x;
        p--;
        bool temp = popcount((unsigned int)a[p])%2?0:1;
        a[p] = x;
        bool temp2 = popcount((unsigned int)a[p])%2?0:1;
        if(temp&&!temp2) {
            cur--;
        } else if(!temp && temp2) {
            cur++;
        }
        cout<<cur<<" ";
    }
    cout<<"\n";
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}