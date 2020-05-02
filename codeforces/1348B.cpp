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
int t,k,n;
int v[N];
void print() {
    cout<<n<<endl;
    forn(i, n) {
        if(i != 0) cout<<" ";
        cout<<v[i];
    } cout<<endl;
}
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>k;
        map<int, int> mp;
        forn(i,n ) {
            cin>>v[i];
            mp[v[i]]++;
        }
        if(k == n) print();
        else {
            int freq = (int) mp.size();
            if(freq > k) puts("-1");
            else {
                vi p;
                int l = -1;
                for(auto i : mp) {
                    l = i.first;
                    p.emplace_back(i.first);
                }
                while((int) p.size() < k) p.emplace_back(l);
                vi ans;
                int sz = (int) p.size();
                for(int i = 0, d = 0; i < n; ++i) {
                    // debug(i);
                    if(v[i] == p[d]) {
                        ans.emplace_back(v[i]);
                        d++;
                        d = d % sz;
                    } else {
                        // debug('f');
                        while(v[i] != p[d]) {
                            // debug("add", p[d]);
                            ans.emplace_back(p[d]);
                            d++;
                            d = d % sz;
                        }
                        ans.emplace_back(v[i]);
                        d++;
                        d = d % sz;
                    }
                }
                printf("%d\n", (int) ans.size());
                forn(i, (int) ans.size()) {
                    if(i != 0) printf(" ");
                    printf("%lld", ans[i]);
                } puts("");
            }
        }
    }
    return 0;
}
