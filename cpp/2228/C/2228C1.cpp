#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
// 현재 깊이, 최종 깊이, 뺄값, a값 d1, d2, 최종값
/*
예외? -> x>a+res 인경우 끝자리에서 하나? 해도 안될거 같음
*/
void divc(int depth, int aLength, ll x, ll &a, int &d1, int &d2, ll &res)
{
    int diff = aLength - depth;
    ll u = x, v = x;
    for(int i=0; i<diff; i++) {
        u = u*10 + d1;
        v = v*10 + d2; 
    }

    if(v < a - res) return;
    if(u > a + res) return;

    if (depth == aLength)
    {
        res = min(res, abs(a - x));
        return;
    }
    else
    {
        divc(depth + 1, aLength, x * 10 + d1, a, d1, d2, res);
        divc(depth + 1, aLength, x * 10 + d2, a, d1, d2, res);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll a;
        int n;
        cin >> a >> n;
        int d1, d2;
        cin >> d1 >> d2;

        /*
        아 섞어도 되는거임 d1 이랑 d2랑
        그럼 어떻게 해야하나?
        각 뻇을때 최소값? dp? 어떻게??
        분할정복? -> 각 자리수 마다 d1, d2를 선택함, 최적으로 -> 그리고 각 자리수 지나갈때마다 최적을 정해줌
        확인해야하는거 -> 자리수 n-1, n, n+1 이만큼만 하면 됨
        각 자리수로 채워질때 최적값
        아 n 이 아니라 길이
        */

        ll res = 2e18;

        for (int i = max(1, (int)to_string(a).length() - 1); i <= (int)to_string(a).length() + 1; i++)
        {
            divc(0, i, 0, a, d1, d2, res);
        }
        cout << res << "\n";
    }
}