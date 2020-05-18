#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int INF = INT_MAX;
char mt[N][N];
bool vis[N][N];
int ans[N][N];
int pos[N][N];
int n,m;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
bool valid(int i, int j) {
    return i >= 0 and i < n and j >= 0 and j < m;
}
int main() {
    cin>>n>>m;
    pair<int, int> s, t;
    for(int i = 0; i < n; ++i) {
        for(int k = 0; k < m; ++k) {
            cin>>mt[i][k];
            ans[i][k] = INF;
            if(mt[i][k] == 'S') s = {i, k};
            else if(mt[i][k] == 'T') t = {i, k};
        }
    }
    queue< pair<int, int> > q;
    vis[s.first][s.second] = true;
    ans[s.first][s.second] = 0;
    pos[s.first][s.second] = -1;
    q.push(s);
    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        int act = pos[front.first][front.second];
        int a = ans[front.first][front.second];
        for(int i = 0; i < 4; ++i) {
            int ni = front.first + di[i];
            int nj = front.second + dj[i];
            if(valid(ni, nj)) {
                if(mt[ni][nj] != '*') {
                    if(!vis[ni][nj]) {
                        if(act == -1) {
                            ans[ni][nj] = 0;
                            pos[ni][nj] = i;
                        } else {
                            if(i != act) {
                                ans[ni][nj] = a + 1;
                                pos[ni][nj] = i;
                            } else {
                                ans[ni][nj] = a;
                                pos[ni][nj] = act;
                            }
                        }
                        vis[ni][nj] = true;
                        q.emplace(ni, nj);
                    } else {
                        if(i == act) {
                            if(a < ans[ni][nj]) {
                                ans[ni][nj] = a;
                                pos[ni][nj] = i;
                                q.emplace(ni, nj);
                            }
                        }
                    }
                }
            }
        }
    }


    for(int i = 0; i < n; ++i) {
        for(int k = 0; k < m; ++k)  {
            cout<<pos[i][k]<<" ";
        } cout<<endl;
    } cout<<endl;

    for(int i = 0; i < n; ++i) {
        for(int k = 0; k < m; ++k)  {
            cout<<ans[i][k]<<" ";
        } cout<<endl;
    }
    if(ans[t.first][t.second] <= 2) puts("YES");
    else puts("NO");
    return 0;
}
