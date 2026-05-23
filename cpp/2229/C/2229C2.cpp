#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;
/*
prefix sum으로 일단 다 더해놓고
만약에 그 이후에 나온수가? 더 크다? 그럼 안바꿈

-1 -3 6 이런식이면 안바꿈
근데 -1 -3 4 여도 안바꿀듯
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        vector<ll> suffix(n, 0);
        vector<ll> prefix(n, 0);
        vector<ll> realPrefix(n, 0);
        vector<int> positives;
        
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin>>a[i];
            if(a[i]>0) {
                positives.push_back(i);
            }
        }
        prefix[0] = abs(a[0]);
        realPrefix[0] = a[0];
        for(int i=1; i<n; i++) {
            prefix[i]= prefix[i-1] + abs(a[i]);
            realPrefix[i] = realPrefix[i-1] + a[i];
        }
        int lastPositiveIdx = -1;
        suffix[n-1] = a[n-1];
        if(a[n-1]>0) {
            lastPositiveIdx = n-1;
        }
        for(int i=n-2; i>=0; i--) {
            if(lastPositiveIdx<0 && a[i]>0) {
                if(a[i]>0) {
                    lastPositiveIdx=i;
                }
            }
            suffix[i] = suffix[i+1] + a[i];
        }
        
        ll idx=lastPositiveIdx;
        ll best = suffix[0];
        /*
        체크해야하는건, 앞 prefix, 뒤 suffix
        가장 우측 인덱스를 찾아야함
        -> 지금 cur이 기준으로 그 앞은 다 양수로 바꿀거. 근데 최소 뒤에 하나의 양수가 남아야함
        suffix 하나가 더 있어야함
        앞에 양수인거 그리고 그뒤에 일반 prefix(구간 합) 그니까 다음 양수까지
        그니까 양수인 prefix + i보다 그 뒤에있는 양수까지의 구간합의 반전값 + 그 양수 인덱스+1 까지의 suffix
        */
        for(int i=0; i<positives.size()-1; i++) {

        }
    }
}
