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
/*
빈 칸: 언제나 이동할 수 있다. ('.')
벽: 절대 이동할 수 없다. ('#')
열쇠: 언제나 이동할 수 있다. 이 곳에 처음 들어가면 열쇠를 집는다. ('a', 'b', 'c', 'd', 'e', 'f')
문: 대응하는 열쇠가 있을 때만 이동할 수 있다. ('A', 'B', 'C', 'D', 'E', 'F')
민식이의 현재 위치: 빈 곳이고, 민식이가 현재 서 있는 곳이다. ('0')
출구: 달이 차오르기 때문에, 민식이가 가야하는 곳이다. 이 곳에 오면 미로를 탈출한다. ('1')
 */

struct minsik{
    int y,x, key;
};

int n, m, ans;
vector<string> v;
int visited[51][51][64];

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

void bfs(){
    minsik min;
    memset(visited, inf, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '0'){
                min.y = i;
                min.x = j;
                break;
            }
        }
    }

    queue<pair<minsik, int>> q;
    q.push({min, 0});
    visited[min.y][min.x][0] = 0;

    while(!q.empty()){
        minsik curr = q.front().first;
        int cost = q.front().second;
        int k = curr.key;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = curr.y + dy[i];
            int nx = curr.x + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m && visited[ny][nx][k] > cost){
                char c = v[ny][nx];
                if (c == '1'){
                    ans = cost+1;
                    return;
                }
                if (c == '#'){
                    continue;
                }
                visited[ny][nx][k] = cost;
                if (c == '.' || c == '0'){
                    q.push({{ny,nx,k},cost+1});
                }
                if (c >= 'a' && c <= 'f'){
                    int nk = k;
                    nk |= (1 << (c - 'a'));
                    q.push({{ny,nx,nk}, cost+1});
                    visited[ny][nx][nk] = cost+1;
                }

                if (c >= 'A' && c <= 'F'){
                    if ((k | (1 << (c - 'A'))) == k){
                        q.push({{ny,nx,k}, cost+1});
                        visited[ny][nx][k] = cost+1;
                    }
                }
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    bfs();

    if (ans == 0){
        cout << -1;
    }else{
        cout << ans;
    }




    return 0;
}