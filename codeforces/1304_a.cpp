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
ll t,x,y,a,b;
int main() {
    cin>>t;
    while(t--) {
        cin>>x>>y>>a>>b;
        ll dif = labs(x - y);
        ll sm = a + b;
        if(dif % sm == 0) cout<<dif / sm<<endl;
        else puts("-1");
    }
    return 0;
}
