#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

int grid[129][129];
int n;
int white, blue;

void cut(int y, int x, int size) {
    int color = grid[y][x];
    int dif = 1;
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (color != grid[i][j]) {
                dif = 0;
                break;
            }
        }
    }
    if (dif) {
        if (color == 1) {
            blue++;
        } else {
            white++;
        }
    } else {
        cut(y, x, size / 2);
        cut(y + size / 2, x, size / 2);
        cut(y, x + size / 2, size / 2);
        cut(y + size / 2, x + size / 2, size / 2);
    }

}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    cut(0,0,n);
    cout << white << "\n" << blue;
    return 0;
}