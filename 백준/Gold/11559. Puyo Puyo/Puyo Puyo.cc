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
#include <list>
#include <unordered_set>
#include <sstream>
#include <ctime>
#include <iomanip>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;

vs v;
int ans;
bool visited[12][6];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

void fall(){
    for (int x = 0; x < 6; x++) {
        int start = 11;
        for (int y = 11; y >= 0; y--) {
            if (v[y][x] != '.') {
                v[start][x] = v[y][x];
                if (start != y) {
                    v[y][x] = '.';
                }
                start--;
            }
        }
    }
}

bool find(){
    memset(visited,false,sizeof(visited));
    bool is_chained = false;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (v[i][j] != '.' && !visited[i][j]){
                char ch = v[i][j];
                queue<pii> q;
                q.push({i,j});
                visited[i][j] = true;
                vector<pii> trail;
                while(!q.empty()){
                    int cy = q.front().first;
                    int cx = q.front().second;
                    trail.push_back({q.front()});
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int ny = cy + dy[k];
                        int nx = cx + dx[k];
                        if (ny>=0&&ny<12&&nx>=0&&nx<6&& !visited[ny][nx] && v[ny][nx] == ch){
                            visited[ny][nx] = true;
                            q.push({ny,nx});
                        }
                    }
                }
                if (trail.size() >= 4){
                    is_chained = true;
                    for(auto &[a,b] : trail){
                        v[a][b] = '.';
                    }
                }
            }
        }
    }
    return is_chained;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 12; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    while(true){
        if (!find()){
            break;
        }
        fall();
        ans++;
    }
    cout << ans;
    return 0;
}