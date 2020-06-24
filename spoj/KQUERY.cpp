#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,q;
int a[N], ft[N];
int ans[N];
map<int, vector<int> > val;
map<pair<int, pair<int, int> >, int> idx;
priority_queue< pair<int, pair<int, int> >, deque<pair<int, pair<int, int> > > > pq;
map<int, int> in;
int lso(int i) {
	return i & (-i);
}
int get(int pos) {
	int res = 0;
	while(pos > 0) {
		res += ft[pos];
		pos -= lso(pos);
	}
	return res;
}
int get(int l, int r) {
	return get(r) - get(l - 1);
}
void upd(int pos, int val) {
	while(pos <= n) {
		ft[pos] += val;
		pos += lso(pos);
	}
}
int main() {
	set<int> nums;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		val[-a[i]].emplace_back(i);
		nums.emplace(a[i]);
	}
	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
		int l,r,k;
		scanf("%d %d %d", &l, &r, &k);
		nums.emplace(k);
		pq.push(make_pair(k, make_pair(l, r)));
		idx[make_pair(k, make_pair(l, r))] = i;
	}
	int dig = 1;
	for(auto i : nums) {
		in[i] = dig;
		dig++;
	}
	for(auto i : val) {
		while(!pq.empty() and in[abs(pq.top().first)] >= in[abs(i.first)]) {
			int p = idx[pq.top()];
			auto d = pq.top();
			pq.pop();
			ans[p] = get(d.second.first, d.second.second);
		}
		if(pq.empty())
			break;
		for(auto j : i.second)
			upd(j, 1);
	}
	while(!pq.empty()) {
		int p = idx[pq.top()];
		auto d = pq.top();
		ans[p] = d.second.second - d.second.first + 1;
		pq.pop();
	}
	for(int i = 0; i < q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}

