#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
using ll = long long;
int n;
ll k;
ll a[N];
bool pred(ll m) {
	ll tot = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i] < 0) {
			ll l = -1, r = n;
			while(r - l > 1) {
				ll mid = (l + r) / 2;
				if(a[i] * a[mid] <= m)
					r = mid;
				else
					l = mid;
			}
			tot += (n - r);
		} else {
			ll l = -1, r = n;
			while(r - l > 1) {
				ll mid = (l + r) / 2;
				if(a[i] * a[mid] <= m)
					l = mid;
				else
					r = mid;
			}
			tot += r;
		}
		if(a[i] * a[i] <= m) tot--;
	}
	tot /= 2;
	return tot >= k;
}
int main() {
	scanf("%d %lld", &n, &k);
	for(int i = 0; i < n; ++i)
		scanf("%lld", &a[i]);
	sort(a, a + n);
	// pred(-7);
	// return 0;
	ll lo = -2e18, hi = 2e18;
	while(hi - lo > 1) {
		ll mid = (lo + hi) / 2;
		if(pred(mid))
			hi = mid;
		else
			lo = mid;
	}
	ll ans = hi;
	printf("%lld\n", ans);
	return 0;
}

