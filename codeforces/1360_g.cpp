#include <bits/stdc++.h>
using namespace std;
const int N = 60;
const int INF = 1e9;
int t,a,b,n,m;
int s[N][N];
int col[N];
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>m>>a>>b;
        if(a > m or b > n) {
            puts("NO");
            continue;
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                s[i][j] = 0;
            }
        }
        for(int i = 0; i < m; ++i)
            col[i] = 0;
        bool ok = true;
        for(int i = 0; i < n; ++i) {
            int cur = a;
            for(int j = 0; j < m and cur > 0; ++j) {
                if(col[j] < b) {
                    s[i][j] = 1;
                    col[j]++;
                    cur--;
                }
            }
            if(cur > 0) {
                ok = false;
                break;
            }
        }
        if(ok) {
            puts("YES");
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    cout<<s[i][j];
                } puts("");
            }
        } else puts("NO");
    }
    return 0;
}
