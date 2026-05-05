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
    sort(a.begin(), a.end(), greater<int>());

    bool flag= false;
    int cnt = 1;
    for(int i=1; i<n; i++) {
        if(a[i]==a[i-1]) {
            cnt++;
        } else{
            flag = true;
            break;
        }
    }
    if(!flag) {//작은게 없으면
        if(cnt%2!=0) {
            cout<<"Conan\n";
        } else {
            cout<<"Agasa\n";
        }
    } else {
        cout<<"Conan\n";
    }
}