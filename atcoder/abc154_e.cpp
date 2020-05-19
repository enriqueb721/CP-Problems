#include <bits/stdc++.h>
using namespace std;
const int N = 200;
using ll = long long;
string n;
int k;
ll dp[N][5];
int main() {
	cin>>n>>k;
	reverse(n.begin(), n.end());
	int sz = (int) n.size();
	dp[0][0] = 1;
	for(int i = 1; i < sz; ++i) {
		dp[i][0] = 1ll;
		for(int j = 1; j <= k; ++j) {
			dp[i][j] = (9ll * dp[i - 1][j - 1]) + dp[i - 1][j]; 
		}
	}
	ll ans = 0;
	for(int i = sz - 1, j = k; i >= 0 and j >= 0; --i, --j) {
		if(j == 0) {
			ans++;
			break;
		}
		ll num = n[i] - '0';
		if(num == 0) {
			j++;
			continue;
		}
		ans += dp[i][j];
		int l = 1;
		if(i == 0) l = 0;
		ans += ((num - l) * dp[i][j - 1]);
	}
	cout<<ans<<endl;
	return 0;
}

