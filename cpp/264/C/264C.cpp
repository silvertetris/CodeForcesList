#include <iostream>
using namespace std;

#define int ll
typedef long long ll;
int const N = 1e5 + 20, INF = 1e15;
int n, q, c[N], v[N], ans[N];

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i ++) cin >> v[i];
    for (int i = 0; i < n; i ++) cin >> c[i], c[i] --;

    while (q --){
        int a, b; cin >> a >> b;
        int mx1 = 0, mx2 = 0;

        for (int i = 0; i < n; i ++) ans[i] = -INF;
        for (int i = 0; i < n; i ++){
            if (mx1 == ans[c[i]]){
                ans[c[i]] = max(ans[c[i]], ans[c[i]] + a * v[i]);
                ans[c[i]] = max(ans[c[i]], mx2 + b * v[i]);
                mx1 = max(mx1, ans[c[i]]);

            }
            else {
                ans[c[i]] = max(ans[c[i]], ans[c[i]] + a * v[i]);
                ans[c[i]] = max(ans[c[i]], mx1 + b * v[i]);
                mx2 = max(mx2, ans[c[i]]);

                if (mx2 > mx1) swap(mx1, mx2);
            }
        }

        cout << mx1 << '\n';
    }
}
