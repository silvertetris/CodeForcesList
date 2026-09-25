#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
int n, x;
vector<int> a;
vector<bool> isPrime;
vector<int> primes;
void solve() {
    cin>>n>>x;
    a.assign(n, 0);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    if(x==1) {
        cout<<0<<"\n";
        return;
    }
    ll ans = 0;
    vector<int> xPrime;
    for(auto i=0; i<primes.size(); i++) {
        if(x%primes[i]==0) {
            xPrime.push_back(primes[i]);
            while(x%primes[i]==0) {
                x/=primes[i];
            }
        }
    }

    for(int i=0; i<xPrime.size(); i++) {
        ll temp = 0;
        for(int j=0; j<n; j++) {
            if(a[j]%xPrime[i]==0) {
                temp+=a[j];
            }
        }
        ans = max(ans, temp);
    }
    cout<<ans<<"\n";
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);
    isPrime.assign(3*1e5+1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(auto i=2; i*i<=3*1e5; i++) {
        if(isPrime[i]) {
            for(auto j=i*i; j<=3*1e5; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    for(int i=0; i<=3*1e5; i++) {
        if(isPrime[i]) primes.push_back(i);
    }
    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}