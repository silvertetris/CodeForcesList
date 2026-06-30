#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n;
/*
l, r
a= 이전 a -1 i-l 이 홀수면
짝수면 오른쪽꺼
그니까 인덱스에 l을 빼는거임
-> 반대임
1based 에서

이 i를 l~r 사이에 모든 값에 적용임
//1 고르면 무조건 증가임
1에서 최대치로 증가해야하면 동시에 1을 차이만큼 골라야하는데, 반대쪽이 줄여야함, 그러면 뒤에껏도 고라줘야하는데 세번쨰도 감소해야하면 2도 해야함 그래서 그 차이가 1의 고른 수보다 더 크면 안됨
뒤까지 신경쓰면?
*/
void solve()
{
    cin >> n;
    vector<int> a(n + 2, 0);
    vector<int> b(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    ll sub = 0;
    int diff = 0;
    for (int i = 1; i <= n; i++)
    {
        sub += b[i] - a[i];
        if (sub < 0)
        {
            cout << "NO\n";
            return;
        }
    }
    /*if(diff!=0 && sub%diff==0) {
        cout<<"YES\n";
    }else {
        cout<<"NO\n";
    }*/
    cout<<"YES\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}