#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;
        ll div = n/12;
        ll remain = n%12;
        ll sub = n-div*12;//그니까 얘가 팰린드롬이여야함
        //10에서 막히면 12를 더해서 22 맞추기
        //10일때만 안됨 더 크면? 22 이상이면 무조건 가능

        if(remain != 10) {
            cout<<remain<<" "<<n-remain<<"\n";
        } else if(n>=22) {
            cout<<22<<" "<<n-22<<"\n";
        }else {
            cout<<-1<<"\n";
        }

    }
}