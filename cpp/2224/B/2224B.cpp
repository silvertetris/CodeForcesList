#include <bits/stdc++.h>
#define ll long long


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    /*
    음이 아닌 정수 배열 -> 재정렬 가능 맘대로
최대 Mex 합 하고 prefixes중에 최대 값


1 1 1 4 4 5

5 4 4 1 1 1

배열 사이즈
최대 mex를 먼저 찾음 
-> 그 수까지 빠르게 가는 방법은 1부터 더하는 방법임
1…n 까지 더하는건 n(n-1)/2
근데 최대값은 그냥 최대값 m * n임
최대 mex까지는 같이 올라감
1 2 3 4 5 -> 이걸 2번 더함 그니까 n(n-1)임
이거랑 최대값 에서 출발해서 천천히 mex채우기
5+0 , 5+1, 5+2

그럼 비교해야할게
한발 늦은 mex와 최대값 수와
mex를 차근차근 채울때 합

최대 mex를 가장 먼저찾기

최대값 * mex + (n-1)(n-2)/2 랑

    */
    while(t--) {
        int n;
        cin>>n;
        vector<ll> a(n);
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }

        sort(a.begin(), a.end());
        ll mex=0;//최대 mex
        for(int i=0; i<n; i++) {
            if(mex == a[i]) {
                mex++;
            } else if(mex<a[i]) {
                break;
            }
        }
        if(mex==0) {
            cout<<a[n-1] * (ll)n<<"\n";
            continue;
        }
        ll maximum = a.back();
        /*ll temp1 =0;
        for(int i=0; i<mex; i++) {//바로 최대값
            temp1+= i+maximum;
        }
        for(int i=mex; i<n; i++) {
            temp1+=mex+maximum;
        }
        //중간에서 바꾸는 것이 최적일수도 있나?
        /*
        있음
        마지막에 멕시멈이 더 크면 가능함
        그니까 2가지 경우가 아닌 처음부터 순회하면서 최대값 구해야함
        
        ll temp2=0;
        for(auto i=1; i<=mex; i++) {
            temp2+=i+i-1;
        }
        for(auto i=mex; i<n; i++) {
            temp2 += maximum+mex;
        }*/

        ll res = 0;
        for(auto i=0; i<=mex; i++) {
            res = max(res, ((ll)(ll)i*(i-1)) +(ll)(n-i)*(maximum+(ll)i) +(ll)i);
        }
        cout<<res<< "\n";
    }
}