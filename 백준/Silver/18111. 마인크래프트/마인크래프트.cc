#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int grid[501][501];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, b;
    int least_sec = 2147483647;
    int result_height;

    cin >> n >> m >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i <= 256; i++) {
        int sec = 0;
        int dig = 0;
        int fillb = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (grid[j][k] > i) {
                    dig += grid[j][k] - i;
                } else if (grid[j][k] < i) {
                    fillb += abs(grid[j][k] - i);
                }
            }
        }
        sec = dig * 2 + fillb;
        if (dig + b >= fillb)
            if (sec <= least_sec) {
                least_sec = sec;
                result_height = i;
            }
    }

    cout << least_sec << " " << result_height;


    return 0;
}