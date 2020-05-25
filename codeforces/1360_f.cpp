#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int t,n,m;
char s[N][N];
string bt(int idx, vector<int> v) {
    if(idx == m) {
        bool ok = true;
        for(int i : v) {
            if(i < m - 1) {
                ok = false;
                break;
            }
        }
        if(ok)
            return "";
        else
            return "*";
    }
    map<char, vector<int> > mp;
    bool ok = true;
    for(int i = 0; i < n; ++i) {
        if(v[i] < idx - 1) {
            ok = false;
            break;
        }
        mp[s[i][idx]].emplace_back(i);
    }
    if(!ok)
        return "*";
    for(auto i : mp) {
        for(int j = 0; j < (int) i.second.size(); ++j) {
            int p = i.second[j];
            v[p] += 1;

        }
        string st = bt(idx + 1, v);
        if(st != "*") {
            st.push_back(i.first);
            return st;
        }
        for(int j = 0; j < (int) i.second.size(); ++j) {
            int p = i.second[j];
            v[p] -= 1;
        }
    }
    return "*";
}
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(int i = 0; i < n; ++i)
            cin>>s[i];
        vector<int> d(n, 0);
        string ans = bt(0, d);
        if(ans == "*")
            puts("-1");
        else {
            reverse(ans.begin(), ans.end());
            cout<<ans<<endl;
        }
    }
    return 0;
}
