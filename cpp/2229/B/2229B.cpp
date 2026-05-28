#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
/*
a, b 둘다 n임 배열
i를 고르고, (사이즈 이내) a_i랑 b_i랑 바꿈
max(a) + b합의 최대
같은 자리만 바꿀 수 있음
a의 최대값이 더 크면?
바로 뒤에 있는애를 b의 제일 작은것과 교체


뒤에서 부터 탐색해서
만약 a가 더 큰게 이미 있다?
그럼 앞에부터 a가 더 크면 무조건 바꿈

근데 a가 큰게 없고 계속 b가 더 크다면?
정렬 안된거야


*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        for(int i=0; i<n; i++) {
            cin>>b[i];
        }
        ll res = 0;
        for(int i=0; i<n; i++) {
            if(a[i]>b[i]) {
                int temp=a[i];
                a[i] = b[i];
                b[i] = temp;
            }
            res+=b[i];
        }
        res+=*max_element(a.begin(), a.end());
        cout<<res<<"\n";
    }
}