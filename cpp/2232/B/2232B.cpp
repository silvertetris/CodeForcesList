#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

/*
a_i는 i 포지션의 서리 높이
높이 h에 칼을 넣음
i에 있는 서리 높이가 h보다 크면
a_i - h 만큼 a_i+1에 더하게 됨
n에 있는건 사라짐
오름차순이 나오면 안되는걸 알면서
초기값

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
        vector<int> a(n+1, 0);
        for(int i=1; i<=n; i++)  {
            cin>>a[i];
        }
        ll summ =a[1];
        ll mini = a[1];
        cout<<a[1]<<" ";
        for(int i=2; i<=n; i++) {
            summ+=a[i];
            ll average = summ/i;
            mini = min(mini, average);
            cout<<mini<<" ";
        }
        cout<<"\n";
    }
}