#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int MOD = 1e9 + 7;
/*
그냥 lcm(p....) = p1*p2*..
이거면 걍 서로소 인애들 집합
서로소 집합인 애들 개수
오일러 피 함수? -> 아님 구간에서 서로소 개수가 안됨 -> 맞음 구간에서 서로소 개수 구해야지 -> 근데 1부터 n 까지가 아닌 배열에서만 그니까
각 배열 순회할때마다 카운트 둬야함

소수인거 -> 소인수 인거 -> 소인수 인거 안겹쳐야함
약수인거 다 구해서 저장
*/
int divisors[5 * 100000 + 1];
void seive()
{
    for (int i = 0; i <= 5 * 100000; i++)
    {
        divisors[i] = i;
    }
    for (int i = 2; i <= 5 * 100000; i++)
    {
        if (divisors[i] == i)
        {
            for (int j = 2*i; j <= 5 * 100000; j += i)
            {
                if(divisors[j]==j) {
                    divisors[j] = i;
                }
            }
        }
    }
}

void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    vector<int> flag;
    vector<int> divCnt(5*100000+1, 0);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    for(int i=0; i<n; i++) {
        int temp = a[i];
        while(temp>1) {
            int div = divisors[temp];
            int cnt = 0;
            while(temp%div==0) {
                cnt++;
                temp/=div;
            }
            if(divCnt[div]<=0) {
                flag.push_back(div);
            }
            divCnt[div]+=cnt;
        }
    }

    ll ans = 1;
    for(int i=0; i<flag.size(); i++) {
        ans = (ans*(divCnt[flag[i]]+1))%MOD;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);
    seive();
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}