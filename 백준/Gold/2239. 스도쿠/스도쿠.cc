#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <map>
#include <numeric>
#include <cmath>


using namespace std;

int grid[10][10];
vector<pair<int, int>> zero;
int top;
bool isfinished;

bool check(int y, int x, int n) {
    for (int i = 0; i < 9; i++) {
        if (grid[y][i] == n || grid[i][x] == n) {
            return false;
        }
    }
    int ny = y / 3 * 3;
    int nx = x / 3 * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[ny + i][nx + j] == n) {
                return false;
            }
        }
    }
    return true;
}

void sudoku() {
    if (top == zero.size()) {
        isfinished = true;
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (check(zero[top].first, zero[top].second, i)) {
            grid[zero[top].first][zero[top].second] = i;
            top++;
            sudoku();
            if (isfinished) {
                return;
            }
            top--;
            grid[zero[top].first][zero[top].second] = 0;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 9; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            grid[i][j] = s[j] - '0';
            if (grid[i][j] == 0) {
                zero.push_back({i, j});
            }
        }
    }
    sudoku();
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}