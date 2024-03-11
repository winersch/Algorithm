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
#define ll long long
using namespace std;

int bulb[11][11];
int tmp[11][11];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int ans = inf, cnt;

void turnOn(int y, int x){
    tmp[y][x] = !tmp[y][x];

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < 10 && nx >= 0 && nx < 10){
            tmp[ny][nx] = !tmp[ny][nx];
        }
    }
}

bool isSolved(){
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (tmp[i-1][j]){
                turnOn(i,j);
                cnt++;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        if (tmp[9][i]){
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 10; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++) {
            if (s[j] == '#') {
                bulb[i][j] = 0;
            } else {
                bulb[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                tmp[j][k] = bulb[j][k];
            }
        }
        cnt = 0;
        for (int j = 0; j < 10; j++) {
            if (i & (1<<j)){
                cnt++;
                turnOn(0,j);
            }
        }

        if (isSolved()){
            ans = min(ans, cnt);
        }
    }
    if (ans == inf){
        ans = -1;
    }
    cout << ans;

    return 0;
}