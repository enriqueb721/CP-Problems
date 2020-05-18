#include <bits/stdc++.h>
using namespace std;
const int N = 60;
int n,m;
int a[N];
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int u,v; scanf("%d %d", &u, &v);
		a[u]++, a[v]++;
	}
	for(int i = 1; i <= n; ++i) {
		printf("%d\n", a[i]);
	}
	return 0;
}
