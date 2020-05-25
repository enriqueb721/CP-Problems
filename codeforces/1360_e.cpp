#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int t,n;
char m[N][N];
int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin>>m[i][j];
            }
        }
        bool ok = true;
        for(int i = 0; i < n - 1; ++i) {
            for(int j = 0; j < n - 1; ++j) {
                if(m[i][j] == '1') {
                    if(m[i + 1][j] != '1' and m[i][j + 1] != '1') {
                        ok = false;
                        break;
                    }
                }
            }
            if(!ok)
                break;
        }
        if(ok)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}