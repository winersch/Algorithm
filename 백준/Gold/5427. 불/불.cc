#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <numeric>
#include <set>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, m;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
bool visited[1001][1001];
bool firevisited[1001][1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        memset(visited,false,sizeof(visited));
        cin >> m >> n;
        vector<string> v;
        queue<pii> fireq,q;
        bool escaped = false;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            v.push_back(s);
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == '@'){
                    q.push({i,j});
                    visited[i][j] = true;
                    if (i == 0 || i == n-1 || j == 0 || j == m-1){
                        escaped = true;
                    }
                }
                if (s[j] == '*'){
                    fireq.push({i,j});
                }
            }
        }

        int ans = 0;
        while(!escaped && !q.empty()){
            queue<pii> tq;
            while(!fireq.empty()){
                int cy = fireq.front().first;
                int cx = fireq.front().second;
                fireq.pop();

                for (int i = 0; i < 4; i++) {
                    int ny = cy + dy[i];
                    int nx = cx + dx[i];
                    if (ny >= 0 && ny < n && nx >= 0 && nx < m && (v[ny][nx] == '.' || v[ny][nx] == '@')){
                        tq.push({ny,nx});
                        v[ny][nx] = '*';
                    }
                }
            }
            fireq = tq;
            while(!tq.empty()) tq.pop();

            while(!q.empty()){
                int cy = q.front().first;
                int cx = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int ny = cy + dy[i];
                    int nx = cx + dx[i];
                    if (ny >= 0 && ny < n && nx >= 0 && nx < m && v[ny][nx] == '.' && !visited[ny][nx]){
                        visited[ny][nx] = true;
                        if (ny == 0 || ny == n-1 || nx == 0 || nx == m-1){
                            escaped = true;
                            break;
                        }
                        tq.push({ny,nx});
                    }
                }
            }
            q = tq;
            ans++;
        }
        if (escaped){
            cout << ++ans << "\n";
        }else{
            cout << "IMPOSSIBLE\n";
        }
    }


    return 0;
}