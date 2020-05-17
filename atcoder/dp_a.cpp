#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int v[N], dp[N];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
	for(int i = n - 2; i >= 0; --i) {
		if(i == n - 2) dp[i] = abs(v[i] - v[i + 1]);
		else dp[i] = min(
			abs(v[i] - v[i + 1]) + dp[i + 1],
			abs(v[i] - v[i + 2]) + dp[i + 2]
		);
	}
	printf("%d\n", dp[0]);
	return 0;
}
