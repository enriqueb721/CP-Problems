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
extern const int N = 2e6 + 100;
extern const double EPS = 1e-12;

class LandSplitter {
    public:
	ll split_conti(ll n, ll a, ll v) {
		return v * a * (n - a) ;
	}
    ll cheapest(ll n, ll a, ll b){
		if(b - a == 0) {
			if(n % b == 0) return split_conti(n, b, n / b) / 2;
			else return -1;
		}
		ll ans = 0;
		ll ln = (n + (b - 1)) / b;
		if(a * ln > n) return -1;
		ll diff = (ln * b) - n;
		ll dist = b - a;
		ll tot = diff / dist;
		diff -= tot * dist;
		ans = split_conti(n, a, tot);
		if(diff == 0) {
			ans += split_conti(n, b, ln - tot);
		} else {
			ans += split_conti(n, b, max(0ll, ln - tot - 1));
			ans += (b - diff) * (n - (b - diff));
		}			
		return ans / 2;
    }
};

int main() {
    LandSplitter ___test;
    auto ans = ___test.cheapest(51, 5, 7);
    cout<<ans<<endl;
    /*
    for(auto i : ans) {
        cout<<i<<" ";
    } cout<<endl;
    */
}

