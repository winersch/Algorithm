#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>


using namespace std;

int n, m;
int grid[1025][1025];
int dp[1025][1025];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;


    cin >> grid[0][0];

    for (int i = 0; i < n; i++) {
        if (i != 0) {
            cin >> grid[i][0];
            grid[i][0] += grid[i - 1][n - 1];
        }
        for (int j = 1; j < n; j++) {
            cin >> grid[i][j];
            grid[i][j] += grid[i][j - 1];
        }
    }

    vector<int> v[m];
    for (int i = 0; i < m; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v[i].push_back(x1 - 1);
        v[i].push_back(y1 - 1);
        v[i].push_back(x2 - 1);
        v[i].push_back(y2 - 1);
    }


    for (int i = 0; i < m; i++) {
        int x1, x2, y1, y2;
        x1 = v[i][0];
        y1 = v[i][1];
        x2 = v[i][2];
        y2 = v[i][3];
        int sum = 0;

        if (y1 == 0) {
            if (x1 == 0) {
                sum += grid[x1][y2];
                for (int j = x1 + 1; j <= x2; j++) {
                    sum += grid[j][y2] - grid[j - 1][n-1];
                }
            } else {
                for (int j = x1; j <= x2; j++) {
                    sum += grid[j][y2] - grid[j - 1][n-1];
                }
            }
        } else {
            for (int j = x1; j <= x2; j++) {
                sum += grid[j][y2] - grid[j][y1 - 1];
            }
        }
        cout << sum << "\n";

    }

    return 0;
}