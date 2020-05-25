#include <bits/stdc++.h>
using namespace std;
const int N = 60;
const int INF = 1e9;
int t,n;
int v[N];
int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 0; i < n; ++i)
            cin>>v[i];
        sort(v, v + n);
        int ans = INF;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                ans = min(ans, v[j] - v[i])
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}