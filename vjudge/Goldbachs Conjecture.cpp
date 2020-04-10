#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;
const int N = 1e7 + 10;
int t,n;
vi primes;
bool is_composite[N];
void sieve() {
    is_composite[0] = is_composite[1] = true;
    for(ll i = 2; i < N; ++i) {
        if(!is_composite[i]) {
            for(ll k = i * i; k < N; k += i) is_composite[k] = true;
            primes.emplace_back(i);
        }
    }
}
int main() {
    sieve();
    scanf("%d", &t);
    for(int cas = 1; cas <= t; ++cas) {
        scanf("%d", &n);
        ll ans = 0;
        for(auto i : primes) {
            if(i > n / 2) break;
            int diff = n - i;
            if(!is_composite[diff]) ans++;
        }
        printf("Case %d: %lld\n", cas, ans);
    }
    return 0;
}