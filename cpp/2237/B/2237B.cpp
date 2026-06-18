#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n;


void solve()
{
    cin >> n;
    vector<int> a(n); // 여기에 있는 max의 개수가 b에 있는 애들보다 더 크면 -1임
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<int> copya = a;
    vector<int> copyb = b;
    sort(copya.begin(), copya.end());
    sort(copyb.begin(), copyb.end());

    for (int i = 0; i < n; i++)
    {
        if (copya[i] > copyb[i])
        {
            cout << "-1\n";
            return;
        }
    }
    ll res  = 0;
    bool flag = false;
    while(1) {
        if(flag) break;
        bool swapped = false;  
        for(int i=1; i<n; i++) {
            if(a[i-1]>b[i-1]) {
                int idx = i-1;//b보다 같거나 작은애를 끌어와야함
                for(int j=i-1; j<n; j++) {
                    if(a[j]<=b[i-1]) {
                        idx = j;
                        break;
                    }
                }
                for(int j=idx; j>i-1; j--) {
                    swap(a[j], a[j-1]);
                    res++;
                    swapped = true; 
                }
            }
        }
        flag= true;
        for(int i=0; i<n; i++) {
            if(a[i]>b[i]) {
                flag = false;
                break;
            }
        }
        if(!swapped) break; 
    }
    cout<<res<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}