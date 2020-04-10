#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t,n;
int main() {
    scanf("%d", &t);
    for(int cas = 1; cas <= t; ++cas) {
        scanf("%d", &n);
        ll ans = 0;
        if(n == 1) ans = 1;
        else {
            ll seq = -1, to = n;
            for(int i = 2; i <= n; ++i) {
                ll cur = n / i;
                ll diff = to - cur;
                ans += (i - 1) * diff;
                to = cur;
                if(cur < i) {
                    seq = cur; break;
                }
            }
            for(int i = seq; i >= 1; --i) ans += (n / i);
        }
        printf("Case %d: %lld\n", cas, ans);
    }
    return 0;
}