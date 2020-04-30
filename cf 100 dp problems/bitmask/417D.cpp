#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int N = 200;
const int MAX = (1 << 22) + 10;
const ll INF = LLONG_MAX - 5;
ll n,m,b;
struct friends{
    ll x,k,m,mask;
    bool operator<(const friends &other) const {
        return k < other.k;
    }
} f[N];
ll dp[MAX];
int main() {
    for(int i = 0; i < MAX; ++i) dp[i] = INF;
    scanf("%lld %lld %lld", &n, &m, &b);
    for(int i = 0; i < n; ++i) {
        scanf("%lld %lld %lld", &f[i].x, &f[i].k, &f[i].m);
        for(int j = 0; j < f[i].m; ++j) {
            int d; scanf("%d", &d);
            f[i].mask |= (1 << (d - 1));
        }
    }
    sort(f, f + n);
    dp[0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int k = 0; k < (1 << m); ++k) {
            if(dp[k] != INF) {
                int new_mask = (k | f[i].mask);
                ll add = (new_mask == ((1 << m) - 1)) ? f[i].k * b : 0;
                dp[new_mask] = min(
                    dp[new_mask],
                    dp[k] + f[i].x + add
                );
            }
        }
    }
    if(dp[(1 << m) - 1] == INF) puts("-1");
    else printf("%lld\n", dp[(1 << m) - 1]);
    return 0;
}
