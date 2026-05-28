#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    /*
    n홀드 a_i만큼 떨어져있음
    오름차순이면 트랙
    그 구간의 어려움은 두 인접 난이도 차의 최대값
    각 인덱스를 정해서 빼야함
    */
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int res = 1000000;
    for (int i = 1; i < n - 1; i++)
    {
        int temp = 0;
        for (int j = 1; j < n; j++)
        {
            if (j == i)
            {
                temp = max(temp, a[j + 1] - a[j - 1]);
                j += 1;
            }
            else {
                temp = max(temp, a[j]-a[j-1]);
            }
        }
        res = min(res, temp);
    }
    cout << res << "\n";
}