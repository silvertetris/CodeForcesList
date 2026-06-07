#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        vector<vector<int>> a (n, vector<int> (m));
        vector<vector<int>> b (n, vector<int> (m));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin>>a[i][j];
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin>>b[i][j];
            }
        }

        //각 세로, 가로는 순열임
        /*
        각 row, column이 반대쪽 배열과 순열이 포함-> 되면 yes 하나라도 각 set이나 배열에 없는 수나 없으면 NO
        1. row끼리 정렬
        2. column끼리 정렬함
        a 에서 각 위치가 뭐뭐인지 기록함 -> pair

        b에서 각각 순회하면서 위치랑 비교
        각 row, column 배열에 최종적으로 비교
        */
        int permut = n*m;
        vector<pair<int, int>> pos(n*m +1);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                pos[a[i][j]] = {i, j};
            }
        }
        bool flag = true;
        //row
        for(int i=0; i<n; i++) {//좌에서 우 i가 같은지 확인해야지
            if(!flag) break;
            int idx = pos[b[i][0]].first;
            for(int j=1; j<m; j++) {
                if(pos[b[i][j]].first != idx) {
                    flag = false;
                    break;
                }
            }
        }

        //column
        for(int i=0; i<m; i++) {
            if(!flag) break;
            int idx = pos[b[0][i]].second;
            for(int j=1; j<n; j++) {
                if(pos[b[j][i]].second != idx) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) {
            cout<<"Yes\n";
        }else {
            cout<<"No\n";
        }
    }
}