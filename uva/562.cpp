#include <bits/stdc++.h>
using namespace std;
const int N = 2e2;
const int INF = 1e9;
int t, n;
int v[N];
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		int d, sm = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
			sm += v[i];
		}
		bool dp[sm + 1], temp[sm + 1];
		for(int i = 0; i <= sm; ++i) dp[i] = false, temp[i] = false;
		dp[0] = true;
		int ans = sm;
		for(int i = 0; i < n; ++i) {
			for(int k = v[i]; k <= sm; ++k) if(dp[k - v[i]]) temp[k] = true;
			for(int k = v[i]; k <= sm; ++k) {
				dp[k] |= temp[k], temp[k] = false;
				if(dp[k]) ans = min(ans, abs(sm - 2 * k));
			}
			if(ans == 0) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}
