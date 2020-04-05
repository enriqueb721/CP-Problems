#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
int t,n;
int main() {
    scanf("%d", &t);
    bool f = false;
    while(t--) {
        if(f) puts(""); else f = true;
        scanf("%d", &n);
        n *= 100;
        vi v; int p;
        while(scanf("%d", &p) != EOF and p > 0) v.emplace_back(p);
        vi acm((int) v.size() + 1);
        acm[0] = 0;
        vector<vi> dp = vector<vi>((int)v.size() + 100, vi(n + 100, 0));
        for(int i = 1; i < (int) acm.size(); ++i) acm[i] = acm[i - 1] + v[i - 1];
        int mxi = 0;
        for(int i = 1; i <= (int) v.size(); ++i) {
            for(int k = 1; k <= n; ++k) {
                if(v[i - 1] > k) dp[i][k] = dp[i - 1][k];
                else dp[i][k] = max(
                    dp[i - 1][k],
                    dp[i - 1][k - v[i - 1]] + v[i - 1]
                );
            }
            if(acm[i] - dp[i][n] <= n) mxi = i;
            else break;
        }
        set<int> st;
        for(int i = mxi, k = dp[mxi][n]; i >= 1; --i) {
            if(v[i - 1] > k) continue;
            else {
                if(dp[i - 1][k - v[i - 1]] == k - v[i - 1]) {
                    k -= v[i - 1];
                    st.emplace(i);
                }
            }
        }
        printf("%d\n", mxi);
        for(int i = 1; i <= mxi; ++i) {
            if(st.count(i)) printf("port\n");
            else printf("starboard\n");
        }
    }
    return 0;
}
