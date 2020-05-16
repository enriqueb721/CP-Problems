#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX = 1e15 + 10ll;
ll h;
vector<ll> pw;
int main() {
	ll p = 1;
	while(p < MAX) {
		pw.emplace_back(p);
		p *= 2;
	}
	cin>>h;
	auto it = upper_bound(pw.begin(), pw.end(), h);
	int idx = it - pw.begin();
	ll ans = pw[idx] - 1;
	cout<<ans<<endl;
	return 0;
}
