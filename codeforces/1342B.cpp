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
char s[N];
char comple(char c) {
    return c == '0' ? '1' : '0';
}
int main() {
    cin>>t;
    while(t--) {
        scanf("%s", s);
        int n = strlen(s);
        char f = s[0];
        bool all = true;
        forn(i, n) {
            if(f != s[i]) all = false;
        }
        if(all) {
            for(int i = 0; i < n; ++i) {
                cout<<f;
            } cout<<endl;
        } else {
            for(int i = 0; i < 2 * n; ++i) {
                cout<<f;
                f = comple(f);
            } cout<<endl;
        }
    }
    return 0;
}
