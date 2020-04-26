#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int N = 1e6 + 10;
vector<ll> v[N];
map<ll, ll> mp;
int n,c;
ll mul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}
ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}
ll bpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = mul(res, a);
        a = mul(a, a), b >>= 1;
    }
    return res;
}
ll inv(ll a) {
    return bpow(a, MOD - 2);
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &c);
        for(int k = 0; k < c; ++k) {
            ll num; scanf("%lld", &num);
            v[i].emplace_back(num);
            mp[num]++;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        ll sz = mul((int) v[i].size(), n);
        ll inver = inv(sz), invn = inv(n);
        for(int k : v[i]) {
            ll cur = mul(
                inver,
                mul(mp[k], invn)
            );
            ans = add(ans, cur);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
