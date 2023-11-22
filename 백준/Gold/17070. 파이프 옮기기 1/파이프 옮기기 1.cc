#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>
#include <stack>


using namespace std;

int n, ans;
int house[17][17];
queue<pair<int, pair<int, int>>> q;
// 가로 0, 세로 1, 대각선 2

void right(int y, int x) {
    if (house[y][x+1] == 1 || x+1 >= n){
        return;
    }
    q.push({0,{y,x+1}});
}

void down(int y, int x) {
    if (house[y+1][x] == 1 || y+1 >= n){
        return;
    }
    q.push({1,{y+1,x}});
}

void diagonal(int y, int x) {
    if (house[y+1][x] == 1 || house[y][x+1] == 1 || house[y+1][x+1] == 1 || y+1 >= n || x+1 >= n){
        return;
    }
    q.push({2,{y+1, x+1}});
}

void bfs() {
    while (!q.empty()) {
        int y = q.front().second.first;
        int x = q.front().second.second;
        int status = q.front().first;
        q.pop();
        if (y == n-1 && x == n-1){
            ans++;
            continue;
        }
        diagonal(y,x);
        switch (status) {
            case 0:
                right(y,x);
                break;
            case 1:
                down(y,x);
                break;
            case 2:
                right(y,x);
                down(y,x);
                break;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> house[i][j];
        }
    }
    q.push({0, {0, 1}});
    bfs();
    cout << ans;
    return 0;
}