#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
const int INF = INT_MAX - 5;
map<int, pair<int, int> > mp;
map<int, int> hs;
vi in,post;
int build(int l, int r, int* idx) {
    if(l > r) return -1;
    int cur = post[*idx];
    (*idx)--;
    if(l == r) {
        mp[cur].first = -1;
        mp[cur].second = -1;
        return cur;
    }
    int pi = hs[cur];
    mp[cur].first = build(pi + 1, r, idx);
    mp[cur].second = build(l, pi - 1, idx);
    return cur;
}
int mx = INF, ans = -1;
void dfs(int i, int sum) {
    sum += i;
    if(mp[i].first == -1 and mp[i].second == -1) {
        if(sum < mx) {
            mx = sum;
            ans = i;
            return;
        }
    }
    if(mp[i].first != -1) {
        dfs(mp[i].first, sum);
    }
    if(mp[i].second != -1) {
        dfs(mp[i].second, sum);
    }
}
int main() {
    string temp;
    string a,b;
    int c = 0;
    while(getline(cin, temp)) {
        c++;
        if(c % 2 == 0) {
            b = temp;
            in.clear();
            post.clear();
            mp.clear();
            hs.clear();
            stringstream s(a);
            int d;
            while(s >> d) in.emplace_back(d);
            s = stringstream(b);
            while(s >> d) post.emplace_back(d);
            int idx = (int) in.size() - 1;
            for(int i = 0; i < (int) in.size(); ++i) hs[in[i]] = i;
            int root = build(0, idx, &idx);
            mx = INF, ans = -1;
            dfs(root, 0);
            cout<<ans<<endl;
        } else {
            a = temp;
        }
    }

    return 0;
}