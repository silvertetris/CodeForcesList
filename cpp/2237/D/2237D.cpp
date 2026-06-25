#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n;
void solve()
{
    cin >> n;
    string s;
    cin >> s;
    /*
    1 - 0의 개수
    각 개수를 더하다가
    개수 차이가 0이면 안됨 -> 무조건 숫자 하나가 남음
    그니까 현재까지 더한 값중 개수차이가 3의 배수 (현재랑 같은 것)을 지움
    cnt[x] 자체가 3의 배수인 애들 자체를 지우는 것임.
    그리고 개수가 0인건 다 지웠으니까
    010101 통과된걸 지움
    근데 둘이 숫자 같은건 이미 1번에서 지웠으니까
    01010, 10101 같은 홀수들만 지움 그니까 2로나누고 지우는 것임.
    */
    vector<int> cnt(3, 0);
    cnt[0] = 1; // 초기 길이가 0인애
    int x = 0;
    int y=0;
    ll ans = 0;
    char prev = ' ';
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            x++;
        }
        else
        {
            x += 2;
        }
        x%=3;
        if(prev==s[i]) {
            y=1;
        }else {
            y++;
            prev = s[i];
        }
        ans+= accumulate(cnt.begin(), cnt.end(), 0)- cnt[x];
        cnt[x]++;
        ans-=(y-1)/2;
    }
    cout<<ans<<"\n";
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