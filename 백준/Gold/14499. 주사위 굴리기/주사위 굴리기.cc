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

int n, m, x, y, k;
int grid[21][21];
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};
int dice_num[7];

void move(int direction){
    int temp[7];
    for (int i = 1; i <= 6; i++) {
        temp[i] = dice_num[i];
    }

    if (direction == 1) {
        dice_num[1] = temp[4];
        dice_num[3] = temp[1];
        dice_num[6] = temp[3];
        dice_num[4] = temp[6];
    } else if (direction == 2) {
        dice_num[1] = temp[3];
        dice_num[4] = temp[1];
        dice_num[6] = temp[4];
        dice_num[3] = temp[6];
    } else if (direction == 3) {
        dice_num[1] = temp[5];
        dice_num[5] = temp[6];
        dice_num[6] = temp[2];
        dice_num[2] = temp[1];
    } else if (direction == 4) {
        dice_num[1] = temp[2];
        dice_num[2] = temp[6];
        dice_num[6] = temp[5];
        dice_num[5] = temp[1];
    }

    if (grid[y][x] == 0) {
        grid[y][x] = dice_num[6];
    } else {
        dice_num[6] = grid[y][x];
        grid[y][x] = 0;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> y >> x >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        int ny = y + dy[a-1];
        int nx = x + dx[a-1];
        if (ny >= 0 && ny < n && nx >= 0 && nx < m){
            y = ny;
            x = nx;
            move(a);
            cout << dice_num[1] << "\n";
        }
    }


    return 0;
}