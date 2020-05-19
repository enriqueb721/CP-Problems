#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int k,n;
double p[N];
double acm[N];
double sm(int p) {
	return (p * (p + 1)) / 2;
}
int main() {
	cin>>n>>k;
	for(int i = 1; i <= n; ++i) cin>>p[i];
	double temp = 0.0f;
	for(int i = 1; i < k; ++i) {
		acm[i] = sm(p[i]) * 1.0f / p[i];
		temp += acm[i];
	}
	double ans = 0;
	for(int i = k; i <= n; ++i) {
		temp -= acm[i - k];
		acm[i] = sm(p[i]) * 1.0f / p[i];
		temp += acm[i];
		ans = max(ans, temp);
	}
	printf("%.15lf\n", ans);
	return 0;
}
