#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = INT_MAX - 5;
const int N = 24;
ll dist[N][N];
ll dp[(1 << N) + 10], path[(1 << N) + 10];
int x,y;
int n;
pair<int, int> points[N + 10];
ll find_dist(pair<int, int> a, pair<int, int> b) {
    return pow(abs(a.first - b.first), 2) +
           pow(abs(a.second - b.second), 2);
}
int main() {
    for(int i = 0; i < (1 << N) + 10; ++i) dp[i] = INF;
    scanf("%d %d", &x, &y);
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int a,b; scanf("%d %d", &a, &b);
        points[i] = {a, b};
    }
    for(int i = 0; i < n; ++i) {
        for(int k = i; k < n; ++k) {
            dist[i][k] = dist[k][i] = find_dist(points[i], points[k]);
        }
    }
    dp[0] = 0;
    for(int i = 0; i < (1 << n); ++i) {
        int bit = 0;
        while(i & (1 << bit)) bit++;
        for(int k = 0; k < n; ++k) {
            if(!(i & (1 << k))) {
                int mask = i | (1 << bit) | (1 << k);
                ll start_to_end = find_dist({x, y}, points[bit]) +
                               find_dist(points[k], {x, y});
                if(dp[i] + dist[bit][k] + start_to_end < dp[mask]) {
                    path[mask] = i;
                    dp[mask] = dp[i] + dist[bit][k] + start_to_end;
                }
            }
        }
    }
    int mask = (1 << n) - 1;
    vector<int> ans;
    while(mask) {
        ans.emplace_back(0);
        int p = path[mask];
        for(int i = 0; i < n; ++i) {
            if((mask & (1 << i)) and !((mask & (1 << i)) & (p & (1 << i)))) {
                ans.emplace_back(i + 1);
            }
        }
        mask = p;
    }
    printf("%lld\n", dp[(1 << n) - 1]);
    for(int i = 0; i < (int) ans.size(); ++i) {
        if(i != 0) printf(" ");
        printf("%d", ans[i]);
    } puts(" 0");
    return 0;
}
