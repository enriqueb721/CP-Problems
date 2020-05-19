#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
using ll = long long;
int n;
ll a[N];
int main() {
	cin>>n;
	for(int i = 0; i < n; ++i) cin>>a[i];
	set<int> st;
	for(int i = 0; i < n; ++i) st.emplace(a[i]);
	if((int) st.size() == n) puts("YES");
	else puts("NO");
	return 0;
}
