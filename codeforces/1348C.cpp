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
int t,n,k;
char s[N];
string p[N];
int main() {
    cin>>t;
    while(t--){
        cin>>n>>k;
        scanf("%s", s);
        if(k == 1) {
            sort(s, s + n);
            printf("%s\n", s);
            continue;
        }
        map<char, int> mp;
        forn(i, n) mp[s[i]]++;
        // for(auto i : mp) cout<<i.first<<" "<<i.second<<endl;
        bool more = false;
        int temp = k;
        char cur = '@';
        for(auto i : mp) {
            if(i.second >= temp) {
                cur = i.first;
                break;
            } else {
                more = true;
                temp -= i.second;
            }
        }
        if(more) cout<<cur<<endl;
        else {
            // puts("fffff");
            temp = k;
            map<char, int> nmp;
            char f = '@';
            for(auto i : mp) {
                if(i.second > temp) {
                    nmp[i.first] = i.second - temp;
                    temp = 0;
                } else {
                    temp -= i.second;
                }
                if(f == '@') f = i.first;
            }
            // for(auto i : nmp) cout<<i.first<<" "<<i.second<<endl;
            // debug(f);
            int sz = (int) nmp.size();
            if(sz == 1) {
                char curr = 'p';
                int tot = -1;
                for(auto i : nmp) {
                    curr = i.first;
                    tot = (i.second) / k + (i.second % k != 0 ? 1 : 0);
                    break;
                }
                cout<<f;
                for(int i = 0; i < tot; ++i) {
                    cout<<curr;
                } cout<<endl;
            } else {
                cout<<f;
                for(auto i : nmp) {
                    int nm = i.second;
                    forn(j, nm) cout<<i.first;
                } cout<<endl;
            }
        }
    }
    return 0;
}
