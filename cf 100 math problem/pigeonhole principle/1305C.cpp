#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const int M = 1e3 + 10;
int n,m;
ll v[N];
ll nxt[N];
ll ans = 1;
ll add(ll a, ll b) {
    return ((a % m) + (b % m)) % m;
}
ll sub(ll a, ll b) {
    return ((a % m) - (b % m) + m) % m;
}
ll mul(ll a, ll b) {
    return ((a % m) * (b % m)) % m;
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) scanf("%lld", &v[i]);
    if(n > m) {
        puts("0");
    } else {
        sort(v, v + n); reverse(v, v + n);
        for(int i = 0; i < n; ++i) {
            for(int k = 0; k < m; ++k) {
                if(nxt[k] > 0) {
                    ll p = sub(k, v[i]);
                    ans = mul(mul(p, nxt[k]), ans);
                }   
            }
            nxt[v[i] % m]++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}