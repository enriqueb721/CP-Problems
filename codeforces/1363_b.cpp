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
string s;
int main() {
    cin>>t;
    while(t--) {
        cin>>s;
        int n = s.size();
        vector< pair<int, int> > v;
        int ant = s[0] - '0', c = 0;
        for(int i = 0; i < n; ++i) {
            if(ant == (s[i] - '0')) {
                c++;
            } else {
                v.emplace_back(ant, c);
                c = 1;
                ant = s[i] - '0';
            }
        }
        if(c > 0) v.emplace_back(ant, c);
        int mn = n;
        int sm0 = 0, sm1 = 0;
        for(int i = 0; i < (int) v.size(); ++i) {
            if(i & 1) {
                sm1 += v[i].second;
            } else {
                sm0 += v[i].second;
            }
        }
        mn = min(mn, min(n - sm0, n - sm1) );
        int cur0 = 0, cur1 = 0;
        for(int i = 0; i < (int) v.size(); ++i) {
            if(i & 1) {
                cur1 += v[i].second;
                sm1 -= v[i].second;
                mn = min(mn, n - sm0 - cur1);
            } else {
                cur0 += v[i].second;
                sm0 -= v[i].second;
                mn = min(mn, n - sm1 - cur0);
            }
        }
        cout<<mn<<endl;
    }
    return 0;
}
