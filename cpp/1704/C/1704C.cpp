#include <bits/stdc++.h>

using namespace std;

#define ll long long
/*
처음에는 m개 감염, 아침마다 절대 면역인 집 하나 선택 가능
먼저 면역으로 만들고, 인접한 감염은 감염

*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> prefix(m);
        prefix[0] = n - a[m - 1] + a[0] - 1;
        for (int i = 1; i < m; i++)
        {
            prefix[i] = a[i] - a[i - 1] - 1;
        }
        sort(prefix.begin(), prefix.end(), greater<int>());

        int temp=0;
        int res =0;
        for(int i=0; i<m; i++) {
            if(prefix[i] - temp <=0) {
                break;
            }
            if(prefix[i] - temp  ==1) {
                res++;
                temp+=2;
            } else {
                res += prefix[i] - temp -1;
                temp+=4;
            }
        }
        cout<<n-res<<"\n";
    }
}