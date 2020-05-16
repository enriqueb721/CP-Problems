#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
ll n,k;
ll v[N];
int main() {
	cin>>n>>k;
	for(int i = 0; i < n; ++i) {
		cin>>v[i];
	}
	sort(v, v + n);
	reverse(v, v + n);
	ll ans = 0;
	for(int i = k; i < n; ++i) {
		ans += v[i];
	}
	cout<<ans<<endl;
	return 0;
}
