#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e3 + 10;
const int INF = INT_MAX;
int c[] = {5, 10, 20, 50, 100, 200};
int a[6];
ll dp[N];
int main() {
	for(int i = 0; i < N; ++i) dp[i] = INF; dp[0] = 0;
	for(int i = 0; i < 6; ++i) {
		for(int k = c[i]; k < N; k += 5) dp[k] = min(dp[k], dp[k - c[i]] + 1);
	}
	while(scanf("%d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]) != EOF) {
		int sm = 0;
		for(int i = 0; i < 6; ++i) sm += (c[i] * a[i]);
		if(sm == 0) break;
		int x,y;
		scanf("%d.%d", &x, &y);
		int v = x * 100 + y;
		sm++;
		ll cur[sm];
		for(int i = 0; i < sm; ++i) cur[i] = INF;
		cur[0] = 0;
		for(int i = 0; i < 6; ++i) {
			for(int j = sm; j >= 0; --j) {
				for(int k = 1; k <= a[i]; ++k) {
					if(j < k * c[i]) break;
					cur[j] = min(cur[j], cur[j - (k * c[i])] + k);
				}
			}
		}
		ll ans = INF;
		for(int i = v; i < sm; ++i) {
			if(i - v >= N) break;
			ans = min(ans, (ll)cur[i] + (ll)dp[i - v]);
		}
		printf("%3d\n", ans);
	}
	return 0;
}

