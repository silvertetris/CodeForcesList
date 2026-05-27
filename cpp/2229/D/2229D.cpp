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
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        /*
        max(min(a1, b1)) -> 최소것들의 최대 -> 이분탐색
        최대화 시키는 것 -> diff = one - zero
        diff 최대화 방법: 1의 개수가 최대화 -> 탐색하는 4개가 다 1이여야함.
        */
        int l = 0;
        int r = 1e6 * 2;
        while (l <= r)
        {
            int mid = (l + r) / 2; // m
            int prev = -1;
            int zero = 0;
            int one = 0;
            // 경우는 3개, --, ++, -+ 0, 2, 1
            for (int i = 0; i < n; i++)
            {
                int type = 0;
                if (a[i] >= mid)
                {
                    type++;
                }
                if (b[i] >= mid)
                {
                    type++;
                }

                if (type == 0)
                { // 남는게 --
                    if (prev != 0)//이전이 -이 아니면 -> -+, ++ 에서 -- 나온거니까 -> 그 포지션은 --임
                    {//어차피 0,0은 최대한 없애야지 m이상이 만족함 -> 여러개의 0,0은 그냥 하나의 zero로 압축
                        zero++;
                        prev = 0;
                    }
                }
                else if (type == 1)//-+나옴 얘는 무시깜 어차피 그 앞에 나온것에 따라 달라짐 -> --나 ++ 나오면 그거에 따라감
                { // 남는게 -+
                    continue;
                }
                else
                { // 남는게 ++ -> 무조건 ++임 이전 ++로 초기화
                    one++;
                    prev = 1;
                }
            }
            if (one > zero)
            { // 1이 더많아야하니까, m값을 내려야함
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << l-1 << "\n";
    }
}