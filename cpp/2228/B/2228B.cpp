
#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

/*
n 포지션 원으로 있음
초기 포지션 레이부 x1 레밀리아 x2 둘은 무조건 다름
레밀리아가 가만히 있거나 한칸 움직이거나. 인접 움직이는건 k번 가능
레이무도 똑같이 진행
같은 포지션이면 레이무가 레밀리아 잡고 끝
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x1, x2, k; // 레이무, 레밀리아
        cin >> n >> x1 >> x2 >> k;
        /*
        레밀리아가 도망가야함 k 제한 -> 근데 안움직이면 카운트 안됨
        레밀리아 먼저 도망가고 레이무 움직임 -> 얘는 무제한
        */
        if (n == 2 || n == 3)
        {
            cout << "1\n";
        }
        else
        {
            int dist = abs(x1-x2);
            dist = min(dist, n-dist);
            cout<<k+dist<<"\n";
        }
    }
}