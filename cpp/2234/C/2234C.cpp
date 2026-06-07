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
        int n;
        cin >> n;
        vector<ll> h(n);
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        /*
        그니까 각 구간에서의 최대값을 구해야함 -> 원형을 따졌을때

        i+j부터 i+n-1 -> 오른쪽 물통들
        그니까 비운곳 기점으로 우측 -> 최대값 유지
        비운곳 기점으로 좌측 -> 최대값 유지
        이거 근데 하드에서는 안풀림 O(n^2)
        그럼 왼쪽 통통이들은 어떻게 하냐?
        i, i+j-1이겠지 -> 기점으로 왼쪽 i까지 <<< 우측에 있는 큰놈들 보다 무조건 작아야함
        */
        for (int i = 0; i < n; i++)
        {
            vector<ll> r(n+1, 0);
            for(int j=n-1; j>=1; j--) {
                r[j] = max(r[j+1], h[(i+j)%n]);
            }
            ll res = 0;
            ll l = 0;
            for(int j=1; j<n; j++) {
                l=max(l, h[(i+j-1) %n]);
                res+=min(l, r[j]);
            }
            cout << res << " ";
        }
        cout << "\n";
    }
}