#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9;
int n,k;
int h[N];
int dp[N];
int main() {
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &h[i]);
		dp[i] = INF;
	}
	dp[n - 1] = 0;
	for(int i = n - 2; i >= 0; --i) {
		for(int j = 1; j <= k and i + j < n; ++j) {
			dp[i] = min(dp[i], dp[i + j] + abs(h[i] - h[i + j]));
		}
	}
	printf("%d\n", dp[0]);
	return 0;
}
