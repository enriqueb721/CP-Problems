#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,c;
int a[N], b[N], dp[N][2];
int main() {
	scanf("%d %d", &n, &c);
	for(int i = 1; i < n; ++i) 
		scanf("%d", &a[i]);
	for(int i = 1; i < n; ++i)
		scanf("%d", &b[i]);
	dp[2][0] = a[1], dp[2][1] = b[1] + c;
	for(int i = 3; i <= n; ++i) {
		dp[i][0] = min(dp[i - 1][0] + a[i - 1], dp[i - 1][1] + a[i - 1]);
		dp[i][1] = min(dp[i - 1][0] + b[i - 1] + c,dp[i - 1][1] + b[i - 1]);
	}
	for(int i = 1; i <= n; ++i) {
		if(i != 1) printf(" ");
		printf("%d", min(dp[i][0], dp[i][1]));
	} puts("");
	return 0;
}

