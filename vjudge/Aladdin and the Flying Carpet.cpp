#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
const int N = 1e6 + 10;
int t;
ll n,k;
bool is_composite[N];
vi primes;
void sieve() {
    is_composite[0] = is_composite[1] = true;
    for(ll i = 2; i < N; ++i) {
        if(!is_composite[i]) {
            primes.emplace_back(i);
            for(ll k = i * i; k < N; k += i) is_composite[k] = true;
        }
    }
}
ll factors(ll num, ll fact) {
    ll temp = num, ans = 1;
    for(ll p : primes) {
        if(p > temp) break;
        ll count = 1;
        while(temp % p == 0) temp /= p, count++;
        ans *= count;
    }
    if(temp != 1) ans *= 2;
    ans /= 2;
    for(int i = 1; i < fact; ++i) if(num % i == 0) ans--;
    return ans;
}
int main() {
    sieve();
    scanf("%d", &t);
    for(int cas = 1; cas <= t; ++cas) {
        scanf("%lld %lld", &n, &k);
        ll ans = 0;
        if(k * k < n) ans = factors(n, k);
        printf("Case %d: %lld\n", cas, ans);
    }
    return 0;
}
