#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
/*
1. 점이 모두 같거나 (2개)
2. 겹치는게 아예 없거나
3. 겹치는게 하나가 있어야함 한 좌표
*/
bool check(int x1,int y1, int x2, int y2, int x3, int y3) {
    if(((x1==x2) && (y1==y2))|| ((x2==x3) && (y2==y3)) || ((x3==x1) && (y3==y1))) return false;
    int a = (x1-x2) * (x1- x2) + (y1-y2) * (y1-y2);
    int b = (x2-x3) * (x2-x3) + (y2-y3) * (y2-y3);
    int c = (x3-x1) * (x3-x1) + (y3-y1) * (y3-y1);
    if(a+b == c || b+c == a || a+c == b) return true;
    else {
        return false;
        
    }
}
void solve() {
    int x1, y1, x2, y2, x3, y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    if(check(x1, y1, x2, y2, x3, y3)) {
        cout<<"RIGHT\n";
        return;
    }

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int ans = false;
    for(int i=0; i<4; i++) {
        ans |= check(x1+dx[i], y1+dy[i], x2, y2, x3, y3);
        ans |= check(x1, y1, x2+dx[i], y2+dy[i], x3, y3);
        ans |= check(x1, y1, x2, y2, x3+dx[i], y3+dy[i]);
    }
    if(ans){
        cout<<"ALMOST\n";
        return;
    } else {
        cout<<"NEITHER\n";
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    solve();
}