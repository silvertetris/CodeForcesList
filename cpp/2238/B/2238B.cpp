#include <bits/stdc++.h>

#define ll long long
#define ld long double
/*
1부터 n 까지 눈
a, b, c 번쨰 눈을 고름
gcd(lcm(a, b), lcm(b, c)) = gcd(a, c)면 크림슨
서로 순서는 달라도 됨 -> 서로 순서 달라도 됨 -> a, c 랑 c, a 둘 경우의 수 같은 수 제외 하고 2곱해줘야함
소수판정, 오일러 피

gcd(a, c)의 배수 && lcm(a, c)의 약수 어야함

gcd(a, c) 가 특정값인거 구하기
-> 오일러 피 누적합 해서 -> n 까지 쌍이니까 n을 특정값으로 나누면 , a, c는 서로소임
-> 이거 쌍 찾아서
-> 그니까 오일러피는 y보다 작거나 같으면서 y와 서로소인 x의 개수임 
그니까 a<=c 니까 c>=a 도 찾야아함 

*/
using namespace std;

vector<ll> cnt;
vector<ll> prefix;
vector<ll> divv;
int n;

void eular()
{
    for (int i = 1; i <= 200000; i++)
    {
        ll result = i;
        ll temp = i;
        for (auto p = 2ll; p * p <= temp; p++)
        {
            if (temp % p == 0)
            {
                result -= result / p;
                while (temp % p == 0)
                {
                    temp /= p;
                }
            }
        }
        if (temp > 1)
        {
            result = result - result / temp;
        }
        cnt[i] = result;
    }
    prefix[1] = cnt[1];
    for (int i = 2; i <= 200000; i++)
    {
        prefix[i] = prefix[i - 1] + cnt[i];
    }

    for (int i = 1; i <= 200000; i++)
    {
        for (int j = i; j <= 200000; j += i)
        {
            divv[j]++;
        }
    }
}

void solve()
{
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += divv[i] * (2*prefix[n/i]-1ll);
    }

    cout << ans << "\n";
}

int main()
{
    int ss = 200001;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cnt.resize(ss, 0);
    prefix.resize(ss, 0);
    divv.resize(ss, 0);
    eular();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}