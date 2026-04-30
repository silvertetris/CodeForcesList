#include <bits/stdc++.h>

using namespace std;

#define long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        /*for(int i=0; i<n; i++) {
            if(a[i]%6==0) {
                int temp =a[i];
                a.erase(a.begin() + i);
                a.insert(a.begin(), temp);
            }
        }
        for(int i=0; i<n; i++) {
            cout<<a[i]<<" ";
        }*/
        vector<int> six;
        vector<int> two;
        vector<int> three;
        vector<int> prime;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 6 == 0)
            {
                six.push_back(a[i]);
            }
            else if (a[i] % 3 == 0)
            {
                three.push_back(a[i]);
            }
            else if (a[i] % 2 == 0)
            {
                two.push_back(a[i]);
            }
            else
            {
                prime.push_back(a[i]);
            }
        }
        for (int i = 0; i < six.size(); i++)
        {
            cout << six[i] << " ";
        }
        for (int i = 0; i < three.size(); i++)
        {
            cout << three[i] << " ";
        }
        for (int i = 0; i < prime.size(); i++)
        {
            cout << prime[i] << " ";
        }
        for (int i = 0; i < two.size(); i++)
        {
            cout << two[i] << " ";
        }

        cout << "\n";
    }
}