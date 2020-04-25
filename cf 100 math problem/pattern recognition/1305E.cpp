#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 10;
const ll MAX = 1e9;
int n;
ll m;
ll ans[N];
int main() {
    scanf("%d %lld", &n, &m);
    ll walk = 1, add = 0, cur = 0;
    bool fst = true;
    while(walk <= n) {
        if(fst) cur += add, fst = false;
        else cur += add, fst = true, add++;
        walk++;
    }
    if(m > cur) {
        puts("-1");
    } else {
        ll d = -1, sm = 0, it = 2;
        while(d < m) {
            sm++;
            d += sm, it++;
            if(d >= m) break;
            d += sm, it++;
        }
        ll bef = d - sm, diff = m - bef;
        ll p = it - (2 * diff - 1);
        bool ok = true;
        for(int i = 1; i <= n; ++i) {
            if(i < it) ans[i] = ans[i - 1] + 1;
            else if(i == it) ans[i] = ans[i - 1] + p;
            else ans[i] = ans[i - 1] + it;
            if(ans[i] > MAX) {
                ok = false;
                break;
            }
        }
        if(!ok) puts("-1");
        else for(int i = 1; i <= n; ++i) {
            if(i != 1) printf(" ");
            printf("%lld", ans[i]);
        } puts("");
    }
    return 0;
}
