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
        int odd = 0, even = 0;
        for(int i = 0; i < n; ++i) {
            cin>>v[i];
            if(v[i] & 1) odd++;
            else even++;
        }
        sort(v, v + n);
        int p = 0;
        for(int i = 1; i < n; ++i) {
            if(v[i] - v[i - 1] == 1)
                p++, i++;
        }
        // cout<<odd<<" "<<even<<" "<<p<<endl;
        while(odd & 1 and even & 1) {
            if(p == 0) break;
            odd--, even--;
        }
        if(odd % 2 == 0 and even % 2 ==0)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}