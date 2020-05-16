#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll h,n;
ll v[N];
int main() {
	cin>>h>>n;
	ll sm = 0;
	for(int i = 0; i < n; ++i) {
		cin>>v[i];
		sm += v[i];
	}
	if(sm >= h) puts("Yes");
	else puts("No");
	return 0;
}
