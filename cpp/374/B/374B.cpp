#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a = "";
    cin >> a;

    int length = a.size();

    /*
    한턴에, 2개의 인접한 숫자를 고름 (합이 9인 두 숫자) 그리고 그 두 숫자를 하나의 숫자 9로 바꿈

1 8
2 7
3 6
4 5
-> 9

두 인접한 수를 탐색해서 조건
    맞으면 각 digits++;
    9짝이 짝수면 어차피 최적인데 만약, 홀수가 남으면 경우의 수가 하나 늚
    
    */
    ll ans =1;
    int cnt =0;
    for (int i = 1; i < length; i++)
    {
        if(a[i]-'0' + a[i-1]-'0'==9) {
            cnt++;
        }
        else {
            if(cnt%2==0) {
                ans*=cnt/2 +1;
                cnt=0;
            }
            cnt=0;
        }
    }
    if(cnt%2==0) {
        ans*=cnt/2 +1;
    }
    cout<<ans<<"\n";
}