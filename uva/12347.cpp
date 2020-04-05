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
using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
extern const int INF = INT_MAX - 5;
extern const int MOD = 1e9 + 7;
extern const int N = 2e5 + 200;
int n;
vi v;
int main() {
    while(scanf("%d", &n) != EOF) {
        v.emplace_back(n);
    }
    stack<int> st;
    vi ans;
    for(auto i : v) {
        if(!st.empty()) {
            if(i < st.top()) {
                st.emplace(i);
            } else {
                vi quit;
                while(!st.empty() and i > st.top()) {
                    quit.emplace_back(st.top());
                    st.pop();
                }
                st.emplace(quit.back());
                st.emplace(i);
                for(int k = 0; k < (int) quit.size() - 1; ++k) {
                    ans.emplace_back(quit[k]);
                }
            }
        } else {
            st.emplace(i);
        }
    }
    while(!st.empty()) {
        ans.emplace_back(st.top());
        st.pop();
    }
    for(auto i : ans) {
        cout<<i<<endl;
    }
    return 0;
}
