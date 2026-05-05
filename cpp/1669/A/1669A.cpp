#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--) {
        int input;
        cin>>input;
        cout<<"Division ";
        if(input<=1399) {
            cout<<4;
        } else if(input<=1599 && input >=1400) {
            cout<<3;
        }
        else if(1600<=input && input<=1899) {
            cout<<2;
        }
        else {
            cout<<1;
        }
        cout<<"\n";
    }
}