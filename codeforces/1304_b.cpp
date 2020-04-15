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
extern const int N = 200;
int n,m;
string s[N], rev[N];
bool take[N];
vector<ii> ans;
bool is_pal(const string &str) {
    for(int i = 0, k = (int) str.size() - 1; i < k; ++i, --k) {
        if(str[i] != str[k]) return false;
    }
    return true;
}
int main() {
    cin>>n>>m;
    forn(i, n) {
        cin>>s[i];
        rev[i] = s[i];
        reverse(rev[i].begin(), rev[i].end());
    }
    int count = 0;
    for(int i = 0; i < n; ++i) {
        if(take[i]) continue;
        for(int k = i + 1; k < n; ++k) {
            if(s[i] == rev[k]) {
                take[i] = take[k] = true;
                count+=(2 * m);
                ans.emplace_back(i, k);
                break;
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        if(!take[i]) {
            if(is_pal(s[i])) {
                count+= m;
                ans.emplace_back(i, i);
                break;
            }
        }
    }
    string sans = "";
    for(auto i : ans) {
        sans += s[i.first];
    }
    for(int i = (int) ans.size() - 1; i >= 0; --i) {
        if(ans[i].first != ans[i].second) sans += s[ans[i].second];
    }
    cout<<count<<endl;
    cout<<sans<<endl;
    return 0;
}
