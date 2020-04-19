#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2000;
int t,n;
ll v[N], d;
bool pred(ll p) {
    ll ml = p * v[0];
    for(int i = 1; i < n; ++i) {
        if(v[i] > ml) ml = v[i];
        else if(ml % v[i] != 0) {
            ll div = ml / v[i];
            ml = v[i] * (div + 1);
        }
    }
    return ml > d;
}
int main() {
    cin>>t;
    for(int cas = 1; cas <= t; ++cas) {
        cin>>n>>d;
        for(int i = 0; i < n; ++i) cin>>v[i];
        ll lo = 1, hi = d / v[0];
        while(lo < hi) {
            ll mid = lo + (hi - lo + 1) / 2;
            if(pred(mid)) hi = mid - 1;
            else lo = mid;
        }
        ll ans = lo * v[0];
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
    return 0;
}
