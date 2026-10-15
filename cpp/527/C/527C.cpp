#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void cut(set<int>& pos, multiset<int>& len, int t) {
    pos.insert(t);
    int l = *prev(pos.find(t));   // 왼쪽 이웃
    int r = *next(pos.find(t));   // 오른쪽 이웃

    len.erase(len.find(r - l));   // 원래 구간 하나만 삭제
    len.insert(t - l);            // 쪼개진 두 구간 추가
    len.insert(r - t);
}

void solve() {
    int w, h, n;
    cin >> w >> h >> n;

    set<int> posW = {0, w};   // 세로 컷 위치
    set<int> posH = {0, h};   // 가로 컷 위치
    multiset<int> lenW = {w}; // 가로 구간 길이들
    multiset<int> lenH = {h}; // 세로 구간 길이들

    for (int i = 0; i < n; i++) {
        char op;
        int num;
        cin >> op >> num;

        if (op == 'H') cut(posH, lenH, num);
        else           cut(posW, lenW, num);

        ll maxW = *lenW.rbegin();
        ll maxH = *lenH.rbegin();
        cout << maxW * maxH << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--) {
        solve();
    }
}