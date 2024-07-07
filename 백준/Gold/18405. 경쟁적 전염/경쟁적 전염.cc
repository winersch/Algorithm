#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>

using namespace std;

int n, k, s, x, y;
int grid[201][201];
bool visited[201][201];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void bfs() {
    queue<pair<int, pii>> q;
    for (int virus = 1; virus <= k; virus++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == virus) {
                    q.push({virus, {i, j}});
                    visited[i][j] = true;
                }
            }
        }
    }
    for (int time = 0; time < s; time++) {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            int virus = q.front().first;
            pii curr = q.front().second;
            q.pop();

            for (int j = 0; j < 4; j++) {
                int ny = curr.first + dy[j];
                int nx = curr.second + dx[j];

                if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && grid[ny][nx] == 0){
                    visited[ny][nx] = true;
                    grid[ny][nx] = virus;
                    q.push({virus,{ny,nx}});
                }
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    cin >> s >> y >> x;
    bfs();

    cout << grid[y - 1][x - 1];


    return 0;
}