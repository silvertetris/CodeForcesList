#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    /*
    그니까 1 칸 아니면 2칸을 뛸 수 있는데,
극한까지 미루다가 1..n까지 도달할 수 있는 그 극한 제한 day

7 0 2 7

8 0 6 1 3

음수가 2개 consecutive하면 끝임

한번 다 빼고? -> 안됨

시작 지점 끝 지점이 중요함 -> 1번 케이스
그리고 중간지점은 그 지점 - 시간
연속된 지점은 -> 결국 큰 애들한테 뜀 -> 그러면 양옆에 작은 애들은 무시해도됨 -> 큰값중에서 작은걸 뽑음
*/
    int con = min(a[0], a[n-1]);
    int temp = 10000000;
    for(int i=1; i<n-1; i++) {
        temp = min(temp, max(a[i], a[i+1]));
    }
    int ans = min(con, temp);

    cout<<ans<<"\n";
}