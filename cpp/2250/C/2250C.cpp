#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n;
vector<int> l;
vector<int> r;
vector<int> u;
vector<int> v;
void solve() {
    cin>>n;
    l.assign(n+1, 0);
    r.assign(n+1, 0);
    u.assign(n+1, 0);
    v.assign(n+1, 0);
    for(int i=1; i<=n; i++) {
        cin>>l[i]>>r[i]>>u[i]>>v[i];
    }
    int m = n;
    //int i=1부터 시작해서, 1안되면 2부터 시작하는걸로 바꿈 -> 그니까 안되면 기존꺼 유지하다가, 다음으로 건너뜀 근데 j는 순차적
    //j, m-j+1
    /*
    1. 왼쪽 오른쪽 랭크 초기화
    2. 지우면 m을 지움
    3. 지우면 모든 랭크가 바뀜 -> 모든 랭크를 확인해야함
    4. 안되는놈을 계속 지움
    */
    vector<pair<int, pair<int, int>>> sub(n+1, {0, {0,0}});
    for(int i=1; i<=n; i++) {
        sub[i] = {i, {i, m-i+1}};
    }
    while(true) {
        bool flag = false;

        for(int i=n; i>=1; i--) {
            if(sub[i].first ==0) continue;
            if((sub[i].second.first<l[i] || sub[i].second.first>r[i]) && (sub[i].second.second<u[i] || sub[i].second.second>v[i])) {
                continue;
            }else {
                sub[i] = {0, {0, 0}};
                flag = true;
                m--;
                break;
            }
        }
        if(!flag) {
            break;
        }
        int idx = m;
        for(int i=n; i>=1; i--) {
            if(sub[i].first==0) continue;
            sub[i] = {idx, {idx, m-idx+1}};
            idx--;
        }
    }
    cout<<m<<"\n";
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