#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 10;
const int MAX = 1e4 + 10;
const int INF = INT_MAX - 5;
int h,n;
int a[N], b[N];
ll dp[N][2 * MAX + 10];
int main() {
	cin>>h>>n;
	for(int i = 1; i <= n; ++i) {
		cin>>a[i]>>b[i];
	}
	for(int i = 0; i <= n; ++i) {
		for(int k = 0; k < 2 * MAX + 10; ++k) dp[i][k] = INF;
	}
	for(int i = 0; i <= n; ++i) {
		dp[i][0] = 0;
	}
	for(int i = 1; i <= n; ++i) {
		for(int k = 1; k < 2 * MAX + 10; ++k) {
			if(a[i] > k) dp[i][k] = dp[i - 1][k];
			else if(a[i] == k) {
				dp[i][k] = min(
					dp[i - 1][k],
					dp[i - 1][k - a[i]] + b[i]
				);
			} else {
				dp[i][k] = min(
					min(
						dp[i - 1][k],
						dp[i][k - a[i]] + b[i]
					),
					dp[i - 1][k - a[i]] + b[i]
				);
			}
		}
	}
	ll ans = INF;
	for(int i = h; i < 2 * MAX + 10; ++i) ans = min(ans, dp[n][i]); 
	cout<<ans<<endl;
	return 0;
}
