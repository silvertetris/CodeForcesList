#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int MOD = 1e9 + 7;
    int h, w, n;
    cin >> h >> w >> n;
    long long dp[10000 + 1][100000 + 1] = {0};
    int stuckx[2001] = {0};
    int stucky[20001] = {0};
    int startx, starty = 1;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        stuckx[i] = x;
        stucky[i] = y;
    }

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        }
    }
}