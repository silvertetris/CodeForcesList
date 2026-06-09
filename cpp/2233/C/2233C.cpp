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
        int n, k;
        cin >> n >> k;
        string s = "";
        cin >> s;
        int firstidx = 0;
        int secondidx = n - 1;
        int entirefirst = 0;
        int entiresecond = 0;
        vector<bool> res(n, false);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                firstidx = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ')')
            {
                secondidx = i;
                break;
            }
        }
        for (int i = firstidx; i <= secondidx; i++)
        {
            if (s[i] == ')')
            {
                entiresecond++;
            }
            else
            {
                entirefirst++;
            }
        }
        int cnt = 0;
        while (true)
        {
            if (firstidx >= secondidx || cnt >= k)
                break;
            int a = 0;
            int b = 0;
            for (int i = firstidx; i <= secondidx; i++)
            {
                if (s[i] == '(')
                {
                    a++;
                }
                else
                {
                    break;
                }
            }
            for (int i = secondidx; i >= firstidx; i--)
            {
                if (s[i] == ')')
                {
                    b++;
                }
                else
                {
                    break;
                }
            }
            bool flag = false;
            if (a > b)
            {
                for (int i = secondidx; i >= firstidx; i--)
                {
                    secondidx--;

                    if (cnt >= k)
                        break;
                    if (s[i] == ')' && !flag)
                    {
                        res[i] = true;
                        cnt++;
                        entiresecond--;
                    }
                    else if (s[i] == '(')
                    {
                        flag = true;
                        entirefirst--;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else if (a < b)
            {
                for (int i = firstidx; i <= secondidx; i++)
                {
                    firstidx++;
                    if (cnt >= k)
                        break;
                    if (s[i] == '(' && !flag)
                    {
                        res[i] = true;
                        cnt++;
                        entirefirst--;
                    }
                    else if (s[i] == ')')
                    {
                        flag = true;
                        entiresecond--;
                    }
                }
            }
            else
            {
                if (entirefirst >= entiresecond)
                {
                    for (int i = secondidx; i >= firstidx; i--)
                    {
                        secondidx--;

                        if (cnt >= k)
                            break;
                        if (s[i] == ')' && !flag)
                        {
                            res[i] = true;
                            cnt++;
                            entiresecond--;
                        }
                        else if (s[i] == '(')
                        {
                            flag = true;
                            entirefirst--;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {
                    for (int i = firstidx; i <= secondidx; i++)
                    {
                        firstidx++;
                        if (cnt >= k)
                            break;
                        if (s[i] == '(' && !flag)
                        {
                            res[i] = true;
                            cnt++;
                            entirefirst--;
                        }
                        else if (s[i] == ')')
                        {
                            flag = true;
                            entiresecond--;
                        }
                    }
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(res[i]) {
                cout<<1;
            }else{
                cout<<0;
            }
        }
        cout<<"\n";
    }
}