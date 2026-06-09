#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--) {
        int n, x, y, z;
        cin>>n>>x>>y>>z;//목표, 맥심, 니키타, ai
        int first = 0;
        int firsttime =0;
        int second = 0;
        int secondtime=0;
        while(first<n) {
            first += x+y;
            firsttime++;
        }
        while(second<n) {
            if(secondtime>=z) {
                second+=10*y + x;
            }else {
                second+=x;
            }
            secondtime++;
        }
        cout<<min(firsttime, secondtime)<<"\n";
    }
}