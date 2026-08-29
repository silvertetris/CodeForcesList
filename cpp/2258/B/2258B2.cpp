#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n, m;
vector<int> a;
void solve() {
    cin>>n>>m;
    a.assign(n, 0);
    vector<int> visited(m+1, 0);
    ll summ = 0;
    int maximum = 0;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        visited[a[i]]++;
        summ+=a[i];
        maximum = max(maximum, a[i]);
    }
    vector<ll> prefix(m+1, 0);
    for(int i=1; i<=m; i++) {
        prefix[i] = prefix[i-1] + visited[i];
    }
    /*
    2^x일때 x에 따라 뻥튀기 됨
    x번 이상일때는 어차피 summ이 답임
    min(maximum, x) ->나누는 횟수
    숫자를 확정시켜놓고,
    거기서 maximum을 넘지 않는 어떤 숫자를 최대 개수로 치고 그걸 max로 업데이트
    그리고 나눈수 과거 예측
    */
    vector<ll> ans(m+1,summ);
    for(auto i=1; i<=m; i++) {
        int x = (int)pow(2, (double)min(i, 19));
        if(x > maximum) break;

        ll temp = 0;
        for(auto j=1; j<=maximum; j++) {
            ll cnt = 0;
            for(auto k=1; k<x ; k++) {
                if((ll)k*j>maximum) break;
                cnt += prefix[m] - prefix[k*j-1];
            }
            if((ll)x*j <= maximum) {
                cnt += visited[x*j];
            }
            temp = max(temp, cnt);
        }
        ans[i] = temp;
    }
    for(int i=1; i<=m; i++) {
        cout<<ans[i]<<" ";
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