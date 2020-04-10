#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
ll n, k;
ll bpow(ll a, ll b, ll mod = 1000) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod, b >>= 1;
    }
    return ret;
}
int main() {
    scanf("%d", &t);
    for(int cas = 1; cas <= t; ++cas) {
        scanf("%lld %lld", &n, &k);
        double nlog = log10((double)n) * (double)k;
        ll p = nlog;
        nlog -= (double)p;
        ll most = (double)powl((double)10.0f, nlog) * (double)100.0f;
        ll least = bpow(n, k);
        string s_least = to_string(least);
        while((int) s_least.size() < 3) s_least = "0" + s_least;
        printf("Case %d: %lld ", cas, most); cout<<s_least<<"\n";
    }
    return 0;
}