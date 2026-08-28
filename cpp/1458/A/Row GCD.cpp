#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    int a[200001]={0,};
    int b[200001]={0,};
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    for(int i=0; i<m; i++) {
        cin>>b[i]; //get it as sorted array..??
    }
}