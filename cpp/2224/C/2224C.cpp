#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<char> a(n);
        vector<char> b(n);
        int first = 0;
        int second = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i]=='(') {
                first++;
            }else second++;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            if(b[i]=='(') first++;
            else second++;
        }
        /*
        초장부터 )가 나오면 무조건 안됨
        개수가 다르면 안됨
        같으면 어차피 바꿔도 똑같음
        다를떄 비교해야함
        같은거 먼저 확인했으니 -> 다른것들 중에서 diff하나로 확인 가능
        일단 각각에 대해서 벨런스를 맞춤
        일단 주고 계산 -> )가 둘중 아무곳에서 있는 것들 중 초과한다면 그건 바꾸든 말든 어디서 안되는것임
        (이 너무 많은 쪽에다가 , )를 넣어줘야함
        */
        if(first!=second) {
            cout<<"NO\n";
            continue;
        }
        int countA=0;//열린거 기준
        int countB=0;
        bool flag = true;

        for(int i=0; i<n; i++) {
            if(a[i]!=b[i]) {
                if(a[i] = '(') {
                    if(countA<countB) {
                        a[i] = '(';
                        b[i] = ')';
                    }
                    else {
                        a[i] = ')';
                        b[i]='(';
                    }
                }
            }
            if(a[i] =='(') {
                countA++;
            }else {
                countA--;
            }
            if(b[i] == '(') {
                countB++;
            } else {
                countB--;
            }
            if(countA<0 || countB<0) {
                cout<<"NO\n";
                flag =false;
                break;
            }
        }
        if(flag) {
            if(countA==0 && countB==0) {
                cout<<"YES\n";
            }
            else {
                cout<<"NO\n";
            }
        }

        /*

        */
    }
}