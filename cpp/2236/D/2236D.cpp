#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    /*
    
다음턴 부터는
y-x가 0과 k 사이에 있는 y만 골라야함 (마지막 고른 값이 x라면)
그리고 지움
이거 못하면 짐
그니까 가장 먼저 고르는게 Dabir한테 가장 불리한 수를 고르는거임
그래서 가장 작은 수를 고르는게 가장 Dabir한테 불리함
Egor이 이기게 해야함
첫턴은 무조건 젤 작은거
두번쨰 턴은 egor이 가장 큰걸 고름
여기서 한번 체크 -> k보다 작거나 같으면 ㄱㅊ
엥 이게 끝 아님? -> 아님 제일 큰걸 고르고 없애도, 차이가 k 보다 크면 클남
그냥 그리디틱 하게 다 없앨까 -> 가장 큰걸 고르는게 최적이 아닐 수 있음 홀 짝수에 따라 달라짐
-> 그냥 넘어갈 수 있는 총 숫자가 짝수인지 홀수인지만 판별 하면 답임 -> 다 고른다 칠때, 짝수면 YES 가 이김 홀수면 NO임
각 스탭에서 계수를 셈 그니까 담으로 넘어가는게 바로 끝낼 수 있으면 바로 끝내면 됨. 근데 끝까지 갔을때 넘어갈 수 있다? -> 그 다음스탭 cnt 세야지\
1. 다 같은 경우 33333
2. 넘어갈 수 있는데,
3. 넘어갈 수 없는데, 짝수개인 경우
어차피 최적 프롬프트는 egor이 정함
    */
    bool flag = false;//넘어갈 수 있냐
    bool res = false; //다 고른다 칠때
    for(int i=0; i<n; i++){
        int idx = i;
        for(int j = idx; j<n; j++) {
            if(a[j] != a[i]) {
                idx = j;
                break;
            }
            idx = n;
        }
        //3-0 = 3
        int cnt = idx - i;
        if(cnt%2==0) {
            cout<<"YES\n";
            return;
        }
        if(idx<n && a[idx]-a[i]<=k) {
            cout<<"YES\n";
            return;
        }
        i = idx-1;//++ 고려
    }
    cout<<"NO\n";
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