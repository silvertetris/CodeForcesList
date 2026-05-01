#include <bits/stdc++.h>

using namespace std;

#define long long ll

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(2*n);
        for(int i=0; i<2*n; i++) {
            cin>>a[i];
        }
        int mex = 1;
        /*
        2n 사이즈 a
0에서 n-1까지 두번씩만 나옴
팰린드롬인 부분배열 찾기
mex가 최대인 팰린드롬


0 5 4 2 2 4 5 0 3 3

dp 10^10 안됨

그리디
순열이니까 visited를 이용
아니지 그니까 하나씩 증가해서 팰린드롬 확인되면 거기서 확장 후에 있으면 그냥 맨 끝자락 부터 다시 시작해도 됨.

        */
        for(int i=1; i<2*n; i++) {
            int idx =-1;
            if(a[i] == a[i-1]) {
                vector<bool> visited(n+1, false);
                int l= i-1;
                int r= i;
                while(l>=0 && r<2*n && a[l] == a[r]) {
                    l--;
                    r++;
                }
                for(int j=l+1; j<r-1; j++) {
                    visited[a[j]]=true;
                }
                int temp =0;
                while(visited[temp]) {
                    temp++;
                }
                mex = max(mex, temp);
                idx = max(idx, r);
            }
            if(i<2*n-1 && a[i-1] == a[i+1]) {
                int l= i-1;
                int r= i+1;
                vector<bool> visited(n+1, false);
                while(l>=0 && r<2*n && a[l] == a[r]) {
                    l--;
                    r++;
                }
                for(int j=l+1; j<r-1; j++) {
                    visited[a[j]]= true;
                }
                int temp=0;
                while(visited[temp]) {
                    temp++;
                }
                mex = max(mex, temp);
                idx= max(idx, r);
            }
            if(idx !=-1) {
                i = idx;
            }
        }
        cout<<mex<<"\n";
    }
}