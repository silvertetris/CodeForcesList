#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int temp = n;
    cout << temp << " ";
    while (true)
    {

        int idx = temp - 1;
        if (idx == 0)
            break;
        
        bool flag = false;
        for (int i = idx; i >= 1; i--)
        {
            if (temp % i == 0)
            {
                temp = i;
                break;
            }
        }
        if (temp == 1)
        {
            cout << temp << " ";
            break;
        }
        else
        {
            cout << temp << " ";
        }
    }
    cout << "\n";
}