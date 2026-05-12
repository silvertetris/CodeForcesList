#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<bool> types(n+1, false);

    for(int i=1; i<=n; i++) {
        bool temp;
        cin>>temp;
        if(temp) {
            types[i] = true;
        }
    }
    /*
    그니까 입력받은 것에서 인덱스 i 로 간다는 말
    최종적으로 k 로 가니까 각 k 에 대해서 dfs를 해주면 됨
    같은 수가 2개인건 안됨 -> 그니까 하나의 길만 있어야함 길이 있으면 안됨
    0이면 거기가 끝임
    1. 0이면 끝
    2. 길이 2개면 끝
    */
    vector<int> cnt(n+1, 0);//거꾸로 봤을때가 아니라 그냥 나가는 애가 2개인 애들
    vector<int> graph(n+1);
    for(int i=1; i<=n; i++) {
        int input;
        cin>>input;
        graph[i]=input;
        cnt[input]++;
    }

    vector<int> res;

    for(int i=1; i<=n; i++) {
        if(types[i]) {
            vector<int> temp;
            int idx = i;
            while(true) {
                if(idx==0) {
                    break;
                }
                temp.push_back(idx);
                int prev = graph[idx];
                if(prev!=0 && cnt[prev]==1) {
                    idx = prev;
                }
                else {
                    break;
                }
            }
            if(temp.size()>res.size()) {
                res = temp;
            }
        }
    }
    cout<<res.size()<<"\n";
    reverse(res.begin(), res.end());
    for(int i=0; i<res.size(); i++) {
        cout<<res[i]<<" ";
    }
    cout<<"\n";
}