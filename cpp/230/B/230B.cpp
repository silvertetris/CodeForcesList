#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    bool prime[1000001];
    fill(prime, prime+1000001, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i <= 1000000; i++) {
        if (prime[i]) {
            for (int j = 2 * i; j <= 1000000; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        long double temp;
        cin >> temp;
        long long root = sqrtl(temp);
        if (root * root == (long long)temp && prime[root]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
