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
string a,b;
int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        cin>>a>>b;
        set<int> sa;
        bool ok = true;
        for(char c : a)
            sa.emplace(c);
        for(char c: b) {
            if(!sa.count(c)) {
                ok = false;
                break;
            }
        }
        if(!ok) {
            puts("-1");
            continue;
        }
        for(int i = 0; i < n; ++i) {
            if(a[i] < b[i]) {
                ok = false;
                break;
            }
        }
        if(!ok) {
            puts("-1");
            continue;
        }
        map<int, deque<int> > mpa;
        map<int, vector<int> >mpb;
        for(int i = 0; i < n; ++i) {
            if(a[i] != b[i]) {
                mpb[b[i]].emplace_back(i);
            }
            mpa[a[i]].emplace_back(i);
        }
        vector< pair<int, vector<int> > > v;
        for(auto i : mpb) {
            v.push_back(i);
        }
        reverse(v.begin(), v.end());
        vector< set<int> > ans;
        for(auto i : v) {
            set<int> cur;
            for(int k : i.second)
                cur.emplace(k);
            cur.emplace(mpa[i.first][0]);
            ans.emplace_back(cur);
        }
        cout<<(int) ans.size()<<endl;
        for(auto i : ans) {
            cout<<(int) i.size();
            for(int k : i) {
                cout<<" "<<k;
            } cout<<endl;
        }
    }
    return 0;
}
