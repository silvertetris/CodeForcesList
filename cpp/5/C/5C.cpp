#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    int n = s.size();
    vector<int> d(n, -1);
    vector<int> c(n, -1);
    
    stack<int> st;

    for (int j = 0; j < n; j++) {
        if (s[j] == '(') {
            st.push(j);
        } 
        else {
            if (st.empty()) {
                continue;
            }
            
            d[j] = st.top();
            st.pop();
            c[j] = d[j];

            int prev_idx = d[j] - 1;
            if (prev_idx >= 0 && s[prev_idx] == ')' && c[prev_idx] != -1) {
                c[j] = c[prev_idx];
            }
        }
    }

    int max_len = 0;
    int count = 1;

    for (int j = 0; j < n; j++) {
        if (c[j] != -1) {
            int current_len = j - c[j] + 1;
            
            if (current_len > max_len) {
                max_len = current_len;
                count = 1;
            } else if (current_len == max_len) {
                count++;
            }
        }
    }

    cout << max_len << " " << count << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
    return 0;
}