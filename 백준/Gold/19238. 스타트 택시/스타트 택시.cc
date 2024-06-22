#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;


struct passenger{
    pii start;
    pii end;
};

int n, m, fuel;
int wall[21][21];   // -1 = wall, 0 = road, passenger = 1~
bool visited[21][21];
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};
vector<passenger> v;
pii taxi;

pair<pii, int> searchPassenger(){
    queue<pair<pii, int>> q;
    q.push({taxi, 0});
    passenger curPassenger;
    memset(visited, false, sizeof(visited));
    vector<pair<pii,int>> candidates;
    int minFuel = inf;
    visited[taxi.first][taxi.second] = true;
    if (wall[taxi.first][taxi.second] > 0){
        candidates.push_back({taxi, 0});
        q.pop();
    }
    while(!q.empty()){
        pii curr = q.front().first;
        int cfuel = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = curr.first + dy[i];
            int nx = curr.second + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < n && wall[ny][nx] != -1 && !visited[ny][nx]){
                visited[ny][nx] = true;
                if (wall[ny][nx] > 0 && cfuel+1 <= minFuel){
                    candidates.push_back({{ny,nx},cfuel+1});
                    minFuel = cfuel+1;
                }
                q.push({{ny,nx}, cfuel+1});
            }
        }

    }
    if (candidates.empty()){
        return {{-1,-1}, -1};
    }
    sort(candidates.begin(), candidates.end());
    curPassenger = v[wall[candidates[0].first.first][candidates[0].first.second]-1];
    fuel -= candidates[0].second;
    wall[candidates[0].first.first][candidates[0].first.second] = 0;
    q.push({{curPassenger.start}, 0});
    memset(visited, false, sizeof(visited));
    visited[curPassenger.start.first][curPassenger.start.second] = true;
    while (!q.empty()){
        pii curr = q.front().first;
        int cfuel = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = curr.first + dy[i];
            int nx = curr.second + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < n && wall[ny][nx] != -1 && !visited[ny][nx]){
                visited[ny][nx] = true;
                if (curPassenger.end == make_pair(ny,nx)){
                    return {curPassenger.end, cfuel+1};
                }
                q.push({{ny,nx}, cfuel+1});
            }
        }
    }
    return {{-1,-1}, -1};
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> fuel;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if (a == 1){
                wall[i][j] = -1;
            }
        }
    }
    cin >> taxi.first >> taxi.second;
    taxi.first--;
    taxi.second--;
    for (int i = 1; i <= m; i++) {
        passenger ps;
        cin >> ps.start.first >> ps.start.second >> ps.end.first >> ps.end.second;
        ps.start.first--;
        ps.start.second--;
        ps.end.first--;
        ps.end.second--;
        v.push_back(ps);
        wall[ps.start.first][ps.start.second] = i;
    }

    for (int i = 0; i < m; i++) {
        pair<pii, int> find = searchPassenger();
        if (find.second == -1 || fuel - find.second < 0){
            cout << -1;
            return 0;
        }
        fuel += find.second;
        taxi = find.first;
    }

    cout << fuel;

    return 0;
}