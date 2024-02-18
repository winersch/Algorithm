#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000000
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool visited[101][101];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        memset(visited, false, sizeof(visited));
        int n, m, ans = 0;
        vector<string> grid;
        vector<bool> key(26);
        cin >> n >> m;
        for (int j = 0; j < n; j++) {
            string ts;
            cin >> ts;
            grid.push_back(ts);
        }
        string k;
        cin >> k;
        if (k != "0") {
            for (int j = 0; j < k.length(); j++) {
                key[k[j] - 'a'] = true;
            }
        }
        queue<pair<int, int>> q;
        queue<pair<int, int>> door[26];

        for (int j = 0; j < n; j++) {
            for (int l = 0; l < m; l++) {
                if (j == 0 || j == n - 1 || l == 0 || l == m - 1) {
                    if (grid[j][l] == '$') {
                        visited[j][l] = true;
                        q.push({j, l});
                        ans++;
                    }
                    if (grid[j][l] == '.') {
                        visited[j][l] = true;
                        q.push({j, l});
                    }
                    if (grid[j][l] >= 'a' && grid[j][l] <= 'z') {
                        visited[j][l] = true;
                        q.push({j, l});
                        key[grid[j][l]-'a'] = true;
                    }
                    if (grid[j][l] >= 'A' && grid[j][l] <= 'Z') {
                        visited[j][l] = true;
                        if (key[grid[j][l] - 'A']) {
                            q.push({j, l});
                        } else {
                            door[grid[j][l] - 'A'].push({j, l});
                        }

                    }
                }
            }
        }
        for (int j = 0; j < 26; j++) {
            if (key[j]){
                while(!door[j].empty()){
                    q.push(door[j].front());
                    door[j].pop();
                }
            }

        }
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int ny = curr.first + dy[j];
                int nx = curr.second + dx[j];

                if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx] && grid[ny][nx] != '*') {
                    if (grid[ny][nx] == '.') {
                        visited[ny][nx] = true;
                        q.push({ny, nx});
                    }
                    if (grid[ny][nx] >= 'a' && grid[ny][nx] <= 'z') {
                        key[grid[ny][nx] - 'a'] = true;
                        visited[ny][nx] = true;
                        q.push({ny, nx});
                        while (!door[grid[ny][nx] - 'a'].empty()) {
                            q.push(door[grid[ny][nx] - 'a'].front());
                            door[grid[ny][nx] - 'a'].pop();
                        }
                    }
                    if (grid[ny][nx] == '$') {
                        visited[ny][nx] = true;
                        q.push({ny, nx});
                        ans++;
                    }
                    if (grid[ny][nx] >= 'A' && grid[ny][nx] <= 'Z') {
                        visited[ny][nx] = true;
                        if (key[grid[ny][nx] - 'A']) {
                            q.push({ny, nx});
                        } else {
                            door[grid[ny][nx] - 'A'].push({ny, nx});
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }


    return 0;
}
