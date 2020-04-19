#include <bits/stdc++.h>
using namespace std;
const int N = 200;
int t,n;
int v[N];
int main() {
    cin>>t;
    for(int cas = 1; cas <= t; ++cas) {
        cin>>n;
        for(int i = 0; i < n; ++i) cin>>v[i];
        int ans = 0;
        for(int i = 1; i < n - 1; ++i) {
            if(v[i] > v[i - 1] and v[i] > v[i + 1]) ans++;
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
    return 0;
}
