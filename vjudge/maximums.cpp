#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n;
ll v[N];
ll ans[N];
int main() {
    cin>>n;
    for(int i = 0; i < n; ++i) cin>>v[i];
    ans[0] = v[0];
    int mx = v[0];
    for(int i = 1; i < n; ++i) {
        int sm = v[i] + mx;
        ans[i] = sm;
        mx = max(mx, sm);
    }
    for(int i = 0; i < n; ++i) {
        if(i != 0) cout<<" ";
        cout<<ans[i];
    } cout<<endl;
    return 0;
}
