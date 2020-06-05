#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int n,m;
vector<int> g[N];
int top[N];
vector<int> ans;
int col[N];
vector< pair<int, int> > comp;
bool valid(int from) {
	comp.emplace_back(top[from], from);
	col[from] = 1;
	set<int> st;
	for(int to : g[from]) {
		if(top[to] < top[from])
			st.emplace(top[to]);
		else if(top[to] == top[from])
			return false;
	}
	// cout<<from<<" "<<top[from]<<" "<<st.size()<<endl;
	if(top[from] - 1 != (int) st.size())
		return false;
	st.clear();
	for(int to : g[from]) {
		if(col[to] == 0) {
			bool res = valid(to);
			if(!res)
				return false;
		}
	}
	return true;
}
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int a,b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	} 
	for(int i = 1; i <= n; ++i)
		scanf("%d", &top[i]);
	bool ok = true;
	for(int i = 1; i <= n; ++i) {
		if(col[i] == 0) {
			comp.clear();
			bool val = valid(i);
			if(!val) {
				ok = false;
				break;
			}
			sort(comp.begin(), comp.end());
			for(auto j : comp) {
				ans.emplace_back(j.second);
			}
		}
	}
	if(!ok)
		puts("-1");
	else {
		for(int i = 0; i < (int) ans.size(); ++i) {
			printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}
