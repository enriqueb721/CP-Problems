#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
ll n,k;
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>k;
        if(k >= n) {
            puts("1");
        } else {
            vector<ll> div;
            for(ll i = 1; i * i <= n; ++i) {
                if(n % i == 0) {
                    div.emplace_back(i);
                    div.emplace_back(n / i);
                }
            }
            sort(div.begin(), div.end());
            ll ans = n;
            for(int i = 0; i < (int) div.size(); ++i) {
                if(div[i] > k) break;
                ans = min(ans, n / div[i]);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}