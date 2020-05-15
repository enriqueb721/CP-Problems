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
extern const int N = 2e6 + 100;
extern const double EPS = 1e-12;
#define LSone(s) (s & (-s))

class SwapTheString {
    public:
    int a[N], m;
    vi t;
    void inc(int i, int d) {
        for(i++; i <= m; i += LSone(i)) t[i] += d;
    }
    ll rsq(int i) {
        ll sm = 0;
        for(i++; i; i -= LSone(i)) {
            sm += t[i];
        }
        return sm;
    }
    string generatte(string p, ll a0, ll x, ll y, ll n) {
        a[0] = a0;
        for(int i = 1; i < n; ++i) {
            a[i] = (a[i - 1] * x + y) % 1812447359ll;
        }
        string s = p;
        for(int i = p.size(); i < n; ++i) {
            s.push_back((char)(a[i] % 26 + 'a'));
        }
        return s;
    }
    long long findNumberOfSwaps(string p, ll a0, ll x, ll y, ll n, ll k) {
        string s = generatte(p, a0, x, y, n);
        int sz = (int) s.size();
        t = vi(sz + 1, 0);
        m = sz;
        ll ans = 0;
        for(int i = 0; i < k; ++i) {
            map<int, vector<int> > mp;
            for(int j = i; j < sz; j += k) {
                mp[(int)s[j] * -1].push_back(j);
            }
            for(auto j : mp) {
                for(auto l : j.second) {
                    ll r = rsq(l);
                    ans += ((l / k) - r);
                    inc(l, 1);
                }
            }
            for(auto j : mp) for(auto l : j.second) inc(l, -1);
        }
        return ans;
    }
};
