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
#include "bits/stdc++.h"
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
extern const double EPS = 1e-9;
extern const int INF = INT_MAX - 5;
extern const ll LINF = LLONG_MAX - 5;
extern const int MOD = 1e9 + 7;
extern const int N = 2e5 + 200;
int t;
int n;
int a[N], b[N];
int acm[N], bcm[N];
int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        forr(i, 1, n + 1) cin>>a[i];
        forr(i, 1, n + 1) cin>>b[i];
        for(int i = 1; i <= n; ++i) {
            acm[i] = a[i] + acm[i - 1];
            bcm[i] = b[i] + bcm[i - 1];
        }
        ll ans = 0;
        ll dist = 0;
        bool keep = true;
        for(int i = 1; i <= n; ++i) {
            if(acm[i] == bcm[i]) {
                if(keep) {
                    dist += a[i];
                } else {
                    keep = true;
                }
            } else {
                ans += dist;
                keep = false;
                dist = 0;
            }
        }
        if(dist > 0)
            ans += dist;
        cout<<ans<<endl;
    }
    return 0;
}
