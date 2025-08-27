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

int grid[19][19];
int dy[4] = {0, 1, 1, -1};
int dx[4] = {1, 0, 1, 1};

bool inRange(int y, int x) {
    return (y >= 0 && y < 19 && x >= 0 && x < 19);
}

bool check(int y, int x, int n){
    for (int dir = 0; dir < 4; dir++) {
        int py = y - dy[dir];
        int px = x - dx[dir];
        if (inRange(py, px) && grid[py][px] == n) continue;

        int ny = y, nx = x;
        int cnt = 1;

        while (true) {
            ny += dy[dir];
            nx += dx[dir];
            if (!inRange(ny, nx) || grid[ny][nx] != n) break;
            cnt++;
        }

        if (cnt == 5) return true;
    }
    return false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> grid[i][j];
        }
    }

    for (int j = 0; j < 19; j++) {
        for (int i = 0; i < 19; i++) {
            if (grid[i][j] != 0) {
                if (check(i, j, grid[i][j])) {
                    cout << grid[i][j] << "\n" << i + 1 << " " << j + 1 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << 0;
    return 0;
}