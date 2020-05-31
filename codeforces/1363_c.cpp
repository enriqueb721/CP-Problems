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
extern const int N = 1e3 + 100;
int t,n,x;
vector<int> g[N];
int dfs(int from, int par) {
    int c = 0;
    for(int to : g[from]) if(to != par) {
        c += dfs(to, from);
    }
    return c + 1;
}
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &x);
        for(int i = 0; i <= n; ++i) {
            g[i].clear();
        }
        for(int i = 0; i < n - 1; ++i) {
            int a,b; scanf("%d %d", &a, &b);
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        if(n == 1 or (int)g[x].size() == 1) {
            puts("Ayush");
            continue;
        }
        int ans = 0;
        for(int to : g[x]) {
            int c = dfs(to, x);
            ans += c;
        }
        ans--;
        // cout<<ans<<endl;
        if(ans % 2 == 0) puts("Ayush");
        else puts("Ashish");
    }
    return 0;
}
