#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int N = 2e5 + 10;
ll n,k;
ll fact[N];
ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}
ll mul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}
ll subs(ll a, ll b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}
ll bpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = mul(a, res);
        a = mul(a, a), b >>= 1;
    }
    return res;
}
ll inv(ll a) {
    return bpow(a, MOD - 2);
}
ll comb(ll a, ll b) {
    return mul(fact[a], mul(inv(fact[a - b]), inv(fact[b])));
}
void create_fact() {
    fact[0] = 1;
    for(int i = 1; i < N; ++i) fact[i] = mul(i, fact[i - 1]);
}
int main() {
    create_fact();
    scanf("%lld %lld", &n, &k);
    if(k >= n) puts("0");
    else if(k == 0) printf("%lld\n", fact[n]);
    else {
        ll fixed = n - k;
        ll ways = comb(n, fixed);
        ll ans = 0;
        bool adding = true;
        for(int i = fixed; i >= 0; --i) {
            ll c = comb(fixed, i);
            ll pw = bpow(i, n);
            ll res = mul(c, pw);
            // cout<<res<<endl;
            if(adding) ans = add(ans, res);
            else ans = subs(ans, res);
            adding = !adding;
        }
        ans = mul(ans, ways);
        ans = mul(ans, 2); // add columns
        printf("%lld\n", ans);
    }
    return 0;
}
