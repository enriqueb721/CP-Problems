#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 100;
const ll MOD = 1e9;
int t;
char s[N];
int n;
ll mul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}
ll add(ll a, ll b) {
    if(a + b > MOD) return a + b - MOD;
    return a + b;
}
ll sub(ll a, ll b) {
    if(a - b < 1) return a - b + MOD;
    return a - b;
}
bool is_num(char c) {
    return c >= '0' and c<= '9';
}
pair<int, pair<ll, ll> > run(int l, ll sw, ll sh, ll q) {
    ll w = sw, h = sh, num = 0;
    int r = -1;
    for(int i = l; i < n; ++i) {
        char c = s[i];
        if(c == ')') {
            r = i; break;
        };
        if(is_num(c)) {
            num = mul(c - '0', q);
            auto cur = run(i + 2, w, h, num);
            i = cur.first;
            w = cur.second.first;
            h = cur.second.second;
        } else {
            if(c == 'N') h = sub(h, q);
            else if(c == 'S') h =add(h, q);
            else if(c == 'W') w=  sub(w, q);
            else w = add(w, q);
        }
    }
    // cout<<n<<" "<<w<<" "<<h<<endl;
    return { r, {w, h} };
}
int main() {
    cin>>t;
    for(int cas = 1; cas <= t; ++cas) {
        scanf("%s", s);
        n = strlen(s);
        auto ans = run(0, 1, 1, 1);
        ll ans_w = ans.second.first;
        ll ans_h = ans.second.second;
        cout<<"Case #"<<cas<<": "<<ans_w<<" "<<ans_h<<endl;
    }
    return 0;
}
