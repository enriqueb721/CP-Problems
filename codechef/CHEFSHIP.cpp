#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll K = 33;
const ll C = 5381;
int t,n;
char s[N];
ll pw[N], H[N];
struct hashing {
    hashing() {
        pw[0] = 1;
        for(int i = 1; i < N; ++i)
            pw[i] = K * pw[i - 1];
    }
    void build() {
        H[0] = C;
        for(int i = 1; i <= n; ++i)
            H[i] = H[i - 1] * K + (s[i - 1] - 'a' + 1);
    }
    ll get(ll l, ll r) {
        r++;
        return H[r] - H[l] * pw[r - l];
    }
};
int main() {
    cin>>t;
    hashing h;
    while(t--) {
        cin>>s;
        n = strlen(s);
        h.build();
        int ans = 0;
        for(int i = 1; i < n - 2; i += 2) {
            int m1 = i / 2;
            int m2 = (n - (i + 1)) / 2;
            // cout<<0<<" "<<m1<<" _ "<<m1 + 1<<" "<<i<<" | "<<i + 1<<" "<<i + m2<<" _ "<<i + 1 + m2<<" "<<n - 1<<endl;
            // cout<<h.get(0, m1)<<" "<<h.get(m1 + 1, i)<<" "<<h.get(i + 1, i + m2)<<" "<<h.get(i + 1 + m2, n - 1)<<endl;
            if(h.get(0, m1) == h.get(m1 + 1, i) and h.get(i + 1, i + m2) == h.get(i + 1 + m2, n - 1))
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
