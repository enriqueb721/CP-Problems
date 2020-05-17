#include <bits/stdc++.h>
using namespace std;
const int N = 200;
vector<int> g[N], topo;
bool vis[N];
int n,m;
void dfs(int from) {
	for(int to : g[from]) if(!vis[to]) {
		vis[to] = true;
		dfs(to);
	}
	topo.emplace_back(from);
}
int main() {
	while(scanf("%d %d", &n, &m) != EOF and n + m > 0) {
		for(int i = 0; i < m; ++i) {
			int u,v; scanf("%d %d", &u, &v); g[u].emplace_back(v);
		}
		for(int i = 1; i <= n; ++i) vis[i] = false;
		for(int i = 1; i <= n; ++i) {
			if(!vis[i]) {
				vis[i] = true;
				dfs(i);
			}
		}
		reverse(topo.begin(), topo.end());
		for(int i = 0; i < (int) topo.size(); ++i) {
			if(i != 0) printf(" ");
			printf("%d", topo[i]);
		} puts("");
		topo.clear();
	}
	return 0;
}
