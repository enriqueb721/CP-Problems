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
int n,k;
int m[N], c[N], pos[N];
map<ll, ll> mp;
vector< vi > v;
int main() {
    cin>>n>>k;
    forn(i, n) {
        cin>>m[i];
        mp[-m[i]]++;
    }
    set<int> st;
    for(int i = 0; i < n; ++i) st.emplace(-m[i]);
    forn(i, k) cin>>c[i];
    reverse(c, c + k);
    for(int i = 0, p = k; i < k; ++i, --p) pos[i] = -p;
    int ans = 0;
    while((int) mp.size() > 0) {
        auto top = mp.begin();
        vi cur;
        int tot = 0;
        bool f = true;
        while((int) mp.size() > 0) {
            if(!f) {
                auto it = upper_bound(c, c + k, tot);
                int cur_pos = it - c;
                if(cur_pos >= k) break;
                int num = pos[cur_pos];
                auto it2 = st.lower_bound(num);
                if(it2 == st.end()) break;
                top = mp.find(*it2);
            }
            top->second--;
            cur.emplace_back(-top->first);
            if(top->second == 0) {
                st.erase( st.find(top->first) );
                mp.erase(top);
            }
            tot++;
            f = false;
        }
        v.emplace_back(cur);
        ans++;
    }
    cout<<ans<<endl;
    for(int i = 0; i < (int) v.size(); ++i) {
        cout<<(int) v[i].size()<<" ";
        for(int j = 0; j < (int) v[i].size(); ++j) {
            if(j != 0) cout<<" ";
            cout<<v[i][j];
        } cout<<endl;
    }
    return 0;
}
