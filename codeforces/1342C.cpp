/*
        FFFFFFFFFFFFFFFFFFFFFF
        F::::::::::::::::::::F
        F::::::::::::::::::::F
        FF::::::FFFFFFFFF::::F
          F:::::F       FFFFFF
          F:::::F
          F::::::FFFFFFFFFF
          F:::::::::::::::F
          F:::::::::::::::F
          F::::::FFFFFFFFFF
          F:::::F
          F:::::F
        FF:::::::FF
        F::::::::FF
        F::::::::FF
        FFFFFFFFFFF
*/
#include <bits/stdc++.h>
using namespace std;
#define debug(...) cout<<__FUNCTION__<<":"<<__LINE__<<": ";debugger(#__VA_ARGS__, __VA_ARGS__);
template<typename arg>
void debugger(const char* varname, arg&& var) { cout<<varname<<" = "<<var<<endl; }
template<typename arg, typename... args>
void debugger(const char* varnames, arg&& var, args&&... vars) {
    const char* comma = strchr(varnames + 1, ',');
    cout.write(varnames, comma - varnames)<<" = "<<var<<" | ";
    int sz = 1; if(isspace(comma[sz])) sz++;
    debugger(comma + sz, vars...);
}
#define forr(i, s, n) for(ll i=(ll)(s); i<(ll)(n); ++i)
#define forn(i, n) forr(i, 0, n)
#define eb(n) emplace_back(n)
#define endl '\n'
#define fst first
#define snd second
using ll = long long;
using ii = pair<ll,ll>;
using vi = vector<ll>;
extern const int INF = INT_MAX - 5;
extern const ll LINF = LLONG_MAX - 5;
extern const int MOD = 1e9 + 7;
extern const int N = 2e5 + 200;
int t;
ll ans[N];
ll gcd(ll a, ll b) {
    while(b) a %= b, swap(a, b);
    return a;
}
ll lcm(ll a, ll b) {
    return a * (b / gcd(a, b));
}
ll find(ll x, ll lc, ll mx) {
    ll res = 0;
    if(x < lc) res = min(x, mx - 1);
    else {
        ll div = x / lc;
        ll md = x % lc;
        // debug(div, md);
        res = (div - 1) * mx + mx - 1;
        res += min(md + 1, mx);
    }
    return x - res;
}
ll a,b,q;
int main() {
    cin>>t;
    while(t--) {
        cin>>a>>b>>q;
        bool all = false;
        if(a > b) swap(a, b);
        if(b % a == 0) {
            all = true;
        }
        // debug(all);
        ll mx = max(a, b);
        ll lc = lcm(a, b);
        /*debug(mx, lc);
        for(int i = 1; i <= 20; ++i) {
            cout<<i<<": "<<find(i, lc, mx)<<endl;
        }
        return 0;*/
        forn(i, q) {
            ll l, r;
            cin>>l>>r;
            ans[i] = find(r, lc, mx) - find(l - 1, lc, mx);
        }
        forn(i, q) {
            if(i != 0) cout<<" ";
            cout<<ans[i];
        } cout<<endl;
    }
    return 0;
}
