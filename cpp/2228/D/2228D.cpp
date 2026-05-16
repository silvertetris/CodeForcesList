#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
/*
k1, k2는 내가 선택 그냥 사분면에 최소 1개 들어가있는 모든 경우의 수임 -> k1, k2모든 경우의 수에서
그럼 제일 튀어나온 점 기준으로 최대 최소 정하고
x 나 y 겹치는 애들 고려해야함
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> x(n);
        vector<int> y(n);
        for(int i=0; i<n; i++) {
            cin>>x[i]>>y[i];
        }

    }
}