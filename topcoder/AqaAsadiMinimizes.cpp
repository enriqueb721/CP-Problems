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
extern const int MAX = 5e5 + 100;
extern const double EPS = 1e-12;
bool comp(const pair<ll, ll> a, const pair<ll, ll> b) {
    return a.first < b.first;
}
bool lt(double a, double b) {
    return (b - a) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * EPS);
}
pair<ll, ll> a[MAX];
class AqaAsadiMinimizes {
    public:
    double getMin(vector <int> P, int B0, int X, int Y, int N) {
        for(int i = 0; i < N; ++i) {
            if(i < (int) P.size()) {
                a[i] = {P[i], i};
            } else if(i == (int) P.size()) {
                a[i] = {B0, i};
            } else {
                a[i] = {(a[i - 1].first * (ll)X + (ll)Y) % MOD, i};
            }
        }
        sort(a, a + N, comp);
        double mn = INF;
        for(int i = 1; i < N; ++i) {
            double n = labs(a[i].first - a[i - 1].first);
            double d = labs(a[i].second - a[i - 1].second);
            double cur = n * 1.0 / d * 1.0;
            if(lt(cur, mn)) {
                mn = cur;
            }
        }
        return mn;
    }
};

int main() {
    AqaAsadiMinimizes ___test;
    // ___test.run_test(-1);
    // auto ans = ___test.getMin({123456}, 234567890, 345678, 456789, 10);
    // auto ans = ___test.getMin({47, 1, 10, 3, 2}, 0, 0, 0, 5);
    auto ans = ___test.getMin({0}, 0, 0, 0, 500000);
    // auto ans = ___test.getMin({11, 0, 30, 20, 1000}, 0, 0, 0, 5);
    printf("%.5lf\n", ans);
    // cout<<ans<<endl;
    /*
    for(auto i : ans) {
        cout<<i<<" ";
    } cout<<endl;
    */
}