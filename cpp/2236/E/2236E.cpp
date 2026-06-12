#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    /*
    각 차이가 1이면 좋은 배열
그니까 1로 증가하는 배열
아 정렬 했을때임
아 그니까 
a는 정렬하면 안되고
그냥 같은 크기 구간 2개 골랐을때, 정렬하면 1차이여야한다
그게 최대 길이인거?
최소는 1일테고
배열 1이면 0
2 이상이면 무조건 최소 1
n^2 까지 됨
슬라이딩 윈도우
큰 크기부터 해서 처음부터 탐색, 그리고 그다음 subarray 잡음
그니까 어떤 특정수 하나가 나가면, 그 다음수는 똑같은 수가 들어와야함
아 그리고 겹치는게 없어야함
빈도수를 세야할듯 -> a_i 값도 6000 이하니까메모리 충분

윈도우에 들어올때마다
1. 큰거 - 작은거 = size-1
2. 시작 최소값 저장, -> 그거에서 탐색하고 끝지점, 최대값 +1 부터 다시 시작해야함
3. n/2 윈도우 사이즈 시작, 1 까지 줄임 n/2가 최대
*/

    if(n==1) {
        cout<<"0\n";
        return;
    }
    vector<int> cnt(6001, 0);
    vector<bool> indices(n+1, false);
    for(int i=n/2; i>=1; i--) {
        int 
    }
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