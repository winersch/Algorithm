#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
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

int n, m, islandIdx = 1, ans;
int arr[11][11];
int island[11][11];
bool visited[11][11];
int parent[11];
vector<pair<int,pii>> edge;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int findParent(int a){
    if (parent[a] == a){
        return a;
    }
    return parent[a] = findParent(parent[a]);
}

void findIsland() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                queue<pii > q;
                q.push({i, j});
                arr[i][j] = 0;
                island[i][j] = islandIdx;
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] == 1) {
                            island[ny][nx] = islandIdx;
                            arr[ny][nx] = 0;
                            q.push({ny, nx});
                        }
                    }
                }
                islandIdx++;
            }
        }
    }
}

void findRoute(int a, int b) {
    memset(visited, false, sizeof(visited));
    queue<pii > q;
    int dist = inf;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (island[i][j] == a) {
                q.push({i, j});
            }
        }
    }

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 1; i < n; i++) {
            int ny = y + i;
            if (ny >= n){
                break;
            }

            if (island[ny][x] == b && i > 2){
                dist = min(dist, i);
                break;
            }
            if (island[ny][x] > 0){
                break;
            }
        }
        for (int i = 1; i < n; i++) {
            int ny = y - i;
            if (ny < 0){
                break;
            }
            if (island[ny][x] == b && i > 2){
                dist = min(dist, i);
                break;
            }
            if (island[ny][x] > 0){
                break;
            }
        }
        for (int i = 1; i < m; i++) {
            int nx = x + i;
            if (nx >= m){
                break;
            }
            if (island[y][nx] == b && i > 2){
                dist = min(dist, i);
                break;
            }
            if (island[y][nx] > 0){
                break;
            }
        }
        for (int i = 1; i < m; i++) {
            int nx = x - i;
            if (nx < 0){
                break;
            }
            if (island[y][nx] == b && i > 2){
                dist = min(dist, i);
                break;
            }
            if (island[y][nx] > 0){
                break;
            }
        }
    }
    if (dist != inf){
        edge.push_back({dist-1,{a,b}});
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    findIsland();

    for (int i = 1; i < islandIdx; i++) {
        for (int j = i+1; j < islandIdx; j++) {
            findRoute(i,j);
        }
    }

    for (int i = 0; i <= islandIdx; i++) {
        parent[i] = i;
    }
    sort(edge.begin(), edge.end());

    for (int i = 0; i < edge.size(); i++) {
        int cost = edge[i].first;
        int start = edge[i].second.first;
        int end = edge[i].second.second;
        if (cost < 2){
            continue;
        }
        if (start > end){
            swap(start, end);
        }
        if (findParent(start) != findParent(end)){
            ans += cost;
            parent[findParent(end)] = findParent(start);
        }

    }
    int t = findParent(1);
    for (int i = 2; i < islandIdx; i++) {
        if (findParent(i) != t){
            ans = -1;
        }
    }

    cout << ans;


    return 0;
}