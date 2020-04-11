#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int N = 1e7 + 10;
int t; ll n;
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
int main() {
    sieve();
    scanf("%d", &t);
    for(int cas = 1; cas <= t; ++cas) {
        scanf("%lld", &n);
        ll ans = 1, temp = n;
        if(n == 1) ans = 1;
        else {
            ll ways = 1;
            for(int i = 0; i < (int) primes.size(); ++i) {
                if(primes[i] > temp) break;
                int count = 0;
                while(temp % primes[i] == 0) temp /= primes[i], count++;
                if(count > 0) ways *= (count * 2) + 1;
            }
            if(temp > 1) ways *= 2 + 1;
            ans = (ways / 2) + 1;
        }
        printf("Case %d: %lld\n", cas, ans);
    }
    return 0;
}
