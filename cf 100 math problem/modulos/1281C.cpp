#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;
int t, x, n;
char s[N];
ll mul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}
ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}
ll subs(ll a, ll b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &x);
        scanf("%s", s);
        n = strlen(s);
        for(int i = 0, right = n; right <= x - 1; ++i) {
            int times = s[i] - '0';
            int diff = right - (i + 1);
            while(times > 1 and right <= x - 1) {
                for(int k = 0, j = i + 1; k < diff and right <= x - 1; ++k, ++j) {
                    s[right] = s[j];
                    right++;
                }
                times--;
            }
        }
        ll ans = n;
        for(int i = 0; i < x; ++i) {
            int times = s[i] - '0';
            if(times == 1) continue;
            ll diff = subs(ans, i + 1);
            ans = add(
                i + 1,
                mul(times, diff)
            );
        }
        printf("%lld\n", ans);
    }
    return 0;
}
