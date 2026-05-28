#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string s; 
        cin >> s;
        const int INF = 2e9-10000000;
        int n = s.size();
        /*
        #1. states/subproblems
        dp0 = 앞에가 홀수가 나오지 않았을 때 제거 최소 수, 항상 홀수가 없는 state를 유지했을 때임
        dp1 = 앞에가 홀수가 나왔을 때 제거 최소 수
        */
        vector<int> dp0(n+1);
        vector<int> dp1(n+1);
        //#2. Base Cases
        dp0[0] = 0;
        dp1[0] = INF;
        //#3. transitions
        for(int i=1; i<=n; i++) {
            if(s[i-1] == '4') {//4나오면 무조건 지워줘야함
                dp0[i]=dp0[i-1]+1;
                dp1[i]=dp1[i-1]+1;
            } else if(s[i-1]=='2') {//앞에 홀수 있다면 dp1++
                dp0[i]=dp0[i-1];
                dp1[i]=dp1[i-1] +1;//홀짝이니까 지워야함
            } else {//1, 3
                dp0[i] = dp0[i-1] +1;//홀수 나왔으니까 지워야함
                dp1[i]=min(dp0[i-1], dp1[i-1]);//홀수가 있다? 그럼 여태 홀수 지운걸 선택할지, 짝수지우는 걸 선택할지
            }
        }
        //#4. final answer
        cout << min(dp0[n], dp1[n]) << "\n";
    }
}