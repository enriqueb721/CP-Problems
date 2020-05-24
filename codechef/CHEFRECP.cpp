#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int t,n;
int v[N];
int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 0; i < n; ++i)
            cin>>v[i];
        map<int, int> mp;
        int p = v[0], c = 0;
        bool ok = true;
        for(int i = 0; i < n; ++i) {
            if(v[i] == p)
                c++;
            else {
                if(mp.count(p)) {
                    ok = false;
                    break;
                }
                mp[p] = c;
                p = v[i],
                c = 1;
            }
        }
        if(mp.count(p))
            ok = false;
        else
            mp[p] = c;
        if(!ok) {
            puts("NO");
            continue;
        }
        set<int> st;
        for(auto i : mp)
            st.emplace(i.second);
        if((int) st.size() == (int) mp.size())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}