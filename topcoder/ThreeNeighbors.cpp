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
using int128 = __uint128_t;
using ii = pair<ll,ll>;
using vi = vector<ll>;
extern const int INF = INT_MAX - 5;
extern const ll LINF = LLONG_MAX - 5;
extern const int MOD = 1e9 + 7;
// extern const int N = 2e6 + 100;
extern const double EPS = 1e-12;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int count(vector<string> v) {
    int n = v.size();
    int m = v[0].size();
    // cout<<n<<" "<<m<<endl;
    for(int i = 0; i < n; ++i) {
        // assert(m == );
        if(m != (int)v[i].size()) return -1;
    }
    int p = 0;
    for(int i = 0; i < n; ++i) {
        for(int k = 0; k < m; ++k) {
            int tot = 0;
            if(v[i][k] == '.') {
                // cout<<i<<" "<<k<<endl;
                for(int j = 0; j < 8; ++j) {
                    int di = i + dx[j];
                    int dk = k + dy[j];
                    if(di >= 0 and di < n and dk >= 0 and dk < m) {
                        if(v[di][dk] == 'X') tot++;
                    }
                }
                if(tot == 3) p++;
            }
        }
    }
    return p;
}

class ThreeNeighbors {
    public:
    vector <string> construct(int N) {
        int p = N / 96;
        int rm = N % 96;
        // cout<<p<<" "<<rm<<endl;
        vector<string> ans;
        string cur1 = "", cur2= "";
        for(int i = 0; i < 50; ++i) cur1 += "X";
        for(int i = 0; i < 50; ++i) cur2 += ".";
        for(int i = 0; i < p; ++i) {
            if(i == 0) ans.emplace_back(cur1);
            ans.emplace_back(cur2);
            ans.emplace_back(cur2);
            ans.emplace_back(cur1);
        }
        if(rm > 0) {
            int d = rm / 2;
            ans.emplace_back(cur1);
            string cur3 = "";
            for(int i = 1; i <= 50; ++i) {
                if(i <= d + 2) cur3 += ".";
                else cur3 += "X";
            }
            ans.emplace_back(cur3);
            ans.emplace_back(cur3);
            ans.emplace_back(cur1);
            if(rm & 1) {
                string cur4 = "";
                ans.emplace_back(cur1);
                for(int i = 0; i < 50; ++i) {
                    if(i != 0) cur4 += "X";
                    else cur4 += ".";
                }
                ans.emplace_back(cur4);
            }
        }
        return ans;
    }
};
