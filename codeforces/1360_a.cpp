#include <bits/stdc++.h>
using namespace std;
int t,a,b;
int main() {
    cin>>t;
    while(t--) {
        cin>>a>>b;
        if(a > b) swap(a, b);
        int m = max(2 * a, b);
        cout<<m * m<<endl;
    }
    return 0;
}