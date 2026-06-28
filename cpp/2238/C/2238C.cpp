#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n;
/*
n 집 
1 부터 n 까지
1 루트 노드임
임의 v 와 그 섭트리
v랑 정확히 거리가 h인 서브트리 를 길드에 포함
0이면 h만 길드임
그니까 높이를 세야함
높이가 중요함 깊이 기준으로 거리가 갈림
아 근데 h 가 다양함 모든 h 에 대해서 -> 최대 깊이 ->1개
모든 경우의 수를 더해야함 서로 다른 길드 개수
일반화 방법
-> 경우의 수 더하니까 tree dp?
각 높이에 내려갈때마다 경우의 개수 추가 -> 그니까 리치가는 h가 증가할때마다
h가 클수록 더 다양해지지만 더 커질수록 줄어짐 특정 분기점이 있음
아님 커질수록 커지는게 아니라 기준이 -> 특정 가리는 분기점을 만날때마다 증가함
트리 dp 임 h누적
자식부터 시작
자식쪽에서 같은 부모로 모인다 -> 분기점임 -> 추가로 종류가 증가 -> 높이가 같은데 다른곳으로 가면 그 특정 결국 뭉치는 서브트리의 부모로만 만들 수 있음 근데 -> 밑에 펼쳐지면 거기가 분기점임
그니까 -< 분기점이? 2개로? 2단으로 나눠짐

*/
vector<int> parents;
void solve() {
    cin>>n;
    parents.resize(n+1);
    for(int i=2; i<=n; i++) {
        int u;
        cin>>u;
        parents[i] = u;
    }

    /*
    #1. states/subproblems
    dp[i][j] = i 정점에서 깊이가 높은 놈의 높이 좌, 우 -> 깊은놈 얕은놈
    그니까 dp[i][0]이 1순위니까 여기다 전이

    */
   //#2. Base Cases
    vector<vector<int>> dp(n+1, vector<int> (2, 0));
    /*
    #3. transitions
    부모가 더 높이가 높다?
    */
    for(int i=n; i>=2; i--) {
        if(dp[i][0]+1> dp[parents[i]][0]) {
            dp[parents[i]][1] = dp[parents[i]][0];
            dp[parents[i]][0] = dp[i][0]+1;
        } else if(dp[i][0]+1>dp[parents[i]][1]) {
            dp[parents[i]][1] = dp[i][0]+1;
        } else{
            continue;
        }
    }
    ll ans = 0;
    for(int i=1; i<=n; i++) {
        if(dp[i][1]>=0) {
            ans+=dp[i][1]+1;
        }
    }
    cout<<ans<<"\n";
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}