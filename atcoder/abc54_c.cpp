#include <bits/stdc++.h>
using namespace std;
const int N = 10;
vector<int> g[N];
bool vis[N];
int n,m;
int dfs(int from, int tot) {
	for(int to : g[from]) if(!vis[to]) {
		vis[to] = true;
		tot = dfs(to, tot);
		vis[to] = false;
	}
	bool ok = true;
	for(int i = 1; i <= n; ++i) if(!vis[i]) ok = false; if(ok) tot++;
	return tot;
}
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		g[u].emplace_back(v); g[v].emplace_back(u);
	}
	vis[1] = true;
	int ans = dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}
