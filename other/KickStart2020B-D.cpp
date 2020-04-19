#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 400;
ll t,u,d,h,l,r,w;
double mt[N][N];
bool is_hole(ll i, ll j) {
    // cout<<i<<" "<<d<<" "<<u<<endl;
    return (i >= d and i <= u) and (j >= l and j <= r);
}
int main() {
    cin>>t;
    for(int cas = 1; cas <= t; ++cas) {
        cin>>w>>h>>l>>d>>r>>u;
        for(int i = 1; i <= h; ++i) {
            for(int k = 1; k <= w; ++k) mt[i][k] = 0.0f;
        }
        for(int i = 1; i <= h; ++i) {
            for(int k = 1; k <= w; ++k) {
                if(is_hole(i, k)) continue;
                if(i == 1 and k == 1) mt[1][1] = 1.0f;    
                else if(i == h and k == w) mt[i][k] = mt[i - 1][k] + mt[i][k - 1];
                else if(i == h) mt[i][k] = (mt[i - 1][k] * 1.0f / 2.0f) + mt[i][k - 1];
                else if(k == w) {
                    mt[i][k] = mt[i - 1][k] + (mt[i][k - 1] * 1.0f / 2.0f);
                } else mt[i][k] = (mt[i - 1][k] * 1.0f / 2.0f) + (mt[i][k - 1] * 1.0f / 2.0f);
            }
        }
        for(int i = 1; i <= h; ++i) {
            for(int k = 1; k <= w; ++k) {
                printf("%.5lf\t", mt[i][k]);
            } puts("");
        }
        printf("Case #%d: %.10lf\n", cas, mt[h][w]);
    }
    return 0;
}
