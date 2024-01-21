#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

int n, m;
string input[1001];
pair<int,int> parent[1001][1001];

pair<int,int> findParent(int y, int x){
    if (parent[y][x].first == y && parent[y][x].second == x){
        return {y,x};
    }else{
        return parent[y][x] = findParent(parent[y][x].first, parent[y][x].second);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            parent[i][j] = {i,j};
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c = input[i][j];
            switch (c) {
                case 'U':
                    parent[i][j] = findParent(i-1,j);
                    break;
                case 'D':
                    parent[i][j] = findParent(i+1,j);
                    break;
                case 'L':
                    parent[i][j] = findParent(i,j-1);
                    break;
                case 'R':
                    parent[i][j] = findParent(i,j+1);
                    break;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (parent[i][j].first == i && parent[i][j].second == j){
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}