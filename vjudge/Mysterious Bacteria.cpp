#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int N = 1e7;
int t;
ll n;
bool is_composite[N];
vi primes;
void sieve() {
    is_composite[0] = is_composite[1] = true;
    for(ll i = 2; i < N; ++i) {
        if(!is_composite[i]) {
            for(ll k = i * i; k < N; k += i) is_composite[k] = true;
            primes.emplace_back(i);
        }
    }
}
ll gcd(ll a, ll b) {
    while(b) a %= b, swap(a, b);
    return a;
}
int main() {
    sieve();
    scanf("%d", &t);
    for(int cas = 1; cas <= t; ++cas) {
        scanf("%lld", &n);
        ll temp = labs(n), ans = 0;
        bool neg = n < 0;
        for(int i = 0; i < (int) primes.size(); ++i) {
            if(primes[i] > temp) break;
            int cont = 0;
            while(temp % primes[i] == 0) temp /= primes[i], cont++;
            if(cont > 0) ans = gcd(cont, ans);
        }
        if(temp > 1) ans = 1;
        if(neg) while(ans % 2 == 0) ans /= 2;
        printf("Case %d: %lld\n", cas, ans);
    }
    return 0;
}
