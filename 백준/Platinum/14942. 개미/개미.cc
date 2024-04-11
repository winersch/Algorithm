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
#define mod 10007
#define ll long long
using namespace std;

int n;
int energy[100001];
int dist[100001];
bool visited[100001];
vector<pair<int,int>> room[100001];
pair<int,int> parent[100001][17];

void dfs(int curr){
    visited[curr] = true;
    for(auto next : room[curr]){
        if (visited[next.first]){
            continue;
        }
        parent[next.first][0].first = curr;
        parent[next.first][0].second = next.second;
        dfs(next.first);
    }
}

pair<int,int> go(int curr, int cost){
    for (int i = 16; i >= 0; i--) {
        if (cost >= parent[i][curr].second){
            return {parent[i][curr].first, cost - parent[i][curr].second};
        }
    }
    return {curr, cost};
}

int find(int curr, int cost){
    while(true){
        pair<int,int> p = go(curr,cost);
        if (p.first == 1 || curr == p.first){
            return p.first;
        }
        curr = p.first;
        cost = p.second;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> energy[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        room[a].push_back({b,c});
        room[b].push_back({a,c});
    }
    dfs(1);
    parent[0][1] = {1,0};
    for (int i = 1; i <= 16; i++) {
        for (int j = 1; j <= n; j++) {
            parent[j][i] = {parent[parent[j][i-1].first][i-1].first, parent[j][i-1].second + parent[parent[j][i-1].first][i-1].second};
        }
    }
    for (int i = 1; i <= n; i++) {
        int x = i;
        for (int j = 16; j >= 0; j--) {
            if (parent[x][j].second > energy[i]){
                continue;
            }
            energy[i] -= parent[x][j].second;
            x = parent[x][j].first;
        }
        if (x == 0){
            x = 1;
        }
        cout << x << "\n";
    }

    return 0;
}