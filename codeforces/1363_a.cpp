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
int n,x;
int v[N];
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>x;
        int even = 0, odd = 0;
        forn(i, n) {
            cin>>v[i];
            if(v[i] & 1) odd++;
            else even++;
        }
        if(x & 1) {
            if(odd > 0) {
                x--;
                odd--;
            } else {
                puts("No");
                continue;
            }
            while(x > 1 and even > 1) {
                x-=2, even-=2;
            }
            while(x > 1 and odd > 1) {
                x-=2, odd -= 2;
            }
            if(x == 0) puts("Yes");
            else puts("No");
        } else {
            if(odd > 0 and even > 0) {
                x-= 2, odd--, even--;
            } else {
                puts("No");
                continue;
            }
            while(x > 1 and even > 1) {
                x-=2, even-=2;
            }
            while(x > 1 and odd > 1) {
                x-=2, odd -= 2;
            }
            if(x == 0) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
