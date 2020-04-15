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
int t,n;
string s;
vi find_min() {
    vi ret(n), pos;
    if(s[0] == '<') pos.emplace_back(0);
    for(int i = 1; i < (int) s.size(); ++i) {
        if(s[i - 1] == '>' and s[i] == '<') {
            pos.emplace_back(i);
        }
    }
    if(s[(int) s.size() - 1] == '>') pos.emplace_back(n - 1);
    // for(auto i : pos) cout<<i<<" "; cout<<endl;
    int c = 1;
    for(int i = (int) pos.size() - 1; i >= 0; --i) {
        ret[pos[i]] = c;
        c++;
    }
    for(int i = pos[pos.size() - 1] + 1; i < n; ++i) {
        ret[i] = c;
        c++;
    }
    for(int i = (int) pos.size() - 1; i >= 1; --i) {
        int r = pos[i] - 1, l = pos[i - 1];
        while(s[r] == '>' and s[r - 1] == '>') {
            ret[r] = c;
            r--, c++;
        }
        while(s[l] == '<' and s[l + 1] == '<') {
            ret[l + 1] = c;
            l++, c++;
        }
        ret[l + 1] = c;
        c++;
    }
    for(int i = pos[0] - 1; i >= 0; --i) {
        ret[i] = c;
        c++;
    }
    return ret;
}
vi find_max() {
    vi ret(n);
    vector<ii> rng;
    int ant = 0;
    for(int i = 0; i < (int) s.size(); ++i) {
        if(s[i] == '<') {
            rng.emplace_back(ant, i);
            ant = i + 1;
        }
    }
    rng.emplace_back(ant, n - 1);
    // for(auto i : rng) cout<<i.fst<<" "<<i.second<<endl;
    int c = 1;
    for(auto i : rng) {
        ret[i.second] = c;
        c++;
    }
    for(auto i : rng) {
        for(int k = i.second - 1; k >= i.first; --k) {
            ret[k] = c;
            c++;
        }
    }
    return ret;
}
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>s;
        vi mn = find_min();
        vi mx = find_max();
        for(int i = 0; i < n; ++i) {
            if(i != 0) cout<<" ";
            cout<<mn[i];
        } cout<<endl;
        for(int i = 0; i < n; ++i) {
            if(i != 0) cout<<" ";
            cout<<mx[i];
        } cout<<endl;
    }
    return 0;
}
