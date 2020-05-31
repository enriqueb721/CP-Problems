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
// extern const int N = 2e5 + 200;

class Solution {
public:
    vector<vector<int> > g;
    set< pair<int, int> > st;
    int dfs(int from, int par) {
        int c = 0;
        for(int to : g[from]) if(to != par) {
            if(st.count({from, to}))
                c++;
            dfs(to, from);
        }
        return c;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        g = vector<vector<int> >(0);
        for(auto i : connections) {
            g[i[0]].emplace_back(i[1]);
            st.emplace_back(i[1], i[0]);
            g[i[1]].emplace_back(i[0]);
        }
        int ans = dfs(0, -1);
        return ans;
    }
};

int main() {
    return 0;
}
