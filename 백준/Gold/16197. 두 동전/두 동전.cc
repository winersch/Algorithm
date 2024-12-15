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


int n, m, ans = -1;
vector<string> board;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
bool visited[21][21][21][21]; // x1,y1,x2,y2
vector<pii> coins;

struct node {
    int cost, x1, y1, x2, y2;
};

bool is_out(int y, int x){
    return y >= 0 && y < n && x >= 0 && x < m;
}

void bfs() {
    queue<node> q;
    q.push({0, coins[0].first, coins[0].second, coins[1].first, coins[1].second});
    visited[coins[0].first][coins[0].second][coins[1].first][coins[1].second] = true;

    while (!q.empty()) {
        node c = q.front();
        q.pop();
        if (c.cost > 10){
            return;
        }
        for (int i = 0; i < 4; i++) {
            int x1 = c.x1 + dx[i];
            int y1 = c.y1 + dy[i];
            int x2 = c.x2 + dx[i];
            int y2 = c.y2 + dy[i];

            bool b1, b2;
            b1 = is_out(x1,y1);
            b2 = is_out(x2,y2);

            if ((b1 && !b2) || (b2 && !b1)){
                if (c.cost+1 > 10){
                    return;
                }
                ans = c.cost+1;
                return;
            }

            if (!b1 && !b2){
                continue;
            }

            if (board[x1][y1] == '#' && board[x2][y2] == '#'){
                continue;
            }

            if (board[x1][y1] == '#'){
                x1 = c.x1;
                y1 = c.y1;
            }
            if (board[x2][y2] == '#'){
                x2 = c.x2;
                y2 = c.y2;
            }

            if (!visited[x1][y1][x2][y2]){
                visited[x1][y1][x2][y2] = true;
                q.push({c.cost+1,x1,y1,x2,y2});
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        board.push_back(s);
        for (int j = 0; j < m; j++) {
            if (s[j] == 'o') {
                coins.push_back({i, j});
                s[j] = '.';
            }
        }
    }
    bfs();
    cout << ans;

    return 0;
}