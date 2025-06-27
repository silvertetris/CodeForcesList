#include <vector>
#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<int> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    const ll INF = LLONG_MIN / 4;

    while(q--){
        ll a, b;
        cin >> a >> b;
        vector<ll> dp(n+1, INF);
        ll mx1 = 0;
        ll mx2 = 0;

        for(int i = 0; i < n; i++) {
            if (mx1 == dp[c[i]]) { //해당 최대 값이 그 전 공에서 고른 최대값이니까 성립됨
                dp[c[i]] = max(dp[c[i]], dp[c[i]] + a * v[i]);
                dp[c[i]] = max(dp[c[i]], mx2 + b*v[i]); //다른 경우는 mx2를 고려해야함
                mx1 = max(mx1, dp[c[i]]);
            } else { //만약 최대값이 그 해당 인덱스 값과 다르다면
                dp[c[i]] = max(dp[c[i]], dp[c[i]] + a * v[i]);
                dp[c[i]] = max(dp[c[i]], mx1 + b * v[i]); //이번에는 mx1을 고려해야함
                mx2 = max(mx2, dp[c[i]]);
                if (mx2>mx1) swap(mx1, mx2); //더 크면 둘이 swap
            }
        }
        cout<<mx1<<'\n'; //결과적으로 mx1이 최대 값
    }

    return 0;
}