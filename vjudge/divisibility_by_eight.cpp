#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    cin>>s;
    vector<string> pw;
    for(int i = 0; i < 1000; i += 8) {
        string ds = to_string(i);
        reverse(ds.begin(), ds.end());
        pw.emplace_back(ds);
    }
    // for(auto i : pw) cout<<i<<" ";
    // cout<<endl;
    map<int, vector<int> > mp;
    bool okl = false;
    string ans = "";
    for(auto dig : pw) {
        int mn = s.size() - 1;
        bool ok = true;
        for(int idx = 0; idx < (int) dig.size(); ++idx) {
            bool found = false;
            int p = dig[idx] - '0';
            for(int i = mn; i >= 0; --i) {
                int cur = s[i] - '0';
                if(cur == p) {
                    found = true;
                    mn = i - 1;
                    break;
                }
            }
            if(!found) {
                ok = false;
                break;
            }
        }
        if(ok) {
            okl = true;
            reverse(dig.begin(), dig.end());
            ans = dig;
            break;
        }
    }
    if(okl) {
        puts("YES"); cout<<ans<<endl;
    } else puts("NO");
    return 0;
}
